/*Customers arrive in a bank according to a Poisson's process with mean inter arrival time of 10
minutes. Customers spend an average of 5 minutes on the single available counter, and leave.
Write a program in C to find:
 I. Probability that a customer will not have to wait at the counter.
II. Expected number of customers in the bank.
III. Time can a customer expect to spend in the bank*/

#include <stdio.h>
#include <conio.h>
int main()
{
    float l, m, e;
    float p, et;
    printf("Enter Inter arrival time of customers per hours:");
    scanf("%f", &l);
    printf("\nEnter The average time spent by cutomers per hour:");
    scanf("%f", &m);
    p = 1 - l / m;
    e = l / (m - l);
    et = 1 / (m - l);
    et = et * 60;
    printf("\nThe probability That a customer wont't have to wait at counter:%f ", p);
    printf("\n\nExpected number of customer: %f", e);
    printf("\n\nExpected time to be spent in bank: %f minutes", et);
    return 0;
}
