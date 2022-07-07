#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <time.h>

int MAXIMUM;
int GROESSE = 100;
int i;

int main() {
MAXIMUM = GROESSE * 2;
FILE * output_stream;
output_stream = stdout;

srand(time(NULL));
for (i = 0; i < GROESSE; i++){
     printf("%d\n", rand() % MAXIMUM);
    }

fclose(output_stream);
exit(EXIT_SUCCESS);
}	
