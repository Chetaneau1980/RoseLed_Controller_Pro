package org.roseled.controllerpro;

import android.annotation.SuppressLint;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.os.Handler;
import android.os.Looper;

import java.io.IOException;
import java.io.OutputStream;
import java.nio.charset.StandardCharsets;
import java.util.UUID;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * Gère exclusivement la connexion Bluetooth Classic avec le contrôleur RoseLed.
 */
public final class BluetoothController {

    private static final UUID UUID_PORT_SERIE =
            UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    private final ExecutorService executeurBluetooth = Executors.newSingleThreadExecutor();
    private final Handler gestionnairePrincipal = new Handler(Looper.getMainLooper());
    private final EcouteurConnexion ecouteurConnexion;

    private volatile BluetoothSocket socketBluetooth;
    private volatile boolean connecte;

    public BluetoothController(EcouteurConnexion ecouteurConnexion) {
        this.ecouteurConnexion = ecouteurConnexion;
    }

    public boolean estConnecte() {
        return connecte;
    }

    @SuppressLint("MissingPermission")
    public void connecter(BluetoothDevice appareil) {
        executeurBluetooth.execute(() -> etablirConnexion(appareil));
    }

    public void deconnecter() {
        fermerSocket();
        notifierDeconnexion();
    }

    public void envoyerCommande(String commande) {
        if (!connecte || socketBluetooth == null) {
            return;
        }

        executeurBluetooth.execute(() -> ecrireCommande(commande));
    }

    public void fermer() {
        deconnecter();
        executeurBluetooth.shutdownNow();
    }

    @SuppressLint("MissingPermission")
    private void etablirConnexion(BluetoothDevice appareil) {
        fermerSocket();

        try {
            BluetoothSocket nouveauSocket =
                    appareil.createRfcommSocketToServiceRecord(UUID_PORT_SERIE);
            socketBluetooth = nouveauSocket;
            nouveauSocket.connect();
            connecte = true;
            notifierConnexion(appareil.getName());
        } catch (IOException | SecurityException erreur) {
            fermerSocket();
            notifierErreurConnexion();
        }
    }

    private void ecrireCommande(String commande) {
        BluetoothSocket socketActuel = socketBluetooth;

        if (!connecte || socketActuel == null) {
            return;
        }

        try {
            OutputStream sortie = socketActuel.getOutputStream();
            sortie.write((commande + "\n").getBytes(StandardCharsets.UTF_8));
            sortie.flush();
        } catch (IOException erreur) {
            fermerSocket();
            notifierPerteConnexion();
        }
    }

    private void fermerSocket() {
        BluetoothSocket socketActuel = socketBluetooth;
        socketBluetooth = null;
        connecte = false;

        if (socketActuel == null) {
            return;
        }

        try {
            socketActuel.close();
        } catch (IOException erreurIgnoree) {
            // La socket est déjà inutilisable : aucune autre action n'est nécessaire.
        }
    }

    private void notifierConnexion(String nomAppareil) {
        gestionnairePrincipal.post(
                () -> ecouteurConnexion.onConnexionEtablie(nomAppareil));
    }

    private void notifierDeconnexion() {
        gestionnairePrincipal.post(ecouteurConnexion::onDeconnexion);
    }

    private void notifierErreurConnexion() {
        gestionnairePrincipal.post(ecouteurConnexion::onErreurConnexion);
    }

    private void notifierPerteConnexion() {
        gestionnairePrincipal.post(ecouteurConnexion::onConnexionPerdue);
    }

    public interface EcouteurConnexion {
        void onConnexionEtablie(String nomAppareil);

        void onDeconnexion();

        void onErreurConnexion();

        void onConnexionPerdue();
    }
}

