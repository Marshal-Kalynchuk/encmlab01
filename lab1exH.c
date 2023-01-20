// lab1exH.c
// ENCM 369 Winter 2023 Lab 1 Exercise H

#include <stdio.h>

void print_array(const char *str, const int *a, int n);
// Prints the string given by str on stdout, then
// prints a[0], a[1], ..., a[n - 1] on stdout on a single line.

void sort_array(int *x, int n);
// Sorts x[0], x[1], ..., x[n - 1] from smallest to largest.

int main(void)
{
  int test_array[] = { 4000, 5000, 7000, 1000, 3000, 4000, 2000, 6000 };

  print_array("before sorting ...", test_array, 8);
  sort_array(test_array, 8);
  print_array("after sorting ...", test_array, 8);
  return 0;
}

void print_array(const char *str, const int *a, int n)
{
  int i = 0;
  puts(str);
  lp1_sta:
  if (i >= n) goto lp1_aft;
  printf("    %d", a[i]);
  i++;
  goto lp1_sta;
  lp1_aft:
  printf("\n");
}

void sort_array(int *x, int n)
{
  // This is an implementation of an algorithm called insertion sort.

  int outer, inner, vti;
  lp1_sta:
    if (outer >= n) goto lp1_aft;

    vti = x[outer];
    inner = outer;

    lp1_lp1_sta:
    if (inner <= 0) goto lp1_lp1_aft;
    if (vti >= x[inner - 1]) goto lp1_lp1_aft;
    x[inner] = x[inner - 1];
    inner--;
    goto lp1_lp1_sta;
    lp1_lp1_aft:


    x[inner] = vti;
    outer++;
    goto lp1_sta;
  lp1_aft:
}
