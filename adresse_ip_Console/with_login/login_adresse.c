#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void entrer (char adresse[100]);
void separer (char adresse[100]);
void login (char* log,char* mdp);
void fichier (char* login,char* mdp,char* adresse);
void create (char* log,char* mdp,char* adresse);
void question (char* log,char* mdp,char* adresse);
void poser (char rep);
int main()
{
    char adresse[100];
    char log[100];
    char mdp[50];
    int chiffre1,chiffre2,chiffre3,chiffre4;
    char rep;

    question (log, mdp, adresse);
    poser (rep);
    do {
        poser (rep);
        question (log, mdp, adresse);
    } while (rep != 'Y');
    
}
void entrer (char adresse[100])
{
    printf("entrer l'adresse à tester :");
    scanf("%s",adresse);
}
void login (char* log,char* mdp)
{
    printf("login :");
    scanf("%s",log);
    printf("mot de passe :");
    scanf("%s",mdp);
}
void question (char* log,char* mdp,char* adresse)
{
    int choix;
    printf("Choisissez : \n");
    printf("1.J'ai déjà un compte \n");
    printf("2.Créér un compte \n");
    scanf("%d",&choix);
    switch (choix)
    {
    case 1:
        fichier ( log, mdp,adresse);
        break;
    case 2:
        create ( log, mdp,adresse);
        fichier ( log, mdp,adresse);
    default:
        printf("choix non valide bye! xD");
        break;
    }
}
void create (char* log,char* mdp,char* adresse)
{
     FILE* fic = fopen("login.txt", "r+");
    if (fic == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    printf("\nEntrer le nom d'utilisateur :");
    scanf("%s",log);
    printf("\nEntrer votre mot de passe :");
    scanf("%s",mdp);
    fseek(fic,0,SEEK_END);
    fprintf(fic,"\n%s:%s\n",log,mdp);
    printf("\nUtilisateur créé avec succès \n");
    fclose(fic);
}
void fichier (char* log,char* mdp,char* adresse)
{
    char line[256];
    char* user;
    char* mot;
    int vrai;
    char rep;
    FILE* fic = fopen("login.txt", "r+");
    if (fic == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    login(log, mdp);

    while (fgets(line, sizeof(line), fic) != NULL)
    {
        line[strcspn(line, "\n")] = 0;
        char* token = strtok(line, ":");
        if (token != NULL)
        {
            user = token;
            token = strtok(NULL, ":");
            if (token != NULL) 
            {
                mot = token;
                if (strcmp(user, log) == 0 && strcmp(mdp, mot) == 0)
                {
                    printf("Connexion réussie!\n");
                    vrai = 1;
                    printf("Bienvenue %s\n\n",user);
                    entrer(adresse);
                    separer(adresse);
                    return;
                }
            }
        }
    }

    if (!vrai || strcmp(user, log) != 0 || strcmp(mdp, mot) != 0) 
    {
        printf("Mot de passe ou nom d'utilisateur incorrect!\n");
    }

    fclose(fic);
}

void separer (char adresse[100])
{
    int chiffre1, chiffre2, chiffre3, chiffre4;
    char rep;
    char* token = strtok(adresse, ".");


    if (token != NULL)
     {
        chiffre1 = atoi(token);
    }

    token = strtok(NULL, ".");
    if (token != NULL) 
    {
        chiffre2 = atoi(token);
    }

    token = strtok(NULL, ".");
    if (token != NULL)
    {
        chiffre3 = atoi(token);
    }

    token = strtok(NULL, ".");
    if (token != NULL)
    {
        chiffre4 = atoi(token);
    }

    if (chiffre1 > 255 || chiffre2 > 255 || chiffre3 > 255 || chiffre4 > 255 || !(chiffre1 >= 0 && chiffre2 >= 0 && chiffre3 >= 0 && chiffre4 >= 0))
    {
        printf("Ce n'est pas un adresse IP !\n");
        exit(1);
    }
        if (chiffre1 >= 0 && chiffre2 >= 0 && chiffre3 >= 0 && chiffre4 >= 0)
        {
             printf("C'est un adresse IP   ");
                if (chiffre1 <= 127 && chiffre1 > 0)
                {
                    printf("de classe A\n");
                }

                if (chiffre1 >127 && chiffre1 <= 191)
                {
                    printf("de classe B\n");
                }
                if (chiffre1 >191 && chiffre1 <= 223)
                {
                    printf("de classe C\n");
                }
                if (chiffre1 >223 && chiffre1 <= 239)
                {
                    printf("de classe D\n");
                }
                if (chiffre1 >239)
                {
                    printf("de classe E\n");
                }
        }
}

void poser (char rep)
{
    printf("voulez-vous quitter ?(Y/N)");
    scanf("%s",&rep);
}