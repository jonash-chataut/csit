#include<stdio.h>
#include<math.h>
int main()
{
    printf("*****Non-linear Regression (Polynomial model)*****\n Compilied by -> Jonash Chataut\n");
    int m,n,i,j,k;
    float a[20][20],b[20],z[20],x[20],fx[20];
    float sum,pivot,term;
    printf("Enter no. of data points:\n");
    scanf("%d",&n);
    printf("Enter the degree of polynomial to be fitted\n");
    scanf("%d",&m);
    printf("Enter the data points x and fx(y)\n");
    for(int i=0;i<n;i++)
    {
        // printf("Enter data points (x[%d],fx[%d])",i)
        scanf("%f%f",&x[i],&fx[i]);
    }

    // Construction of coefficient matrix
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=m;j++)
        {
            sum=0;
            for(k=0;k<n;k++)
            {
                sum=sum+pow(x[k],i+j);
                a[i][j]=sum;
            }
        }
    }

    // Construction of RHS vectors
    for(i=0;i<=m;i++)
    {
        sum=0;
        for(k=0;k<n;k++)
        {
            sum=sum+fx[k]*pow(x[k],i);
        }
        // yetaaa errorrrrr hoki......
        b[i]=sum;
    }

    // forward elimination
    for(k=0;k<m;k++)
    {
        pivot=a[k][k];
        if(pivot<0.000001)
            printf("Method failed\n");
        else
        for(i=k+1;i<=m;i++)
        {
            term=a[i][k]/pivot;
            for(j=0;j<=m;j++)
            {
                a[i][j]=a[i][j]-a[k][j]*term;
            }
            b[i]=b[i]-b[k]*term;
        }
    }
    z[m]=b[m]/a[m][m];

    // Back substitution
    for(i=m-1;i>=0;i--)
    {
        sum=0;
        for(j=i+1;j<=m;j++)
        {
            sum=sum+a[i][j]*z[j];
        }
        z[i]=(b[i]-sum)/a[i][i];
    }

    printf("The polynomial of regression is :\n y = %0.2f + %0.2f x ",z[0],z[1]);
    for(i=2;i<=m;i++)
    {
        printf("+ %0.2f x^%d",z[i],i);
    }

return 0;
}
