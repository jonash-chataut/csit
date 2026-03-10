#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,*ptr,i,m;
printf("Enter the value of n");
scanf("%d",&n);
//for garbage value 
ptr=(int*)malloc(n*sizeof(int));
for (i=0;i<=n;i++)
{
    printf("%d\n",*(ptr+1));
}
printf("Now initializing\n");
//Now initializing the value by asking to user
printf("Enter the value of the elements\n");
for (i=0;i<=n;i++)
{
    
    scanf("%d",*(ptr+i));
}
// Print the values
printf("The value of the elements\n");
for (i=0;i<=n;i++)
{
    printf("%d",*(ptr+i));
}

// realloc
printf("/n");
printf("Enter the value of m\n");
scanf("%d",&m);
ptr=(int*)realloc(ptr,m*sizeof(int));
//for garbage value 
for (i=0;i<=m;i++)
{
    printf("%d\n",*(ptr+1));
}
printf("Now initializing\n");
//Now initializing the value by asking to user
printf("Enter the value of the elements\n");
for (i=0;i<=m;i++)
{
    
    scanf("%d",*(ptr+i));
}
// Print the values
printf("The value of the elements\n");
for (i=0;i<=m;i++)
{
    
    printf("%d",*(ptr+i));
}
return 0;
}
