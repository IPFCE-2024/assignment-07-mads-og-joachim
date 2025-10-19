#include <stdio.h>
#include <assert.h>
#include "taylor_sine.h"

static double fac(double x, int n);
static double pot(double x, int n);

double taylor_sine(double x, int n) {
    assert(n < 170); // Precondition
    double result = x; // First term in the series is x
    for (int i = 1; i < n; i++)
    {
        double sign = (i % 2) ? -1.0 : 1.0;
        result += sign * pot(x,2*i+1) / fac(x,2*i+1);
    }
    
    return result; 
}

double fac(double x,int n){
    static double result = 1;
    static int count = 1;
    static double last_x = 0.0;
    if (x != last_x) {
        result = 1.0;
        count = 1;
        last_x = x;
    }
    
    for (int i = count; i <= n; i++) 
    {
        result *= i;
        count++;
    }
    return result;
}

double pot(double x, int n){
    static double result = 1.0;
    static int count = 0;
    static double last_x = 0.0;
    if (x != last_x) {
        result = 1.0;
        count = 0;
        last_x = x;
    }

    for (int i = count; i < n; i++)
    {
        result = result * x;
        count++;
    }
    return result;
}
