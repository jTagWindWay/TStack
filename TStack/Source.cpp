#include "TStack.h"
#include "TCalculator.h"
#include <iostream>
#include <string>

using namespace std;


int main() {
	
		TCalculator STR;
		try {
			STR.setInfix("(1+2)");
			STR.toPostfix();
			cout << STR.Calculation() << endl;
		}
	catch (int i) {
		if (i == 8) {
			cout << "Brackets error" << endl;
			cout << i << endl;
		}
	}
		return 1;
}