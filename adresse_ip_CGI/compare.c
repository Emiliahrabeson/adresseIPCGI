#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void content_type();
void start();
void end();
void fichier (char* log,char* mdp,char* adresse);

int main()
{
char log[100] = {0};
char mdp[100] = {0};
char adresse[100] = {0};

	content_type();
	start();
	fichier (log,mdp,adresse);
	end();
    return 0;
}
void content_type()
{
	printf("content-type: text/html\n\n");
}
void start()
{
	printf("<HTML> \n"
				" <HEAD> "
                "<link rel=\"stylesheet\" href=\"style.css\">"
			"    <TITLE> connecter</TITLE>"
			"        <META charset=\"UTF-8\">"                        
				"</HEAD>"
					"<BODY>");		
}

void fichier (char* log,char* mdp,char* adresse)
{
    char line[256];
    char* user;
    char* mot;
    int vrai = 0;
    char rep;
    char* query;

    query = getenv("QUERY_STRING");
    sscanf(query, "Nom=%99[^&]&motdepasse=%99s",log,mdp);

    FILE* fic = fopen("login.txt", "r+");
    if (fic == NULL) {
        printf("<h3 class=\"deco\" p>Erreur d'ouverture du fichier</h3>\n");
        return;
    }
    //login(log, mdp);

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
                    printf("<br><br><br><br><br><B class=\"gras\" > Adress_Test </B><br><br><br>\n");
                    printf("<h3 class=\"deco\" >Connexion réussie!</h3>\n");
                    vrai = 1;
                    printf("<h3 class=\"deco\" >Bienvenue %s</h3>\n\n",user);
                    printf(" <a class=\"link\" href=\"enter_adress.cgi\" > Tester un adresse </a>\n");

                    return;
                }
            }
        }
    }

    if (!vrai || strcmp(user, log) != 0 || strcmp(mdp, mot) != 0) 
    {
        printf("<br><br><br><br><br><B class=\"gras\" > Adress_Test </B><br><br><br>\n");
        printf("<h3 class=\"deco\" >Mot de passe ou nom d'utilisateur incorrect!</h3>\n");
		printf(" <a class=\"link\" href=\"deja.cgi\" > Essayer encore </a>\n\n");
        printf(" <a class=\"link\" href=\"create2.cgi\" > Créer un compte </a>\n\n");
    }

    fclose(fic);
}

void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");
		   	
}
