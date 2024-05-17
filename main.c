#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file = NULL;
    FILE *file2 = NULL;

    int decalage;
    char text[100];

    printf("Entrez le texte a crypter : ");
    scanf("%s", text);
    file = fopen("text.txt", "w");
    fprintf(file, "%s", text);
    fclose(file);

    printf("Entrez le decalage : ");
    scanf("%d", &decalage);

    file = fopen("text.txt", "r");
    file2 = fopen("text2.txt", "w");
    char c;
    while ((c = fgetc(file)) != EOF){
        if (c >= 'A' && c <= 'Z'){
            c = c + decalage;
            if (c > 'Z'){
                c = c - 26;
            }
        }
        else if (c >= 'a' && c <= 'z'){
            c = c + decalage;
            if (c > 'z'){
                c = c - 26;
            }
        }
        fputc(c, file2);
    };
    fclose(file);
    fclose(file2);

    printf("Le fichier a ete crypte avec succes\n");

    return 0;

}
