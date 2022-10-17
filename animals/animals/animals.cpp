#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

/* ---------------------------------------------------------------------------------------------------------
	Since we've passed the parameters into this CGI application using the GET method - we can access the
	parameters and values passed in using the QUERY_STRING environment variable - remembering
	that we need to parse the parameters and their values out as "key-value" pairs
   --------------------------------------------------------------------------------------------------------- */
#define kNameLength 20
#define kAnimalLength 5

int main(void)
{
	char* data;						// variable used to grab/point to the environment variable(s)
	char name[kNameLength];			// variable to store the user name
	char animal[kAnimalLength];		// animal choose by user

	printf("Content-type:text/html\r\n\r\n"); // output MIME header

	printf("<html>");
	printf("<head>");
	printf("<title>The Movies Zoo</title>");
	printf("</head>\n");
	printf("<body>\n");
	printf("<div name = ''description' id = 'description'>");
	printf("<h1>The Movies Zoo</h1><p>Hello!</br>In our Zoo, you can check on some animals that got popular because of movies, series, and cartoons.</br>Find out their scientific names, where they live, what they eat, and what premiere made them superstars!</p></div>");

	// get the information passed into the CGI program and scanf it out ...
	data = getenv("QUERY_STRING");
	if (sscanf(data, "name=%s", name) == 1)
	{
		if (name[0] != '+')
		{
			printf("Welcome to our virtual Zoo, %s! </br> Choose one of the animals in the list to know more about it.", name);
			printf("<form name='animalForm' action = 'animals.exe' method = 'GET'><fieldset>");
			printf("<div name ='animalsList' id ='animalsList'>");
			printf("<label for = 'animal'>Animals:");
			printf("<select name = 'animal' id = 'animal'>");
			printf("<option value = 'none'>");
			printf("<option value = 'wolf'>Wolf");
			printf("<option value = 'orca'>Orca");
			printf("<option value = 'sqrl'>Squirrel");
			printf("<option value = 'elph'>Elephant");
			printf("<option value = 'grff'>Giraffe");
			printf("<option value = 'lion'>Lion");
			printf("<input type = 'submit' value = 'Check on animal' > ");

			data = getenv("QUERY_STRING");
			if (sscanf(data, "animal=%s", animal) == 1 && strcmp(animal, "none") != 0)
			{
				printf("It worked");
			}
			else
			{
				printf("<div id = 'errorAnimal' style = 'color:red;'></div>");
				
			}
			printf("</div>");
			
		}
		else
		{
			printf("<div id = 'errorName' style = 'color:red; '></div>");
		}
	}
	else
	{
		printf("<div id = 'errorName' style = 'color:red; '></div>");
	}

	printf("</body></html>");
	
	return 0;
}


