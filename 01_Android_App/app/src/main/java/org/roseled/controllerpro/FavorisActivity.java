package org.roseled.controllerpro;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public final class FavorisActivity extends Activity {

    private View boutonRetour;

    private View favoriArcEnCiel;
    private View favoriRespiration;
    private View favoriFeu;
    private View favoriOcean;
    private View favoriFlash;
    private View favoriFixe;

    @Override
    protected void onCreate(Bundle etatSauvegarde) {
        super.onCreate(etatSauvegarde);

        setContentView(R.layout.activity_favoris);

        recupererVues();
        configurerActions();
    }

    private void recupererVues() {
        boutonRetour = findViewById(R.id.boutonRetourFavoris);

        favoriArcEnCiel = findViewById(R.id.favoriArcEnCiel);
        favoriRespiration = findViewById(R.id.favoriRespiration);
        favoriFeu = findViewById(R.id.favoriFeu);
        favoriOcean = findViewById(R.id.favoriOcean);
        favoriFlash = findViewById(R.id.favoriFlash);
        favoriFixe = findViewById(R.id.favoriFixe);
    }

    private void configurerActions() {

        boutonRetour.setOnClickListener(
                vue -> finish()
        );

        favoriArcEnCiel.setOnClickListener(
                vue -> afficherFavori("Arc-en-ciel")
        );

        favoriRespiration.setOnClickListener(
                vue -> afficherFavori("Respiration")
        );

        favoriFeu.setOnClickListener(
                vue -> afficherFavori("Feu")
        );

        favoriOcean.setOnClickListener(
                vue -> afficherFavori("Océan")
        );

        favoriFlash.setOnClickListener(
                vue -> afficherFavori("Flash")
        );

        favoriFixe.setOnClickListener(
                vue -> afficherFavori("Fixe")
        );
    }

    private void afficherFavori(String nomFavori) {
        Toast.makeText(
                this,
                nomFavori,
                Toast.LENGTH_SHORT
        ).show();
    }
}