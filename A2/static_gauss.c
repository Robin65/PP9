#include <stdio.h>
#include <math.h>
void gauss_calc(FILE * input_stream)
{
int expected_value = 0;
int std_deviation = 0;
int buffer_instream_int[100];
int sum_buffer_instream =0;
int amount_of_values = 100;
int auxilary_std_deviation =0;

        	for (int i=0; i<100; i++) {
		fscanf(input_stream, "%d, ", &buffer_instream_int[i]);

	printf("\n");

	for (int i=0; i<100; i++) {
	sum_buffer_instream = sum_buffer_instream + buffer_instream_int[i];
			}
	expected_value = sum_buffer_instream / amount_of_values;

	for (int i=0; i<100; i++) {
	auxilary_std_deviation = auxilary_std_deviation + ( pow( (buffer_instream_int[i] - expected_value), 2 ) );
	}
	std_deviation = sqrt(auxilary_std_deviation / amount_of_values); 

	printf("\nErwartungswert: %.d, Standart Abweichung: %.df", expected_value, std_deviation);
		}}
