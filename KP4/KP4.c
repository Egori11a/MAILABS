#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

double func(double x);
double f1(double x);
double f2(double x);
double sign(double x);
double machine_eps(double eps);
double dhtm(double a, double b);
double func_itter(double x_prev);
double itter(double a, double b);
double newtn(double a, double b);
double func_newtn(double x_prev);
// tg(x/2)-ctg(x/2)+x=0
// x = ctg(x/2)-tg(x/2)
//x = x_prev - func(x_prev)/f1(x_prev);
//
// 0,4+arctg(sqrt(x))-x
// x = 0,4+arctg(sqrt(x))
double func_1(double x);
double f1_1(double x);
double f2_1(double x);
double dhtm_1(double a, double b);
double sign_1(double x);
double func_itter_1(double x_prev);
double itter_1(double a, double b);
double newtn_1(double a, double b);
double func_newtn_1(double x_prev);
void write();

int main() {
    write();
}

void write() {
    printf("dichotomy \t iteration\t Newton's\n");
    printf("%.4lf \t\t", dhtm(1.0, 2.0));
    printf("%.4lf \t\t", itter(1.0, 2.0));
    printf("%.4lf", newtn(1.0, 2.0));
    printf("\n");
    printf("%.4lf \t\t", dhtm_1(1.0, 2.0));
    printf("%.4lf \t\t", itter_1(1.0, 2.0));
    printf("%.4lf", newtn_1(1.0, 2.0));
}

// Hewthon 1 func
double newtn(double a, double b) {
    double x = a;
    double x_prev = (a+b)/2;
    double eps = machine_eps(1.0);
    int n = 1;
    char s[] = "method isn't available";

    if (fabs(func(x)*f2(x)) > (f1(x)*f1(x))) {
        return 0;
    }

    while (n < 100) {
        n++;
        x = func_newtn(x_prev);
        if (fabs(x - x_prev) < eps) {
            break;
        } else {
            x_prev = x;
        }
    }
    return x;
}
//Newthon 2 func
double newtn_1(double a, double b) {
    double x = a;
    double x_prev = (a+b)/2;
    double eps = machine_eps(1.0);
    int n = 1;


    if (fabs(func_1(x)*f2_1(x)) > (f1_1(x)*f1_1(x))) {
        return 0;
    }

    while (true) {
        n++;
        x = func_newtn_1(x_prev);
        if (fabs(x - x_prev) < eps) {
            break;
        } else {
            x_prev = x;
        }
    }
    return x;
}

double func_newtn(double x_prev) {
    double x = x_prev - func(x_prev)/f1(x_prev);
    return x;
}

double func_newtn_1(double x_prev) {
    double x = x_prev - func_1(x_prev)/f1_1(x_prev);
    return x;
}
//iter 1 func
double itter(double a, double b) {
    double x = 1.0;
    double x_prev = (a+b)/2;
    double eps = machine_eps(1.0);
    int n = 1;

    if (fabs(f1(x_prev)) >= 1 ) {
        return 0;
    }
    while (true) {
        x = func_itter(x_prev);
        if (fabs(x - x_prev) < eps) {
            break;
        } else {
        x_prev = x;
        }
    }
    return x;
}
//inet 2 func
double itter_1(double a, double b) {
    double x = a;
    double x_prev = (a+b)/2;
    double eps = machine_eps(1.0);
    int n = 1;

    if (fabs(f1_1(x_prev)) >= 1 ) {
        return 0;
    }
    while (true) {
        x = func_itter_1(x_prev);
        if (fabs(x - x_prev) < eps) {
            break;
        } else {
        x_prev = x;
        }
    }
    return x;
}
double func_itter(double x_prev) {
    double x = cos(x_prev/2)/sin(x_prev/2)-tan(x_prev/2);
    return x;
}

double func_itter_1(double x_prev) {
    double x = 0.4+atan(sqrt(x));
    return x;
}

//dihotomia 1 func
double dhtm(double a, double b) {
    double x = (a+b)/2;
    double x_prev = 1.0;
    double eps = machine_eps(1.0);
    int n = 1;

    while (func(x) != 0 && fabs(x - x_prev) > eps) {
        x_prev = x;

        if (sign(x) == sign(a)) {
            a = x;
        } else {
            b = x;
        }
        x = (a+b)/2;
        n++;
    }
    return x;
}
//dihotomia 2 func
double dhtm_1(double a, double b) {
    double x = (a+b)/2;
    double x_prev = a;
    double eps = machine_eps(1.0);
    int n = 1;

    while (func_1(x) != 0 && fabs(x - x_prev) > eps) {
        x_prev = x;

        if (sign_1(x) == sign_1(a)) {
            a = x;
        } else {
            b = x;
        }
        x = (a+b)/2;
        n++;
    }
    return x;
}


double machine_eps(double eps) {
    while (1.0 + eps/2.0 > 1)
        eps /= 2.0;

    return eps;
}


double sign(double x) {
    if ((tan(x/2)-cos(x/2)/sin(x/2)+x)> 0) {
        return true;
    } else if ((tan(x/2)-cos(x/2)/sin(x/2)+x)< 0) {
        return false;
    } else return false;
}

double sign_1(double x) {
    if ((0.4+atan(sqrt(x))-x) > 0) {
        return true;
    } else if ((0.4+atan(sqrt(x))-x)  < 0) {
        return false;
    } else return false;
}


double func(double x) {
    return -1/tan(x/2)+tan(x/2)+x;
}
double func_1(double x) {
    return 0.4+atan(sqrt(x))-x;
}


double f1(double x) {
    return 1+1/(2*pow(cos(x/2), 2))+1/(2*pow(sin(x/2), 2));
}

double f1_1(double x) {
    return 1/(2*sqrt(x)+2*x*sqrt(x))-1;
}


double f2(double x) {
    return -cos(x)/(2*pow(cos(x/2), 3)*pow(sin(x/2), 3));
}

double f2_1(double x) {
    return (3*x+1)/((sqrt(x))*pow((2*sqrt(x)+2*x*sqrt(x)), 2));
}
