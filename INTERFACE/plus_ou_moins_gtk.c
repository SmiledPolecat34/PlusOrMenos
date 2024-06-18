#include <gtk/gtk.h>
#include <stdlib.h>
#include <time.h>

int nombreMystere;
int essais;
GtkWidget *entry;
GtkWidget *label;

void on_guess_button_clicked(GtkWidget *widget, gpointer data) {
    const char *entry_text = gtk_entry_get_text(GTK_ENTRY(entry));
    int nombreEntre = atoi(entry_text);
    essais++;

    if (nombreEntre < nombreMystere) {
        gtk_label_set_text(GTK_LABEL(label), "C'est plus !");
    } else if (nombreEntre > nombreMystere) {
        gtk_label_set_text(GTK_LABEL(label), "C'est moins !");
    } else {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Bravo, vous avez trouvé le nombre mystère en %d essais !", essais);
        gtk_label_set_text(GTK_LABEL(label), buffer);
    }
}

void on_new_game_button_clicked(GtkWidget *widget, gpointer data) {
    srand(time(NULL));
    nombreMystere = (rand() % 100) + 1;
    essais = 0;
    gtk_label_set_text(GTK_LABEL(label), "J'ai choisi un nouveau nombre entre 1 et 100. A vous de deviner !");
    gtk_entry_set_text(GTK_ENTRY(entry), "");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    srand(time(NULL));
    nombreMystere = (rand() % 100) + 1;
    essais = 0;

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Jeu du Plus ou Moins");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    label = gtk_label_new("J'ai choisi un nombre entre 1 et 100. A vous de deviner !");
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);

    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), entry, TRUE, TRUE, 0);

    GtkWidget *guess_button = gtk_button_new_with_label("Deviner");
    g_signal_connect(guess_button, "clicked", G_CALLBACK(on_guess_button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), guess_button, TRUE, TRUE, 0);

    GtkWidget *new_game_button = gtk_button_new_with_label("Nouvelle Partie");
    g_signal_connect(new_game_button, "clicked", G_CALLBACK(on_new_game_button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), new_game_button, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
