#include "functions.h"

int f(double, int, double, double, double[]);

double inputEps(){
    double eps;
    do {
    printf("Enter eps: ");
    scanf("%lf", &eps);
    } while (eps <= 0 || eps >= 1);
    return eps;
}

double inputX(){
    double x;
    do {
        printf("Enter x: ");
        scanf("%lf", &x);
    } while (x <= -1 || x >= 1);
    return x;
}

void output(int count, double results[]){
    FILE *f = fopen(OUTPUT_FILE, "w");

    if (f == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        fprintf(f, "%d: %lf\n", i+1, results[i]);
    }

    fclose(f);
    printf("Results saved to %s\n", OUTPUT_FILE);
}

int findElements(double x, double eps, double results[]){
    int count = f(x, 0, x, eps, results);
    return count;
}

int f(double current, int i, double x, double eps, double results[]){
    double factor = (2*(double)i + 1)*(2*(double)i + 1)/(2*(double)i + 2)/(2*(double)i + 3)*x*x;
    double next = current * factor;

    if(i == MAX){
        return 0;
    } else if ( -eps < current - next && current - next < eps){
        return 0;
    } else {
        results[i] = next;
        return f(next, i+1, x, eps, results) + 1;
    }

    results[i] = current;
    printf("Result %d: %lf \n", i, current);

    return f(next, i + 1, x, eps, results) + 1;
}