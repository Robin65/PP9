#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include "static_gauss.h"

char version[]="V2.2";

int main(int argc,char *argv[])
{
	        char *vvalue = NULL;
                int option;
	        int expected_value = 0;
		int std_deviation = 0;
		opterr = 0;



FILE * input_stream;
input_stream = fopen("input_stream.txt", "r");

          while ((option = getopt(argc, argv, "i:hv")) != -1)
          switch (option)
					        {
 case 'h':
          printf("Standart Befehle\n");
	  printf("-h Hilfe\n");
	  printf("-v version\n");
	  printf("-i input_stream\n");
 break;
 case 'i':
          
		input_stream = fopen(optarg, "r");

		gauss_calc(input_stream);
		fclose(input_stream);
 break;
 case 'v':
          printf("%s \n", version);
 break;
 case '?':
          if (optopt == 'i')
          {
          fprintf (stderr, "dies ist nicht möglich -%c Bitte geben sie eine Kompatibele eingabe! \n", optopt);
          }
          else if (isprint (optopt))//is character printable
          {
          fprintf (stderr, "nicht bekannte Option `-%c'.\n", optopt);
          }
          else
          {
          fprintf (stderr, "nicht möglich `\\x%x'.\n", optopt);
          }
          
          return 1;
          default:
          abort ();

						}}
