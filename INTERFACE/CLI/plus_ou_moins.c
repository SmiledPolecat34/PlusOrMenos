#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NULL ((void*)0)

int main() {
    int nombreMystere = 0, nombreEntre = 0, essais = 0;
    const int MAX = 100, MIN = 1;

    // Initialisation de la fonction rand
    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

    printf("Bienvenue dans le jeu du Plus ou Moins !\n");
    printf("J'ai choisi un nombre entre %d et %d. A vous de le deviner !\n", MIN, MAX);

    // Boucle de jeu
    do {
        printf("Quel est le nombre ? ");
        scanf("%d", &nombreEntre);
        essais++;

        if (nombreEntre < nombreMystere) {
            printf("C'est plus !\n");
        } else if (nombreEntre > nombreMystere) {
            printf("C'est moins !\n");
        } else {
            printf("Bravo, vous avez trouvé le nombre mystère en %d essais !\n", essais);
        }
    } while (nombreEntre != nombreMystere);

    return 0;
}
