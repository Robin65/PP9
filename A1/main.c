#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Header.h"
#include <math.h>
#include <time.h>

const char VERSIONSNR[]= "2.1";

int main(int argc, char* argv[]){

int option;
int expected_value;
int std_deviation;
int amount_of_values;
FILE *ptr = fopen ("output_stream", "w");

if(ptr == NULL){
	printf("Error!");
	exit(1);
	
}
	while((option = getopt(argc, argv, "hvs")) != -1)
		switch(option)
		{
			case 'h':
			printf("-h = Hilfe\n");
			printf("-v = Version\n");
			printf("-s = Eingabe der benötigten Argumente\n");
			exit(0);

			case 'v':	
			printf("Version: %s\n",VERSIONSNR);
			exit(0);

			case 's':
			printf("Geben sie die folgenden Werte ein\n");
			printf("Erwarteten Werte!\n");
			scanf("%d", &expected_value);
			printf("Standard verteilung!\n");
			scanf("%d", &std_deviation);
			printf("Menge der Werte!\n");
			scanf("%d", &amount_of_values);
			break;

			default:
			printf("Idiot, das war falsch! Benutze die Hilfe -h\n");
			exit(0);
		
}	
	print_gaussian_dist(expected_value, std_deviation, amount_of_values, ptr);
	fclose(ptr);	
return 1;
}
