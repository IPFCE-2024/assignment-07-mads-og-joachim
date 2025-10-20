#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "taylor_sine.h"

static double fac(double x, int n);
static double pot(double x, int n);

double taylor_sine(double x, int n) {
    assert(n < 170); // Precondition
    double result = x; // First term in the series is x
    for (int i = 1; i < n; i++)
    {
        double sign = (i % 2) ? -1.0 : 1.0;
        result += sign * pow(x,2*i+1) / tgamma(2*i+2);
    }
    
    return result; 
}

/*
Used to use my own function for potense and factorial 
but discovered a bug with using static variable when 
calling with same x so swapped to the math.h functions
for more robust implementation.

Test
*/