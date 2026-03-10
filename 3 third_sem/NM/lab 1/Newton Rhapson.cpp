//newton

#include<stdio.h>
#include<conio.h>
#include<math.h>

int a3,a2,a1,a0;
float func(float x){
	return (a3*x*x*x+a2*x*x+a1*x+a0);
}

float func_deri(float x){
	return (a3*3*pow(x,2)+a2*2*x+a1);
}

int main(){
	float x0,x1,E,Era;
	printf("*****Newton Rapson method*****\n Compilied by -> Bipana\n");
   // float x0, x1, x2, E, Era;
    printf("Enter coefficients a3, a2, a1, and a0: \na3 = ");
    scanf("%d", &a3);
    printf("a2 = ");
    scanf("%d", &a2);
    printf("a1 = ");
    scanf("%d", &a1);
    printf("a0 = ");
    scanf("%d", &a0);
    //scanf("%d %d %d %d", &a3, &a2, &a1, &a0);
    printf("Enter initial guesses and Error precision: \nx0 = ");
    //scanf("%f %f %f", &x0, &x1, &E);
    scanf("%f", &x0);
//    printf("x1 = ");
//    scanf("%f", &x1);
    printf("Error(E) = ");
	scanf("%f", &E);
//	printf("Enter coefficients a3,a2,a1, and a0: \n");
//	scanf("%d%d%d%d",&a3,&a2,&a1,&a0);
//	printf("Enter your initial guess and Error precision : \n");
//	scanf("%f%f",&x0,&E);
	
	while(true){
		x1=x0-(func(x0)/func_deri(x0));
		Era=fabs(x1-x0)/x1;
		if(Era<E){
			printf("Root= %f\n",x1);
			break;
		}
		else x0=x1;
	}
}
