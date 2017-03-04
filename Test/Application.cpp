#include <iostream>
#include <memory>
#include <conio.h>
#include <thread>
#include "stdio.h"


int foo()
{
    return 5;
}
 
int goo()
{
    return 6;
}
 
int main()
{
	int (*fcnPtr)() = foo;
	fcnPtr = goo;
 
    return 0;
}