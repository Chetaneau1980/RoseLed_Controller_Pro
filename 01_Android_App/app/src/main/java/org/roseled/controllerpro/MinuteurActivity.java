package org.roseled.controllerpro;

import android.app.Activity;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Locale;

public final class MinuteurActivity extends Activity {

    private static final long MINUTE_MS = 60_000L;

    private View boutonRetourMinuteur;

    private View duree15Minutes;
    private View duree30Minutes;
    private View duree1Heure;
    private View duree2Heures;

    private TextView texteTempsRestant;
    private TextView texteDureeSelectionnee;

    private Button boutonDemarrerMinuteur;
    private Button boutonAnnulerMinuteur;

    private CountDownTimer compteARebours;

    private long dureeSelectionneeMs = 30 * MINUTE_MS;
    private boolean minuteurActif = false;

    @Override
    protected void onCreate(Bundle etatSauvegarde) {
        super.onCreate(etatSauvegarde);

        setContentView(R.layout.activity_minuteur);

        recupererVues();
        configurerActions();

        afficherDureeSelectionnee(30);
        afficherTemps(dureeSelectionneeMs);
        afficherEtatPret();
    }

    private void recupererVues() {

        boutonRetourMinuteur =
                findViewById(R.id.boutonRetourMinuteur);

        duree15Minutes =
                findViewById(R.id.duree15Minutes);

        duree30Minutes =
                findViewById(R.id.duree30Minutes);

        duree1Heure =
                findViewById(R.id.duree1Heure);

        duree2Heures =
                findViewById(R.id.duree2Heures);

        texteTempsRestant =
                findViewById(R.id.texteTempsRestant);

        texteDureeSelectionnee =
                findViewById(R.id.texteDureeSelectionnee);

        boutonDemarrerMinuteur =
                findViewById(R.id.boutonDemarrerMinuteur);

        boutonAnnulerMinuteur =
                findViewById(R.id.boutonAnnulerMinuteur);
    }

    private void configurerActions() {

        boutonRetourMinuteur.setOnClickListener(
                vue -> finish()
        );

        duree15Minutes.setOnClickListener(
                vue -> selectionnerDuree(15)
        );

        duree30Minutes.setOnClickListener(
                vue -> selectionnerDuree(30)
        );

        duree1Heure.setOnClickListener(
                vue -> selectionnerDuree(60)
        );

        duree2Heures.setOnClickListener(
                vue -> selectionnerDuree(120)
        );

        boutonDemarrerMinuteur.setOnClickListener(
                vue -> demarrerMinuteur()
        );

        boutonAnnulerMinuteur.setOnClickListener(
                vue -> annulerMinuteur()
        );
    }

    private void selectionnerDuree(int minutes) {

        if (minuteurActif) {
            return;
        }

        dureeSelectionneeMs =
                minutes * MINUTE_MS;

        afficherDureeSelectionnee(minutes);
        afficherTemps(dureeSelectionneeMs);
    }

    private void afficherDureeSelectionnee(int minutes) {

        String texte;

        if (minutes < 60) {
            texte = minutes + " minutes";
        } else {
            int heures = minutes / 60;

            texte = heures == 1
                    ? "1 heure"
                    : heures + " heures";
        }

        texteDureeSelectionnee.setText(
                "Durée sélectionnée : " + texte
        );
    }

    private void demarrerMinuteur() {

        if (minuteurActif) {
            return;
        }

        minuteurActif = true;

        activerChoixDuree(false);

        boutonDemarrerMinuteur.setEnabled(false);
        boutonAnnulerMinuteur.setEnabled(true);

        compteARebours =
                new CountDownTimer(
                        dureeSelectionneeMs,
                        1000
                ) {

                    @Override
                    public void onTick(
                            long millisecondesRestantes
                    ) {
                        afficherTemps(
                                millisecondesRestantes
                        );
                    }

                    @Override
                    public void onFinish() {

                        minuteurActif = false;

                        afficherTemps(0);
                        activerChoixDuree(true);

                        boutonDemarrerMinuteur.setEnabled(true);
                        boutonAnnulerMinuteur.setEnabled(false);

                        Toast.makeText(
                                MinuteurActivity.this,
                                "Minuteur terminé",
                                Toast.LENGTH_LONG
                        ).show();

                        /*
                         * Plus tard, lorsque nous relierons
                         * cet écran au contrôleur Bluetooth,
                         * l'ordre OFF sera envoyé ici.
                         */
                    }
                };

        compteARebours.start();
    }

    private void annulerMinuteur() {

        if (compteARebours != null) {
            compteARebours.cancel();
            compteARebours = null;
        }

        minuteurActif = false;

        activerChoixDuree(true);

        boutonDemarrerMinuteur.setEnabled(true);
        boutonAnnulerMinuteur.setEnabled(false);

        afficherTemps(dureeSelectionneeMs);
    }

    private void activerChoixDuree(boolean activer) {

        duree15Minutes.setEnabled(activer);
        duree30Minutes.setEnabled(activer);
        duree1Heure.setEnabled(activer);
        duree2Heures.setEnabled(activer);

        float opacite = activer ? 1.0f : 0.45f;

        duree15Minutes.setAlpha(opacite);
        duree30Minutes.setAlpha(opacite);
        duree1Heure.setAlpha(opacite);
        duree2Heures.setAlpha(opacite);
    }

    private void afficherTemps(long millisecondes) {

        long totalSecondes =
                millisecondes / 1000;

        long heures =
                totalSecondes / 3600;

        long minutes =
                (totalSecondes % 3600) / 60;

        long secondes =
                totalSecondes % 60;

        String temps = String.format(
                Locale.ROOT,
                "%02d:%02d:%02d",
                heures,
                minutes,
                secondes
        );

        texteTempsRestant.setText(temps);
    }

    private void afficherEtatPret() {

        boutonDemarrerMinuteur.setEnabled(true);
        boutonAnnulerMinuteur.setEnabled(false);
    }

    @Override
    protected void onDestroy() {

        if (compteARebours != null) {
            compteARebours.cancel();
        }

        super.onDestroy();
    }
}