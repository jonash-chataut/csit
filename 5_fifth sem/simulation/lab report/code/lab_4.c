/*In a single pump service station, vehicles arrive for fuelling with an average of 5 minutes between
arrivals. If an hour is taken as unit of time, cars arrive according to Poison’s process with an
average of λ= 12 cars/hr. Write a C program to generate Poisson distribution for x = 0,1,2, …. 15. */

#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    float l, m, p[16], pr, x, a, i;
    int j;
    printf("Enter arrival rate per hours:");
    scanf("%f", &l);
    for (x = 0; x < 16; x++)
    {
        a = 1;
        for (i = 1; i <= x; i++)
        {
            a = a * i;
        }
        pr = (pow(2.71, -l) * pow(l, x)) / a;
        // p[x]= (pow(2.71,-l)*pow(l,x))/a;
        printf("P(X=%f) = %f\n", x, pr);
    }
    /* for(x=0;x<16;x++)
    {
        printf("\nP(X=%2d) = %f\n",x,p[x]);
    }*/
    
    return 0;
}