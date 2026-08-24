package org.roseled.controllerpro;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.SeekBar;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

public final class ParametresActivity extends Activity {

    private View boutonRetourParametres;

    private TextView texteNomBluetooth;
    private TextView texteVersionFirmware;
    private TextView texteVersionApplication;
    private TextView texteLuminositeDemarrage;

    private SeekBar curseurLuminositeDemarrage;

    private Switch interrupteurConnexionAuto;
    private Switch interrupteurReconnexionAuto;

    @Override
    protected void onCreate(Bundle etatSauvegarde) {
        super.onCreate(etatSauvegarde);

        setContentView(R.layout.activity_parametres);

        recupererVues();
        afficherInformations();
        configurerActions();
    }

    private void recupererVues() {

        boutonRetourParametres =
                findViewById(R.id.boutonRetourParametres);

        texteNomBluetooth =
                findViewById(R.id.texteNomBluetooth);

        texteVersionFirmware =
                findViewById(R.id.texteVersionFirmware);

        texteVersionApplication =
                findViewById(R.id.texteVersionApplication);

        texteLuminositeDemarrage =
                findViewById(R.id.texteLuminositeDemarrage);

        curseurLuminositeDemarrage =
                findViewById(R.id.curseurLuminositeDemarrage);

        interrupteurConnexionAuto =
                findViewById(R.id.interrupteurConnexionAuto);

        interrupteurReconnexionAuto =
                findViewById(R.id.interrupteurReconnexionAuto);
    }

    private void afficherInformations() {

        texteNomBluetooth.setText(
                "RoseLed Controller Pro"
        );

        /*
         * La version firmware sera récupérée
         * depuis le contrôleur lorsque nous
         * testerons réellement le Bluetooth.
         */
        texteVersionFirmware.setText(
                "Non disponible"
        );

        /*
         * Version actuelle de l'application.
         * Valeur fixe pour éviter le problème
         * BuildConfig rencontré à la compilation.
         */
        texteVersionApplication.setText(
                "1.0"
        );

        texteLuminositeDemarrage.setText(
                "50 %"
        );
    }

    private void configurerActions() {

        boutonRetourParametres.setOnClickListener(
                vue -> finish()
        );

        curseurLuminositeDemarrage.setOnSeekBarChangeListener(
                new SeekBar.OnSeekBarChangeListener() {

                    @Override
                    public void onProgressChanged(
                            SeekBar seekBar,
                            int valeur,
                            boolean utilisateur
                    ) {

                        texteLuminositeDemarrage.setText(
                                valeur + " %"
                        );
                    }

                    @Override
                    public void onStartTrackingTouch(
                            SeekBar seekBar
                    ) {
                        // Aucun traitement nécessaire.
                    }

                    @Override
                    public void onStopTrackingTouch(
                            SeekBar seekBar
                    ) {

                        afficherMessage(
                                "Luminosité par défaut : "
                                        + seekBar.getProgress()
                                        + " %"
                        );
                    }
                }
        );

        interrupteurConnexionAuto.setOnCheckedChangeListener(
                (bouton, active) -> {

                    if (active) {
                        afficherMessage(
                                "Connexion automatique activée"
                        );
                    } else {
                        afficherMessage(
                                "Connexion automatique désactivée"
                        );
                    }
                }
        );

        interrupteurReconnexionAuto.setOnCheckedChangeListener(
                (bouton, active) -> {

                    if (active) {
                        afficherMessage(
                                "Reconnexion automatique activée"
                        );
                    } else {
                        afficherMessage(
                                "Reconnexion automatique désactivée"
                        );
                    }
                }
        );
    }

    private void afficherMessage(String message) {

        Toast.makeText(
                this,
                message,
                Toast.LENGTH_SHORT
        ).show();
    }
}