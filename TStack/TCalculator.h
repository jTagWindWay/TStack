#include <string>
#include <iostream>
#include "TStack.h"

class TCalculator{
	string infix, postfix;
	int priority(char ch);
	TStack <char> stc;
public:
	void toPostfix();
	double Calc();
};