package org.roseled.controllerpro;

import android.animation.AnimatorSet;
import android.animation.ObjectAnimator;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.view.View;
import android.view.animation.AccelerateDecelerateInterpolator;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;

public class SplashActivity extends Activity {

    private static final long SPLASH_DURATION_MS = 5000L;

    private ImageView logoRoseLed;
    private TextView titleRoseLed;
    private TextView subtitleRoseLed;

    private TextView statusBluetooth;
    private TextView statusFirmware;
    private TextView statusInterface;
    private TextView statusReady;

    private ProgressBar progressSplash;

    private final Handler handler = new Handler(Looper.getMainLooper());

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_splash);

        initialiserVues();
        preparerVues();
        lancerAnimationLogo();
        lancerSequenceInitialisation();
        programmerOuvertureMainActivity();
    }

    private void initialiserVues() {
        logoRoseLed = findViewById(R.id.logoRoseLed);
        titleRoseLed = findViewById(R.id.titleRoseLed);
        subtitleRoseLed = findViewById(R.id.subtitleRoseLed);

        statusBluetooth = findViewById(R.id.statusBluetooth);
        statusFirmware = findViewById(R.id.statusFirmware);
        statusInterface = findViewById(R.id.statusInterface);
        statusReady = findViewById(R.id.statusReady);

        progressSplash = findViewById(R.id.progressSplash);
    }

    private void preparerVues() {
        logoRoseLed.setAlpha(0f);
        logoRoseLed.setScaleX(0.88f);
        logoRoseLed.setScaleY(0.88f);

        titleRoseLed.setAlpha(0f);
        subtitleRoseLed.setAlpha(0f);

        statusBluetooth.setAlpha(0f);
        statusFirmware.setAlpha(0f);
        statusInterface.setAlpha(0f);
        statusReady.setAlpha(0f);

        progressSplash.setProgress(0);
    }

    private void lancerAnimationLogo() {
        ObjectAnimator fadeLogo =
                ObjectAnimator.ofFloat(logoRoseLed, View.ALPHA, 0f, 1f);

        ObjectAnimator scaleX =
                ObjectAnimator.ofFloat(logoRoseLed, View.SCALE_X, 0.88f, 1f);

        ObjectAnimator scaleY =
                ObjectAnimator.ofFloat(logoRoseLed, View.SCALE_Y, 0.88f, 1f);

        AnimatorSet animationLogo = new AnimatorSet();
        animationLogo.playTogether(fadeLogo, scaleX, scaleY);
        animationLogo.setDuration(1100);
        animationLogo.setInterpolator(
                new AccelerateDecelerateInterpolator()
        );
        animationLogo.start();

        handler.postDelayed(
                () -> animerApparition(titleRoseLed, 650),
                650
        );

        handler.postDelayed(
                () -> animerApparition(subtitleRoseLed, 650),
                950
        );
    }

    private void lancerSequenceInitialisation() {

        handler.postDelayed(() -> {
            animerApparition(statusBluetooth, 350);
            progressSplash.setProgress(25);
        }, 1400);

        handler.postDelayed(() -> {
            animerApparition(statusFirmware, 350);
            progressSplash.setProgress(50);
        }, 2200);

        handler.postDelayed(() -> {
            animerApparition(statusInterface, 350);
            progressSplash.setProgress(75);
        }, 3000);

        handler.postDelayed(() -> {
            animerApparition(statusReady, 350);
            progressSplash.setProgress(100);
        }, 3900);
    }

    private void animerApparition(View vue, long duree) {
        vue.animate()
                .alpha(1f)
                .setDuration(duree)
                .setInterpolator(
                        new AccelerateDecelerateInterpolator()
                )
                .start();
    }

    private void programmerOuvertureMainActivity() {
        handler.postDelayed(
                this::ouvrirMainActivity,
                SPLASH_DURATION_MS
        );
    }

    private void ouvrirMainActivity() {
        Intent intent =
                new Intent(SplashActivity.this, MainActivity.class);

        startActivity(intent);

        overridePendingTransition(
                android.R.anim.fade_in,
                android.R.anim.fade_out
        );

        finish();
    }

    @Override
    protected void onDestroy() {
        handler.removeCallbacksAndMessages(null);
        super.onDestroy();
    }
}