/*The probabilities of weather conditions (modelled as either rainy or sunny), given the weather on
the preceding day, can be represented by a transition matrix:
0.9 0.1
0.5 0.5
The weather on day 0 is known to be sunny. This is represented by a vector in which the "sunny"
entry is 100%, and the "rainy" entry is 0%: (1  0). Write a C program to find the weather of the
next day by using Markov Chain Method.*/

#include <stdio.h>
#include <conio.h>

int main()
{
    float transMat[2][2] = {0.9, 0.1, 0.5, 0.5}, vect[1][2] = {1, 0}, result[1][2];
    int i, j, k;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            result[i][j] = 0;
            for (k = 0; k < 2; k++)
            {
                result[i][j] += vect[i][k] * transMat[k][j];
            }
        }
    }
    printf("\nWeather of next day using markov chain\n\n");
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%f\t", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}