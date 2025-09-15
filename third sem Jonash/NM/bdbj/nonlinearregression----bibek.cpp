#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("\n-------------BIBEK PATHAK---------------\n");
    printf("Enter the number of points: ");
    scanf("%d", &n);
    
    double x[n], y[n];
    
    printf("Enter the data points (x and y):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i+1);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i+1);
        scanf("%lf", &y[i]);
    }
    
    double sx = 0, sy = 0, sxy = 0, sx2 = 0;
    
    for (int i = 0; i < n; i++) {
        y[i] = log(y[i]);
    }
    
    for (int i = 0; i < n; i++) {
        sx += x[i];
        sy += y[i];
        sxy += x[i] * y[i];
        sx2 += x[i] * x[i];
    }
    
    double b = (n * sxy - sx * sy) / (n * sx2 - sx * sx);
    double a = exp((sy / n) - (b * sx / n));
    
    printf("The exponential regression equation is: y = %.2lf * e^(%.2lf * x)\n", a, b);
    
    return 0;
}

