#include <stdio.h>
#include <limits.h>
#include <math.h>

long double factorial (long double n)
{
  long double r;
  for (r = 1; n > 1; r *= (n--));
  return r;
}

int main()
{
    int n, iter;
    double ans, func, add, l = 0.1, r = 0.6, x = 0.1;
    long double eps = 1.0l;
    while (2.0l + eps / 2.0l > 2.0l) {
        eps /= 2.0l;
    }
    printf("Machine eps double = %.16Le\n", eps);
    printf("Write n: \n");
    scanf("%d", &n);
    printf("n = %d, \n", n);
    printf("Table znacheniy Teylor and stand f(x) = e^2x");
    printf("________________________________________________________________________\n");
    printf("|   x   |          sum          |        f(x)           |count iter |\n");
    printf("________________________________________________________________________\n");
    for (int i = 1; i <= n; i++) {
        add = 1;
        iter = 1;
        func = exp(2*x);
        ans = 1;
        while (fabs(add) > eps && iter < 100) {
            add = (pow(2*x, iter))/factorial(iter);
            iter++;
            ans = ans + add;
        }
       printf("| %.3f | %.18lf | %.18lf |      %d       |\n", x,ans , func, iter);
       printf("________________________________________________________________________\n");
        x += (r - l) / n;
    }
    return 0;
}
