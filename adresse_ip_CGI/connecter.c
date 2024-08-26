#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void content_type();
void start();
void end();
void choix();
int main()
{
	content_type();
	start();
	choix();
	end();
    return 0;
}
void content_type()
{
	printf("content-type: text/html\n\n");
}
void choix()
{
	printf("<br><br><br><br><br><B class=\"gras\" > Adress_Test </B><br><br><br>\n");
	printf("<fieldset class=\"connect\">\n");

	printf("    <div>\n");
	printf("        <form action=\"deja.cgi\" method=\"get\">\n");
	printf("            <input type=\"submit\" value=\"Se connecter\" />\n");
	printf("        </form>\n");
	printf("    </div>\n");

	printf("    <div>\n");
	printf("        <form action=\"create2.cgi\" method=\"get\">\n");
	printf("            <input type=\"submit\" value=\"Créer un compte\" />\n");
	printf("        </form>\n");
	printf("    </div>\n");

	printf("</fieldset>\n");


}

void start()
{
		printf("<HTML> \n"
				 " <HEAD> "
				 "<link rel=\"stylesheet\" href=\"style.css\">"
				"    <TITLE>connect</TITLE>"
				"        <META charset=\"UTF-8\">"
					"</HEAD>"
					  "<BODY>");		
}
void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");
		   	
}