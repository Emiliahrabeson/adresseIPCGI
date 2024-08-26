#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proto.h"
void entrer (char adresse[100])
{
    printf("entrer l'adresse :");
    scanf("%s",adresse);
}
void separer (char adresse[100])
{
    int chiffre1, chiffre2, chiffre3, chiffre4;
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
        printf("Ce n'est pas un adresse IP !");
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
