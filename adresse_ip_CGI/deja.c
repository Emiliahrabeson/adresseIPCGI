#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void content_type();
void start();
void end();
void mot();

int main()
{
	content_type();
	start();
	mot ();
	end();
	return 0;
}	
void content_type()
{
	printf("content-type: text/html\n\n");
}

void mot ()
{
	printf("<br><br><br><br><br><B class=\"gras\" > Adress_Test </B><br><br><br>\n");
	printf("<DIV><FORM ACTION=\"compare.cgi\" METHOD=\"GET\">\n\
			  <INPUT TYPE=\"TEXT\" placeholder=\"Entrer votre nom\" NAME=\"Nom\">\
			   <BR><BR>\
			    <INPUT  TYPE=\"PASSWORD\" placeholder=\"mot de passe\" NAME=\"motdepasse\">\
			   <INPUT TYPE=\"SUBMIT\" VALUE=\"Se connecter\" />\n\
			   </FORM></DIV>\n");
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
