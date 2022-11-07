#include "functions.h"
int main()
{
    double x = inputX();
    double eps = inputEps();
    double a[MAX];

    int count = findElements(x, eps, a);
    
    output(count, a);
}