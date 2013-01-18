#ifndef FACTORIAL_H
#define FACTORIAL_H

unsigned int factorial(const unsigned int x)
{
    if(x == 0 || x == 1) return 1;
    return x * factorial( x - 1 );
}

#endif // FACTORIAL_H
