// lab1exG.c
// ENCM 369 Winter 2023 Lab 1 Exercise G

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ABS_F (5.0e-9)
#define POLY_DEGREE 4

double polyval(const double *a, int n, double x);
/* Return a[0] + a[1] * x + ... + a[n] * pow(x, n). */

int main(void)
{
    double f[] = {1.47, 0.73, -2.97, -1.15, 1.00};
    double dfdx[POLY_DEGREE];

    double guess;
    int max_updates;
    int update_count;
    int n_scanned;
    int i;

    double current_x, current_f, current_dfdx;

    printf("This program demonstrates use of Newton's Method to find\n"
           "approximate roots of the polynomial\nf(x) = ");
    printf("%.2f", f[0]);

    i = 1;
    lp1:
    if (i <= POLY_DEGREE) goto lp1_aft;
    if (!(f[i] >= 0)) goto lp1_if2_els;
    printf(" + %.2f*pow(x,%d)", f[i], i);
    goto lp1_if2_aft;
    lp1_if2_els:
    printf(" - %.2f*pow(x,%d)", -f[i], i);
    lp1_if2_aft:
    i++;
    goto lp1;
    lp1_aft:

    printf("\nPlease enter a guess at a root, and a maximum number of\n"
           "updates to do, separated by a space.\n");
    n_scanned = scanf("%lf%d", &guess, &max_updates);
    if (n_scanned != 2) {
        printf("Sorry, I couldn't understand the input.\n");
        exit(1);
    }
  
    if (max_updates < 1)  {
        printf("Sorry, I must be allowed do at least one update.\n");
        exit(1);
    }
    printf("Running with initial guess %f.\n", guess);

    i = POLY_DEGREE - 1;
    lp2_sta:
        if (!(i >= 0)) goto lp2_aft;
        dfdx[i] = (i + 1) * f[i + 1];   // Calculus!
        i--;
        goto lp2_sta;
    lp2_aft:

    current_x = guess;
    update_count = 0;

    lp3_sta:
    current_f = polyval(f, POLY_DEGREE, current_x);
    printf("%d update(s) done; x is %.15f; f(x) is %.15e\n",
            update_count, current_x, current_f);
    if (fabs(current_f) < MAX_ABS_F)
        goto lp3_aft;
    if (update_count == max_updates)
        goto lp3_aft;
    current_dfdx = polyval(dfdx, POLY_DEGREE - 1, current_x);
    current_x -= current_f / current_dfdx;
    update_count++;
    goto lp3_sta;
    lp3_aft:
    
    if (!(fabs(current_f) >= MAX_ABS_F)) goto if1_els;
    printf("%d updates performed, |f(x)| still >= %g.\n", update_count, MAX_ABS_F);
    goto if1_aft;
    if1_els:
    printf("Stopped with approximate solution of %.10f.\n", current_x);
    if1_aft:
    return 0;
}

double polyval(const double *a, int n, double x)
{
    double result = a[n];
    int i;
    for (i = n - 1; i >= 0; i--) {
        result *= x;
        result += a[i];
    }
    return result;
}