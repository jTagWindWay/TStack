#include "TCalculator.h"


void TCalculator::toPostfix(){
	stc.Clear();
	postfix = " ";
	string tmp = "(" + infix + ")";
}