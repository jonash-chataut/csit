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
	printf("Newton Raphson Method\n___________Compiled by BIBEK PATHAK_____________\n\n");
	float x0,x1,E,Era;
	printf("Enter coefficients a3,a2,a1, and a0: \n");
	scanf("%d%d%d%d",&a3,&a2,&a1,&a0);
	printf("Enter your initial guess and Error precision : \n");
	scanf("%f%f",&x0,&E);
	
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
