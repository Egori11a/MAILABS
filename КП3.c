#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    int n, iter, num;
    double cnst, ans, func, add, l = 0.1, r = 0.6, x = 0.1;
    long double eps = 1.0l;
    while (2.0l + eps / 2.0l > 2.0l) {
        eps /= 2.0l;
    }
    printf("Machine eps double = %.16Le\n", eps);
    printf("Write n: \n");
    scanf("%d", &n);
    printf("n = %d, \n", n);
    printf("Table znacheniy Teylor and stand f(x) = (2x-3)/(x-1)^2");
    printf("________________________________________________________________________\n");
    printf("|   x   |          sum          |        f(x)           |count iter |\n");
    printf("________________________________________________________________________\n");
    for (int i = 1; i <= n + 1; i++) {
        add = 1;
        iter = 1;
        func = (2*x-3)/pow(x-1, 2);
        ans = -3;
        while (fabs(add) > eps && iter < 100) {
            cnst = ans;
            add = -(iter+3)*pow(x, iter);
            iter++;
            ans = cnst + add;
        }
       printf("| %.3f | %.18lf | %.18lf |      %d       |\n", x,ans , func, iter);
       printf("________________________________________________________________________\n");
        x += (r - l) / n;
    }
    return 0;
}
