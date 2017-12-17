#include "TCalculator.h"
#include "TStack.h"
#include <string>
#include <math.h>


using namespace std;

void TCalculator::toPostfix() {
	postfix = "";
	stc.clearTStack();   //проверить функцию clearTStack
	string tmp = "(" + infix + ")";
	for (unsigned int i = 0; i < tmp.size(); i++) {
		if ((tmp[i] >= '0') && (tmp[i] <= '9') || (tmp[i] == '.')) {
			postfix += tmp[i];
		}
		else if (tmp[i] == '(') {
			stc.Push('(');
		}

		else if (tmp[i] == ')') {
			while (stc.Top() != '(')           
				postfix += stc.Pop();
			stc.Pop();
		}
		else if ((tmp[i] == '+') || (tmp[i] == '-') || (tmp[i] == '*') || (tmp[i] == '/') || (tmp[i] == '^') || (tmp[i] == 't') || (tmp[i] == 's') || (tmp[i] == 'c')) {    //добавить операнды
			postfix += ' '; 
			if (priority(stc.Top()) < priority(tmp[i]))
				stc.Push(tmp[i]);
			else {
				while (priority(stc.Top()) >= priority(tmp[i]))
					postfix += stc.Pop();
				stc.Push(tmp[i]);
			}
		}
	}
}


double TCalculator::Calculation() {
	stDc.clearTStack();
	double first, second, res;
	if (Brackets(postfix) == false) throw 8;
	for (size_t i = 0; i < postfix.size(); i++) {
		if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == '/') || (postfix[i] == '^') || (postfix[i] == 'c') || (postfix[i] == 't') || (postfix[i] == 's'))
		{
			if (postfix[i] == 't') {
				if (stDc.isEmpty()) throw 4;
				first = stDc.Pop();
				res = tan(first);
				stDc.Push(res);
			}
			if (postfix[i] == 'c') {
				if (stDc.isEmpty()) throw 4;
				first = stDc.Pop();
				res = cos(first);
				stDc.Push(res);
			}
			if (postfix[i] == 's') {
				if (stDc.isEmpty()) throw 4;
				first = stDc.Pop();
				res = sin(first);
				stDc.Push(res);
			}
			if (stDc.isEmpty()) throw 4;
			second = stDc.Pop();
			if (stDc.isEmpty()) throw 4;
			first = stDc.Pop();
			switch (postfix[i]) {
			case'+':res = first + second; break;
			case'-':res = first - second; break;
			case'*':res = first * second; break;
			case'/':res = first / second; break;
			case'^':res = pow(first, second); break;
			}
			stDc.Push(res);
		}
		if ((postfix[i] >= '0') && (postfix[i] <= '9') || (postfix[i] == '.')) {
			char *tmp;
			res = strtod(&postfix[i], &tmp);
			stDc.Push(res);
			int g = tmp - &postfix[i];
			i += g - 1;
		}
	}
	if (stDc.isEmpty()){
		throw 6;
	}
	else{
		res = stDc.Pop();
	}
	if (!stDc.isEmpty()){
		throw 7;
	}
	return res;
	//return stDc.Pop();
}


void TCalculator::setInfix(const string str) {
	infix = "";	
	if (Brackets(str) == false) throw 8;
	infix += '(';
	infix += '0';
	infix += ' ';
	
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] != ' '){
			infix += str[i];
			if (str[i] == '(') {
				infix += '0';
		
			}
		}
	}
	infix += ')';
}


bool TCalculator::Brackets(string strc) {
	 int Flag = 0;
	for (size_t i = 0; i < strc.size(); i++) {
		if (strc[i] == '(') {
			Flag++;
		}
		if (strc[i] == ')') {
			Flag--;
			if (Flag < 0) return false;
		}
	}
	if (Flag == 0)
		return true;
	else 
		return false;
}

string TCalculator::GetPostfix() {
	return postfix;
}