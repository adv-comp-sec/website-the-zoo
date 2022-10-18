/*
Filename: animals.cpp
Project: wdd-a03
Date: October 17th, 2022
Author: Maísa Wolff Resplande and Hyewon Lee
Description: This file contains the form to register to the Zoo and choose an animal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#pragma warning(disable : 6001)

// constants
#define kNameLength	50
#define kAnimalLength 5
#define kAddressLength 50
#define SUCCESS 0

int main(void)
{
	char* data;							// variable used to grab/point to the environment variable(s)
	char name[kNameLength];				// user name
	char animal[kAnimalLength];			// animal code choose by user
	char animalName[kAnimalLength];					// animal name
	char descriptionAddress[kAddressLength];		// the address of the description text file

	printf("Content-type:text/html\r\n\r\n");

	printf("<html>");
	printf("<head>");
	printf("<title>The Movies Zoo</title>");
	printf("</head>\n");

	printf("<style>");
	printf("body {background-color: #F0F8FF;}\n");
	printf(".content {display: flex; flex-direction: row; justify-content: center; align-items: center}\n");
	printf("#description {padding: 40px; align-items: center;}");
	printf("</style>");

	printf("<body>\n");

	// get the information passed into the CGI program and scanf it out ...
	data = getenv("QUERY_STRING");
	if (sscanf(data, "name=%[^&]&animal=%s",&name, &animal) != 2)
	{
		printf("Invalid Input");
		return -1;
	}

	// change the blank character '+' into ' '
	char* changeBlank = strchr(name, '+');
	*changeBlank = ' ';

	if (strcmp(animal, "wolf") == SUCCESS)
	{
		strcpy(animalName, "Wolf");
		strcpy(descriptionAddress, "./theZoo/descript_wolf.txt");
	}
	else if (strcmp(animal, "orca") == SUCCESS)
	{
		strcpy(animalName, "Orca");
		strcpy(descriptionAddress, "./theZoo/descript_orca.txt");
	}
	else if (strcmp(animal, "sqrl") == SUCCESS)
	{
		strcpy(animalName, "Squirrel");
		strcpy(descriptionAddress, "./theZoo/descript_sqrl.txt");
	}
	else if (strcmp(animal, "elph") == SUCCESS)
	{
		strcpy(animalName, "Elephant");
		strcpy(descriptionAddress, "./theZoo/descript_elph.txt");
	}
	else if (strcmp(animal, "grff") == SUCCESS)
	{
		strcpy(animalName, "Giraffe");
		strcpy(descriptionAddress, "./theZoo/descript_grff.txt");
	}
	else if (strcmp(animal, "lion") == SUCCESS)
	{
		strcpy(animalName, "Lion");
		strcpy(descriptionAddress, "./theZoo/descript_lion.txt");
	}
	else
	{
		printf("Invalid input");
		return -1;
	}

	// the presenting part
	// the image of the animal
	printf("<div class = \"content\">");
	printf("<div id = \"image\">");
	printf("<img src='./theZoo/image_%s.jpg' alt='%s' width=400 height=400><br>", animal, animalName);
	printf("</div>");

	// the description of the animal
	printf("<div id = \"description\">");
	printf("<h1> Hello, %s <br> <h1>", name);
	printf("<h1> You choose %s </h1>", animalName);

	FILE* myfile = fopen(descriptionAddress, "r");
	if (myfile == NULL)
	{
		printf("Unable to open file!");
		return -1;
	}

	char buffer[255];

	while (!feof(myfile)) {
		if (fgets(buffer, sizeof buffer, myfile) != 0 && *buffer != '\n')
		{
			int len = strlen(buffer);
			if (len > 0 && buffer[len - 1] == '\n')
			{
				buffer[len - 1] = 0;
			}
			printf("%s", buffer);

		}
	}

	fclose(myfile);

	printf("</div>");
	printf("</div>");

	printf("</body></html>");

	return 0;
}


