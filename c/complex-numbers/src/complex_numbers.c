#include <math.h>

#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
    complex_t c;
    c.imag = a.imag + b.imag;
    c.real = a.real + b.real;
    return c;
}

complex_t c_sub(complex_t a, complex_t b)
{
    complex_t c;
    c.imag = a.imag - b.imag;
    c.real = a.real - b.real;
    return c;
}

complex_t c_mul(complex_t a, complex_t b)
{
    complex_t c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

complex_t c_div(complex_t a, complex_t b)
{
    complex_t c;
    c.real = (a.real * b.real + a.imag * b.imag)/(b.real*b.real + b.imag*b.imag); 
    c.imag = (a.imag * b.real - a.real * b.imag)/(b.real*b.real + b.imag*b.imag);
    return c;
}

double c_abs(complex_t x)
{
    return sqrt(x.real*x.real + x.imag*x.imag);
}

complex_t c_conjugate(complex_t x)
{
    x.imag *= (-1);
    return x;
}

double c_real(complex_t x)
{
    return x.real;
}

double c_imag(complex_t x)
{
    return x.imag;
}

complex_t c_exp(complex_t x)
{
    complex_t c;
    c.real = exp(x.real)*cos(x.imag);
    c.imag = exp(x.real)*sin(x.imag);
    return c;
}
