#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void content_type();
void start();
void end();
void tester (char adresse[100]);

int main()
{
char log[100] = {0};
char mdp[100] = {0};
char adresse[100] = {0};

	content_type();
	start();
	tester(adresse);
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

void tester (char adresse[100])
{
    int chiffre1, chiffre2, chiffre3, chiffre4;
    char rep;
     char* query = getenv("QUERY_STRING");

    if (query != NULL)
    {
        sscanf(query, "adresse=%99s", adresse);
    }
    else {
        printf("<h3 class=\"deco\" >Aucune adresse fournie.</h3>\n");
        return;
    }

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

    if (chiffre1 >= 0 && chiffre2 >= 0 && chiffre3 >= 0 && chiffre4 >= 0 && chiffre1 <= 255 && chiffre2 <= 255 && chiffre3 <= 255 && chiffre4 <= 255)
        {
            printf("<br><br><br><br><br><B class=\"gras\" > Adress_Test </B><br><br><br>\n");
             printf("<h3>C'est un adresse IP</h3>");
                if (chiffre1 <= 127 && chiffre1 >= 0)
                {
                    printf("<h3 >de classe A</h3>\n");
                    printf(" <a class=\"link\" href=\"enter_adress.cgi\" > Essayer encore </a>\n\n");
                    printf(" <a class=\"link\"href=\"connecter.cgi\" > se déconnecter </a>\n\n");
                }

                if (chiffre1 >127 && chiffre1 <= 191)
                {
                    printf("<h3>de classe B</h3>\n");
                    printf(" <a class=\"link\" href=\"enter_adress.cgi\" > Essayer encore </a>\n\n");
                    printf(" <a class=\"link\" href=\"connecter.cgi\" > se déconnecter </a>\n\n");
                }
                if (chiffre1 >191 && chiffre1 <= 223)
                {
                    printf("<h3 >de classe C</h3>\n");
                    printf(" <a class=\"link\" href=\"enter_adress.cgi\" > Essayer encore </a>\n\n");
                    printf(" <a class=\"link\" href=\"connecter.cgi\" > se déconnecter </a>\n\n");
                }
                if (chiffre1 >223 && chiffre1 <= 239)
                {
                    printf("<h3 >de classe D</h3>\n");
                    printf(" <a class=\"link\" href=\"enter_adress.cgi\" > Essayer encore </a>\n\n");
                    printf(" <a class=\"link\" href=\"connecter.cgi\" > se déconnecter </a>\n\n");
                }
                if (chiffre1 >239)
                {
                    printf("<h3>de classe E</h3>\n");
                    printf(" <a class=\"link\" href=\"enter_adress.cgi\" > Essayer encore </a>\n\n");
                    printf(" <a class=\"link\" href=\"connecter.cgi\" > se déconnecter </a>\n\n");;
                }
        }

    else if (chiffre1 > 255 || chiffre2 > 255 || chiffre3 > 255 || chiffre4 > 255 || !(chiffre1 >= 0 && chiffre2 >= 0 && chiffre3 >= 0 && chiffre4 >= 0))
    {
        	printf("<br><br><br><br><br><B class=\"gras\" > Adress_Test </B><br><br><br>\n");
        printf("<h3>Ce n'est pas un adresse IP !</h3>\n");
        printf(" <a class=\"link\" href=\"enter_adress.cgi\" > Essayer encore </a>\n\n");
        printf(" <a class=\"link\" href=\"connecter.cgi\" > se déconnecter </a>\n\n");;
        exit(1);
    }
}

void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");
		   	
}
