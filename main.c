#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file = NULL; // Pointeur de fichier 1
    FILE *file2 = NULL; // Pointeur de fichier 2

    int decalage; // Variable pour le decalage
    char text[100]; // Variable pour le texte

    printf("Entrez le texte a crypter : "); // Demande de texte
    scanf("%s", text); // Recuperation du texte 
    file = fopen("text.txt", "w"); // Ouverture du fichier en mode ecriture
    fprintf(file, "%s", text); // Ecriture du texte dans le fichier 1
    fclose(file); // Fermeture du fichier

    printf("Entrez le decalage : "); // Demande de decalage
    scanf("%d", &decalage); // Recuperation du decalage

    file = fopen("text.txt", "r"); // Ouverture du fichier en mode lecture
    file2 = fopen("text2.txt", "w"); // Ouverture du fichier 2 en mode ecriture
    char c; // Variable pour le caractere
    while ((c = fgetc(file)) != EOF){ // Boucle pour lire le fichier 1
        if (c >= 'A' && c <= 'Z'){ // Si le caractere est une majuscule
            c = c + decalage; // On ajoute le decalage 
            if (c > 'Z'){ // Si le caractere depasse Z
                c = c - 26; // On soustrait 26
            }
        }
        else if (c >= 'a' && c <= 'z'){ // Si le caractere est une minuscule
            c = c + decalage; // On ajoute le decalage
            if (c > 'z'){ // Si le caractere depasse z
                c = c - 26; // On soustrait 26
            } 
        }
        fputc(c, file2); // Ecriture du caractere dans le fichier 2
    };
    fclose(file); // Fermeture du fichier 1
    fclose(file2); // Fermeture du fichier 2

    printf("Le fichier a ete crypte avec succes\n"); // Message de confirmation

    return 0; // Fin du programme

}
