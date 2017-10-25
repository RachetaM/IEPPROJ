#include<iostream>
#include<conio.h>
#include "Pin.h"
#include "outputpin.h"
#include "inputpin.h"
using namespace std;

int main()
{
	Pin x = Pin(3, 1);
	cout << x.getDirection();
	return 0;
}