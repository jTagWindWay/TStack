#pragma once
#include <string>
#include "TStack.h"

using namespace std;

class TCalculator {

	
	string postfix;
	string infix;
	int priority(char ch) {
		switch (ch) {
		case '+': return 2; break;
		case '-': return 3; break;
		case '*': return 3; break;
		case '/': return 3; break;
		case '^': return 4; break;
		case '(': return 0; break;
		case ')': return 0; break;
		case 'c': return 1; break;
		case 't': return 1; break;
		case 's': return 1; break;
		}
		return -1;
	}
	TStack <char> stc;
	TStack <double> stDc;
public:
	void toPostfix();
	double Calculation();
	void setInfix(const string );
	bool Brackets(string);
	string GetPostfix();
};