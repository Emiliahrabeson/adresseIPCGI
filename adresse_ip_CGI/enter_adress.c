#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void content_type();
void start();
void end();
void enter_adress();
int main()
{
	content_type();
	start();
	enter_adress();
	end();
    return 0;
}
void content_type()
{
	printf("content-type: text/html\n\n");
}
void enter_adress()
{
	printf("<br><br><br><br><br><B class=\"gras\" > Adress_Test </B><br><br><br>\n");
    printf("<DIV><FORM ACTION=\"tester.cgi\" METHOD=\"GET\">\n\
			  <INPUT TYPE=\"TEXT\" placeholder=\"Entrer un adresse \" NAME=\"adresse\">\
			   <INPUT TYPE=\"SUBMIT\" VALUE=\"Tester\" />\n\
			   </FORM></DIV>\n");
}

void start()
{
		printf("<HTML> \n"
				 " <HEAD> "
				 "<link rel=\"stylesheet\" href=\"style.css\">"
				"    <TITLE>test</TITLE>"
				"        <META charset=\"UTF-8\">"
					"</HEAD>"
					  "<BODY>");		
}
void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");
		   	
}