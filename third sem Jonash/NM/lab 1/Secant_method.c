//Wap to implement the secant method
#include<stdio.h>
#include<math.h>
#include<conio.h>

int a3,a2,a1,a0;
float func(float x){
	return (a3*pow(x,3)+a2*pow(x,2)+a1*pow(x,1)+a0*pow(x,0));
}

int main(){
	float x1,x0,x2,E,Era;
	printf("*****Secant method*****\n Compilied by -> Bipana\n");
	printf("Enter coefficients a3, a2, a1, and a0: \na3 = ");
	scanf("%d", &a3);
	printf("a2 = ");
	scanf("%d", &a2);
	printf("a1 = ");
	scanf("%d", &a1);
	printf("a0 = ");
	scanf("%d", &a0);
	printf("Enter initial guesses x0, x1 and Error precision: \nx0 = ");
	scanf("%f", &x0);
	printf("x1 = ");
	scanf("%f", &x1);
	printf("Error(E) = ");
	scanf("%f", &E);
	while(1){
		x2=x1-(func(x1)*(x1-x0))/(func(x1)-func(x0));
		Era=(x2-x1)/x2;
		if(fabs(Era)<E){
			printf("The root is: %f",x2);
			break;
		}
		else{
			x0=x1;
			x1=x2;
		}
	}	
}
