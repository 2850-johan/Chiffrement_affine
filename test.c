#include <stdio.h>
#include <stdlib.h>

// Fonction pour calculer le PGCD de deux entiers
int pgcd(int a, int b)
{
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Fonction pour chercher l'inverse modulaire
int inverse_modulaire(int a, int b)
{
    int inv, q, r, r1 = a, r2 = b, t, t1 = 0, t2 = 1;
    while (r2 != 0) {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }
    if (t1 < 0) t1 += b;
    inv = t1;
    return inv;
}

int main()
{
    char message[100];
    int a, b, i, choix;
    char message_entree[500];
    printf("Entrez un message à chiffrer  : ");
    scanf ("%[^\n]",message_entree);
    printf("Entrez la valeur de a (entier premier avec 26) : ");
    scanf("%d", &a);
    while (pgcd(a, 26) != 1)
    {
        printf("La valeur de a n'est pas valide. Entrez une autre valeur : ");
        scanf("%d", &a);
    }
    printf("Entrez la valeur de b : ");
    scanf("%d", &b);
    printf("Voulez-vous chiffrer (1) ou déchiffrer (2) le message ? ");
    scanf("%d", &choix);
    for (i = 0; message_entree[i] != '\0'; i++)
    {
        if (message_entree[i] != ' ')
        {
            if (choix == 1)
            {
               message_entree[i] = ((a * (message_entree[i] - 'A') + b) % 26) + 'A';
            }
            else if (choix == 2)
            {
               message_entree[i] = (inverse_modulaire(a, 26) * (message_entree[i] - 'A' - b + 26) % 26) + 'A';
            }
        }
    }
    printf("Message : %s\n", message_entree);
    return 0;
}
