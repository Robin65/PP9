void print_gaussian_dist(int expected_value, int std_deviation, int amount_of_values, FILE * output_stream)
{

#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>	
#include <unistd.h>	

// Declaration

	float e = 2.7182818284590452343602874713527;
	float PI = 3.141592653589793238462643383279;
        float gaussian_density_fc[101][4];
        float Counter = 0;
	int i;
	int j;
	int k;

// Box-Mueller-Transformation
for (i=0; i<101; i++){
	gaussian_density_fc[i][1] =(1/sqrt((2*PI)))*pow(e,(-1*(-5.0 + (0.1 * i)) * (-5.0 + (0.1 * i))));
}

//erstelle Summe der funktion und erhöhe diese homogen
for (i = 0; amount_of_values > Counter; i++) {
Counter = 0;

for (j = 0; j <101; j++) {
	Counter = Counter + (gaussian_density_fc[j][1] * (i*0.1+1));
}
if (Counter > amount_of_values) {
	for (k=0; k<101;k++){
		gaussian_density_fc[k][2]=1+gaussian_density_fc[k][1] * (i*0.1+1);
		gaussian_density_fc[k][3]= (int) gaussian_density_fc[k][2];
	}
}
}

// Berechnung der gauß dichte einzelwerte
for (i=0; i<101;i++) {
	gaussian_density_fc[i][4]= expected_value + (std_deviation * (-5.0+(0.1*i)));
}

// Ausgabe der verteilung
if (output_stream == stdout)
	printf("\nGauss verteilte werte: \n");
	else
	printf("\nDaten Ausgabe zum Output_Stream! \n");

for (i=0; i<101; i++){
		for (j=0; j<gaussian_density_fc[j][3]; j++){
		fprintf(output_stream, "%.2f, ", gaussian_density_fc[i][4]);
		}
		fprintf(output_stream, "\n");
}

printf("\n FERTIG\n");
}
