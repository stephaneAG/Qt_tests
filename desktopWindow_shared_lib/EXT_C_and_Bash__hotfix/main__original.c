/* main.c - using the shared Xlib Desktop/Root Window hack library - by StephaneAG - 2013  */
/* this ile is a driver program that uses our library */

#include <stdio.h>
#include "desktopwindow.h" // we include our library

int main(void)
{
	puts("This is a shared library test ...");
	foo();
	return 0;
}
