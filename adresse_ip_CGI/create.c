#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void content_type();
void start();
void end();
void mot ();
void create (char* log,char* mdp,char* adresse);

int main()
{
char log[100] = {0};
char mdp[100] = {0};
char adresse[100] = {0};

	content_type();
	start();
	create (log,mdp, adresse);
    mot ();
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

void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");
}

void create (char* log,char* mdp,char* adresse)
{
     FILE* fic = fopen("login.txt", "a+");
    if (fic == NULL) {
        printf("<h3 class=\"deco\" >Erreur d'ouverture du fichier</h3>\n");
        return;
    }
    // mot ();
    char* query = getenv("QUERY_STRING");
    sscanf(query, "Nom=%99[^&]&motdepasse=%99s",log,mdp);

    fseek(fic,0,SEEK_END);

    fprintf(fic,"\n%s:%s",log,mdp);
     printf("\n<h3 class=\"deco\" >Utilisateur créé avec succès </h3>\n");
    fclose(fic);
}

void mot ()
{
	printf("<br><br><br><br><br><B class=\"gras\" > Adress_Test </B><br><br><br>\n");
	printf("<DIV><FORM ACTION=\"compare.cgi\" METHOD=\"GET\">\n\
			  <INPUT TYPE=\"TEXT\" placeholder=\"Entrer votre nom\" NAME=\"Nom\">\
			   <BR><BR>\
			    <INPUT  TYPE=\"PASSWORD\" placeholder=\"Entrer votre mot de passe\" NAME=\"motdepasse\">\
			   <INPUT TYPE=\"SUBMIT\" VALUE=\"Se connecter\" />\n\
			   </FORM></DIV>\n");
}