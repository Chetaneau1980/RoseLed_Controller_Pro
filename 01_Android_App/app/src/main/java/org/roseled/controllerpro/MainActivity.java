package org.roseled.controllerpro;

import android.Manifest;
import android.app.Activity;
import android.app.AlertDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothManager;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Color;
import android.graphics.drawable.GradientDrawable;
import android.os.Build;
import android.os.Bundle;
import android.provider.Settings;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Locale;
import java.util.Set;

public final class MainActivity extends Activity
        implements BluetoothController.EcouteurConnexion {

    private static final int DEMANDE_AUTORISATION_BLUETOOTH = 100;
    private static final String NOM_CONTROLEUR = "RoseLed Controller Pro";

    private static final String[] NOMS_COULEURS = {
            "Rouge",
            "Orange",
            "Jaune",
            "Vert",
            "Cyan",
            "Bleu",
            "Violet",
            "Blanc"
    };

    private static final int[] VALEURS_COULEURS = {
            Color.RED,
            0xFFFF8000,
            Color.YELLOW,
            Color.GREEN,
            Color.CYAN,
            Color.BLUE,
            0xFF8000FF,
            Color.WHITE
    };

    private BluetoothAdapter adaptateurBluetooth;
    private BluetoothController controleurBluetooth;

    private TextView texteEtatBluetooth;
    private TextView texteLuminosite;

    private Button boutonConnecter;
    private Button boutonDeconnecter;
    private Button boutonChoisirCouleur;
    private Button boutonEteindre;
    private Button boutonOctobreRose;

    private View apercuCouleur;
    private SeekBar curseurLuminosite;

    private View carteArcEnCiel;
    private View carteRespiration;
    private View carteFeu;
    private View carteOcean;
    private View carteFlash;
    private View carteFixe;

    private View boutonMenu;
    private View menuLateral;
    private View voileMenu;

    private View menuAccueil;
    private View menuFavoris;
    private View menuAnimations;
    private View menuMinuteur;
    private View menuParametres;
    private View menuAPropos;
    private View menuDeconnecter;

    private boolean menuOuvert = false;

    @Override
    protected void onCreate(Bundle etatSauvegarde) {
        super.onCreate(etatSauvegarde);

        setContentView(R.layout.activity_main);

        initialiserBluetooth();
        recupererVues();
        configurerActions();
        afficherEtatDeconnecte();
    }

    private void initialiserBluetooth() {

        BluetoothManager gestionnaireBluetooth =
                getSystemService(BluetoothManager.class);

        adaptateurBluetooth = gestionnaireBluetooth != null
                ? gestionnaireBluetooth.getAdapter()
                : null;

        controleurBluetooth =
                new BluetoothController(this);
    }

    private void recupererVues() {

        texteEtatBluetooth =
                findViewById(R.id.texteEtatBluetooth);

        texteLuminosite =
                findViewById(R.id.texteLuminosite);

        boutonConnecter =
                findViewById(R.id.boutonConnecter);

        boutonDeconnecter =
                findViewById(R.id.boutonDeconnecter);

        boutonChoisirCouleur =
                findViewById(R.id.boutonChoisirCouleur);

        boutonEteindre =
                findViewById(R.id.boutonEteindre);

        boutonOctobreRose =
                findViewById(R.id.boutonOctobreRose);

        apercuCouleur =
                findViewById(R.id.apercuCouleur);

        curseurLuminosite =
                findViewById(R.id.curseurLuminosite);

        carteArcEnCiel =
                findViewById(R.id.carteArcEnCiel);

        carteRespiration =
                findViewById(R.id.carteRespiration);

        carteFeu =
                findViewById(R.id.carteFeu);

        carteOcean =
                findViewById(R.id.carteOcean);

        carteFlash =
                findViewById(R.id.carteFlash);

        carteFixe =
                findViewById(R.id.carteFixe);

        boutonMenu =
                findViewById(R.id.boutonMenu);

        menuLateral =
                findViewById(R.id.menuLateral);

        voileMenu =
                findViewById(R.id.voileMenu);

        menuAccueil =
                findViewById(R.id.menuAccueil);

        menuFavoris =
                findViewById(R.id.menuFavoris);

        menuAnimations =
                findViewById(R.id.menuAnimations);

        menuMinuteur =
                findViewById(R.id.menuMinuteur);

        menuParametres =
                findViewById(R.id.menuParametres);

        menuAPropos =
                findViewById(R.id.menuAPropos);

        menuDeconnecter =
                findViewById(R.id.menuDeconnecter);
    }

    private void configurerActions() {

        boutonConnecter.setOnClickListener(
                vue -> demanderConnexion()
        );

        boutonDeconnecter.setOnClickListener(
                vue -> controleurBluetooth.deconnecter()
        );

        boutonChoisirCouleur.setOnClickListener(
                vue -> afficherChoixCouleur()
        );

        boutonEteindre.setOnClickListener(
                vue -> envoyerCommande("OFF")
        );

        boutonOctobreRose.setOnClickListener(
                vue -> envoyerAnimation("Octobre Rose")
        );

        carteArcEnCiel.setOnClickListener(
                vue -> envoyerAnimation("Arc-en-ciel")
        );

        carteRespiration.setOnClickListener(
                vue -> envoyerAnimation("Respiration")
        );

        carteFeu.setOnClickListener(
                vue -> envoyerAnimation("Feu")
        );

        carteOcean.setOnClickListener(
                vue -> envoyerAnimation("Océan")
        );

        carteFlash.setOnClickListener(
                vue -> envoyerAnimation("Flash")
        );

        carteFixe.setOnClickListener(
                vue -> envoyerAnimation("Fixe")
        );

        configurerCurseurLuminosite();
        configurerMenu();
    }

    // =========================================================
    // MENU LATÉRAL
    // =========================================================

    private void configurerMenu() {

        boutonMenu.setOnClickListener(
                vue -> ouvrirMenu()
        );

        voileMenu.setOnClickListener(
                vue -> fermerMenu()
        );

        menuAccueil.setOnClickListener(
                vue -> fermerMenu()
        );

        menuFavoris.setOnClickListener(vue -> {

            fermerMenu();

            Intent intentFavoris =
                    new Intent(
                            MainActivity.this,
                            FavorisActivity.class
                    );

            startActivity(intentFavoris);
        });

        menuAnimations.setOnClickListener(vue -> {

            fermerMenu();

            Intent intentAnimations =
                    new Intent(
                            MainActivity.this,
                            AnimationsActivity.class
                    );

            startActivity(intentAnimations);
        });

        menuMinuteur.setOnClickListener(vue -> {

            fermerMenu();

            Intent intentMinuteur =
                    new Intent(
                            MainActivity.this,
                            MinuteurActivity.class
                    );

            startActivity(intentMinuteur);
        });

        menuParametres.setOnClickListener(vue -> {

            fermerMenu();

            Intent intentParametres =
                    new Intent(
                            MainActivity.this,
                            ParametresActivity.class
                    );

            startActivity(intentParametres);
        });

        menuAPropos.setOnClickListener(vue -> {

            fermerMenu();

            Intent intentAPropos =
                    new Intent(
                            MainActivity.this,
                            AProposActivity.class
                    );

            startActivity(intentAPropos);
        });

        menuDeconnecter.setOnClickListener(vue -> {

            fermerMenu();

            if (controleurBluetooth.estConnecte()) {
                controleurBluetooth.deconnecter();
            }
        });
    }

    private void ouvrirMenu() {

        if (menuOuvert) {
            return;
        }

        menuOuvert = true;

        voileMenu.setAlpha(0f);
        voileMenu.setVisibility(View.VISIBLE);

        menuLateral.setVisibility(View.VISIBLE);

        menuLateral.setTranslationX(
                -menuLateral.getWidth()
        );

        voileMenu.animate()
                .alpha(1f)
                .setDuration(220)
                .start();

        menuLateral.animate()
                .translationX(0f)
                .setDuration(280)
                .start();
    }

    private void fermerMenu() {

        if (!menuOuvert) {
            return;
        }

        menuOuvert = false;

        voileMenu.animate()
                .alpha(0f)
                .setDuration(200)
                .withEndAction(() ->
                        voileMenu.setVisibility(
                                View.GONE
                        )
                )
                .start();

        menuLateral.animate()
                .translationX(
                        -menuLateral.getWidth()
                )
                .setDuration(250)
                .withEndAction(() ->
                        menuLateral.setVisibility(
                                View.GONE
                        )
                )
                .start();
    }

    // =========================================================
    // ANIMATIONS LED
    // =========================================================

    private void envoyerAnimation(
            String animation
    ) {

        envoyerCommande(
                "ANIMATION " + animation
        );
    }

    private void envoyerCommande(
            String commande
    ) {

        if (!controleurBluetooth.estConnecte()) {
            return;
        }

        controleurBluetooth.envoyerCommande(
                commande
        );
    }

    // =========================================================
    // LUMINOSITÉ
    // =========================================================

    private void configurerCurseurLuminosite() {

        curseurLuminosite.setOnSeekBarChangeListener(
                new SeekBar.OnSeekBarChangeListener() {

                    @Override
                    public void onProgressChanged(
                            SeekBar curseur,
                            int valeur,
                            boolean utilisateur
                    ) {

                        texteLuminosite.setText(
                                getString(
                                        R.string.brightness_value,
                                        valeur
                                )
                        );
                    }

                    @Override
                    public void onStartTrackingTouch(
                            SeekBar curseur
                    ) {
                        // Aucun traitement nécessaire.
                    }

                    @Override
                    public void onStopTrackingTouch(
                            SeekBar curseur
                    ) {

                        envoyerCommande(
                                "BRIGHTNESS "
                                        + curseur.getProgress()
                        );
                    }
                }
        );
    }

    // =========================================================
    // BLUETOOTH
    // =========================================================

    private void demanderConnexion() {

        if (adaptateurBluetooth == null) {

            afficherMessage(
                    R.string.bluetooth_unavailable
            );

            return;
        }

        if (Build.VERSION.SDK_INT
                >= Build.VERSION_CODES.S
                && checkSelfPermission(
                Manifest.permission.BLUETOOTH_CONNECT
        ) != PackageManager.PERMISSION_GRANTED) {

            requestPermissions(
                    new String[]{
                            Manifest.permission.BLUETOOTH_CONNECT
                    },
                    DEMANDE_AUTORISATION_BLUETOOTH
            );

            return;
        }

        continuerConnexion();
    }

    private void continuerConnexion() {

        if (!adaptateurBluetooth.isEnabled()) {

            afficherMessage(
                    R.string.bluetooth_disabled
            );

            startActivity(
                    new Intent(
                            Settings.ACTION_BLUETOOTH_SETTINGS
                    )
            );

            return;
        }

        afficherAppareilsAssocies();
    }

    @SuppressWarnings("MissingPermission")
    private void afficherAppareilsAssocies() {

        Set<BluetoothDevice> appareilsAssocies =
                adaptateurBluetooth.getBondedDevices();

        List<BluetoothDevice> controleursRoseLed =
                new ArrayList<>();

        for (BluetoothDevice appareil
                : appareilsAssocies) {

            if (NOM_CONTROLEUR.equals(
                    appareil.getName()
            )) {

                controleursRoseLed.add(
                        appareil
                );
            }
        }

        controleursRoseLed.sort(
                Comparator.comparing(
                        BluetoothDevice::getAddress
                )
        );

        if (controleursRoseLed.isEmpty()) {

            afficherMessage(
                    R.string.no_paired_device
            );

            return;
        }

        String[] libellesAppareils =
                creerLibellesAppareils(
                        controleursRoseLed
                );

        new AlertDialog.Builder(this)
                .setTitle(
                        R.string.choose_device
                )
                .setItems(
                        libellesAppareils,
                        (dialogue, position) ->
                                connecterAppareil(
                                        controleursRoseLed.get(
                                                position
                                        )
                                )
                )
                .setNegativeButton(
                        R.string.cancel,
                        null
                )
                .show();
    }

    @SuppressWarnings("MissingPermission")
    private String[] creerLibellesAppareils(
            List<BluetoothDevice> appareils
    ) {

        String[] libelles =
                new String[appareils.size()];

        for (
                int index = 0;
                index < appareils.size();
                index++
        ) {

            BluetoothDevice appareil =
                    appareils.get(index);

            libelles[index] =
                    appareil.getName()
                            + "\n"
                            + appareil.getAddress();
        }

        return libelles;
    }

    private void connecterAppareil(
            BluetoothDevice appareil
    ) {

        afficherEtatConnexionEnCours();

        controleurBluetooth.connecter(
                appareil
        );
    }

    // =========================================================
    // COULEUR
    // =========================================================

    private void afficherChoixCouleur() {

        new AlertDialog.Builder(this)
                .setTitle(
                        R.string.color_dialog_title
                )
                .setItems(
                        NOMS_COULEURS,
                        (dialogue, position) ->
                                appliquerCouleur(
                                        VALEURS_COULEURS[
                                                position
                                                ]
                                )
                )
                .setNegativeButton(
                        R.string.cancel,
                        null
                )
                .show();
    }

    private void appliquerCouleur(
            int couleur
    ) {

        GradientDrawable fondCouleur =
                new GradientDrawable();

        fondCouleur.setShape(
                GradientDrawable.OVAL
        );

        fondCouleur.setColor(
                couleur
        );

        fondCouleur.setStroke(
                2,
                Color.DKGRAY
        );

        apercuCouleur.setBackground(
                fondCouleur
        );

        String valeurHexadecimale =
                String.format(
                        Locale.ROOT,
                        "#%06X",
                        couleur & 0x00FFFFFF
                );

        envoyerCommande(
                "COLOR " + valeurHexadecimale
        );
    }

    // =========================================================
    // ÉTAT DE CONNEXION
    // =========================================================

    private void afficherEtatConnexionEnCours() {

        texteEtatBluetooth.setText(
                R.string.bluetooth_status_connecting
        );

        boutonConnecter.setEnabled(false);
    }

    private void afficherEtatConnecte(
            String nomAppareil
    ) {

        texteEtatBluetooth.setText(
                getString(
                        R.string.bluetooth_status_connected,
                        nomAppareil
                )
        );

        boutonConnecter.setVisibility(
                View.GONE
        );

        boutonDeconnecter.setVisibility(
                View.VISIBLE
        );

        activerCommandes(true);
    }

    private void afficherEtatDeconnecte() {

        texteEtatBluetooth.setText(
                R.string.bluetooth_status_disconnected
        );

        boutonConnecter.setEnabled(true);

        boutonConnecter.setVisibility(
                View.VISIBLE
        );

        boutonDeconnecter.setVisibility(
                View.GONE
        );

        activerCommandes(false);
    }

    private void activerCommandes(
            boolean activer
    ) {

        boutonChoisirCouleur.setEnabled(
                activer
        );

        curseurLuminosite.setEnabled(
                activer
        );

        boutonEteindre.setEnabled(
                activer
        );

        boutonOctobreRose.setEnabled(
                activer
        );

        carteArcEnCiel.setEnabled(
                activer
        );

        carteRespiration.setEnabled(
                activer
        );

        carteFeu.setEnabled(
                activer
        );

        carteOcean.setEnabled(
                activer
        );

        carteFlash.setEnabled(
                activer
        );

        carteFixe.setEnabled(
                activer
        );

        float opacite =
                activer ? 1.0f : 0.45f;

        carteArcEnCiel.setAlpha(opacite);
        carteRespiration.setAlpha(opacite);
        carteFeu.setAlpha(opacite);
        carteOcean.setAlpha(opacite);
        carteFlash.setAlpha(opacite);
        carteFixe.setAlpha(opacite);
    }

    private void afficherMessage(
            int identifiantMessage
    ) {

        Toast.makeText(
                this,
                identifiantMessage,
                Toast.LENGTH_LONG
        ).show();
    }

    // =========================================================
    // RETOURS BLUETOOTH
    // =========================================================

    @Override
    public void onConnexionEtablie(
            String nomAppareil
    ) {

        afficherEtatConnecte(
                nomAppareil
        );
    }

    @Override
    public void onDeconnexion() {

        afficherEtatDeconnecte();
    }

    @Override
    public void onErreurConnexion() {

        afficherEtatDeconnecte();

        afficherMessage(
                R.string.connection_failed
        );
    }

    @Override
    public void onConnexionPerdue() {

        afficherEtatDeconnecte();

        afficherMessage(
                R.string.connection_lost
        );
    }

    @Override
    public void onRequestPermissionsResult(
            int codeDemande,
            String[] autorisations,
            int[] resultats
    ) {

        super.onRequestPermissionsResult(
                codeDemande,
                autorisations,
                resultats
        );

        if (codeDemande
                != DEMANDE_AUTORISATION_BLUETOOTH) {

            return;
        }

        if (resultats.length > 0
                && resultats[0]
                == PackageManager.PERMISSION_GRANTED) {

            continuerConnexion();

        } else {

            afficherMessage(
                    R.string.permission_denied
            );
        }
    }

    @Override
    public void onBackPressed() {

        if (menuOuvert) {

            fermerMenu();
            return;
        }

        super.onBackPressed();
    }

    @Override
    protected void onDestroy() {

        controleurBluetooth.fermer();

        super.onDestroy();
    }
}