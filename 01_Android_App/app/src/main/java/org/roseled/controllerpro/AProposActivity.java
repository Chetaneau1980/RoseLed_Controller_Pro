package org.roseled.controllerpro;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public final class AProposActivity extends Activity {

    private View boutonRetourAPropos;

    private TextView texteVersionApplication;
    private TextView texteBluetooth;
    private TextView texteControleur;

    @Override
    protected void onCreate(Bundle etatSauvegarde) {
        super.onCreate(etatSauvegarde);

        setContentView(R.layout.activity_a_propos);

        recupererVues();
        afficherInformations();
        configurerActions();
    }

    private void recupererVues() {

        boutonRetourAPropos =
                findViewById(R.id.boutonRetourAPropos);

        texteVersionApplication =
                findViewById(R.id.texteVersionApplicationAPropos);

        texteBluetooth =
                findViewById(R.id.texteBluetoothAPropos);

        texteControleur =
                findViewById(R.id.texteControleurAPropos);
    }

    private void afficherInformations() {

        texteVersionApplication.setText(
                "Version 1.0"
        );

        texteBluetooth.setText(
                "Bluetooth Classic SPP"
        );

        texteControleur.setText(
                "ESP32 • RoseLed Controller Pro"
        );
    }

    private void configurerActions() {

        boutonRetourAPropos.setOnClickListener(
                vue -> finish()
        );
    }
}