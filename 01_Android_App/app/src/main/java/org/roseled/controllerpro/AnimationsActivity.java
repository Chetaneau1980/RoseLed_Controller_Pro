package org.roseled.controllerpro;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public final class AnimationsActivity extends Activity {

    private View boutonRetourAnimations;

    private View animationArcEnCiel;
    private View animationRespiration;
    private View animationFeu;
    private View animationOcean;
    private View animationFlash;
    private View animationFixe;
    private View animationOctobreRose;

    @Override
    protected void onCreate(Bundle etatSauvegarde) {
        super.onCreate(etatSauvegarde);

        setContentView(R.layout.activity_animations);

        recupererVues();
        configurerActions();
    }

    private void recupererVues() {

        boutonRetourAnimations =
                findViewById(R.id.boutonRetourAnimations);

        animationArcEnCiel =
                findViewById(R.id.animationArcEnCiel);

        animationRespiration =
                findViewById(R.id.animationRespiration);

        animationFeu =
                findViewById(R.id.animationFeu);

        animationOcean =
                findViewById(R.id.animationOcean);

        animationFlash =
                findViewById(R.id.animationFlash);

        animationFixe =
                findViewById(R.id.animationFixe);

        animationOctobreRose =
                findViewById(R.id.animationOctobreRose);
    }

    private void configurerActions() {

        boutonRetourAnimations.setOnClickListener(
                vue -> finish()
        );

        animationArcEnCiel.setOnClickListener(
                vue -> afficherAnimation("Arc-en-ciel")
        );

        animationRespiration.setOnClickListener(
                vue -> afficherAnimation("Respiration")
        );

        animationFeu.setOnClickListener(
                vue -> afficherAnimation("Feu")
        );

        animationOcean.setOnClickListener(
                vue -> afficherAnimation("Océan")
        );

        animationFlash.setOnClickListener(
                vue -> afficherAnimation("Flash")
        );

        animationFixe.setOnClickListener(
                vue -> afficherAnimation("Fixe")
        );

        animationOctobreRose.setOnClickListener(
                vue -> afficherAnimation("Octobre Rose")
        );
    }

    private void afficherAnimation(String nomAnimation) {

        Toast.makeText(
                this,
                nomAnimation,
                Toast.LENGTH_SHORT
        ).show();
    }
}