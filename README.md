# TStack


Содержание

Цель	3
Постановка задачи	3
Используемые инструменты	3
Общая структура проекта	3
Подробное описание модуля TStack	4
Подробное описание модуля test	11
Результаты тестов	12
Графическое представление	15
Заключение	16


 
Цель
В рамках лабораторной работы ставится задача создать шаблонный класс TStack, работающий по принципу FILO. Используя класс TStack,  преобразовать стандартную инфиксную запись в польскую постфиксную. Создать калькулятор в графическом интерфейсе, работающий на основе постфиксной записи. 
Реализовать следующие операции в калькуляторе:
•	сложение/вычитание;
•	умножение
•	деление
•	возведение в степень
Постановка задачи
1.	Реализация шаблонного класса TStack  и его методов.
2.	Реализация класса TCalculator.
3.	Создание тестов для класса TStack.
4.	Создание тестов для класса TCalculator.
5.	Обеспечение работоспособности тестов.
6.	Создание Калькулятора в Windows form.

Используемые инструменты
•	Система контроля версий Git. 
•	Фреймворк для написания автоматических тестов Google Test. 
•	Среда разработки Microsoft Visual Studio 2015

Общая структура проекта
Структура проекта:
•	gtest — библиотека Google Test.
•	include — директория для размещения заголовочных файлов.
•	samples — директория для размещения тестового приложения.
•	sln — директория с файлами решений и проектов для VS 2008 и VS 2010, вложенные директории vc9 и vc10соответственно.
•	src — директория для размещения исходных кодов (cpp-файлы).
•	test — директория с модульными тестами и основным приложением, инициализирующим запуск тестов.
•	Служебные файлы
o	.gitignore — перечень расширений файлов, игнорируемых Git при добавлении файлов в репозиторий.
В решении содержатся следующие модули:
•	Модуль TStack, содержащий реализацию классов TStack и TCalculator (файлы ./TStack/TCalculator.h, .\TStack\TCalculator.cpp, ./TStack/TStack.h) 
•	Модуль test, содержащий тесты для классов TStack и TCalculator (файлы ./test/test_tstack.cpp, ./test/test_tcalculator.cpp).
•	Модуль  Calc, содержащий графическую реализацию калькулятора (файл ./Calc/MyForm.h).

Подробное описание модуля TStack
TStack.h– содержит в себе реализацию шаблонного класса TStack, работающий по принципу –первый-пришёл-последний-ушёл-

#include <string> - подключение библиотеки для работы со стандартными строками
#include <iostream> - подключение библиотеки ввода и вывода

using namespace std – используется пространство имеет std

const int MAX_VECTOR_SIZE = 100000000 – задали максимальный размер вектора
const int MAX_MATRIX_SIZE = 10000 – задали максимальный размер матрицы
Объявление класса TVector  и его поля
template <class T>  
class TStack {

объявление полей класса
private:

	int Size - размер стэка
	int MaxSize – максимальный размер стэка
	T *mas – массив шаблонных элементов 
Так как класс является шаблонным, то реализация методов находится в этом же файле.


Объявление методов класса TStack и их реализация
public:

Реализация конструктора по умолчанию, создаёт объект класса с максимальным размером 15, текущим размером 0. 

	TStack(int _MaxSize = 15) {
		MaxSize = _MaxSize;
		Size = 0;
		mas = new T[MaxSize];
	}


Реализация конструктора копирования. На вход константная ссылка на шаблонный элемент класса. В функции переопределяем свойства класса на текущее значение объекта.

	TStack(const TStack & ts) {
		MaxSize = ts.MaxSize;
		Size = ts.Size;
		mas = new T[ts.MaxSize];
		for (int i = 0; i < Size; i++) {
			mas[i] = ts.mas[i];
		}
	}


Реализация деструктора состоит в освобождении памяти занятой массивом mas.
	~TStack() {
		delete [] mas;
	}


Реализация проверки стэка на пустоту. Если текущий размер 0, то правда, иначе – ложь.
	bool isEmpty() {
		if (Size == 0)
		return true;
		else
			return false;
	}

Реализация проверки стэка на полноту. Если текущий размер равен максимальному размеру, то правда, иначе – ложь.
	bool isFull() {
		if (Size == MaxSize)
		return true;
		else
			return false;
	}


Реализация функции добавления элемента в стек. На вход шаблонный элемент. Проверяем стек на полноту, если стек не полный, то на место текущего размера в массиве mas записываем шаблонный элемент, и увеличиваем стек на единицу.

	void Push(T a) {
		if (isFull())   throw 1;
		mas[Size] = a;
		Size++;
	}


Реализация функции извлечения из стека. Проверяем функцию на пустоту, если она не пустая, то убавляем размер на 1 и извлекаем элемент из массива mas с позиции текущего размера.

	T Pop() {
		if (isEmpty())  throw  2;
			Size--;
			return mas[Size];
		
	}


Реализация функции доступа к верхнему элементу. Проверяем стек на пустоту, если он не пустой, то возвращаем элемент равный, текущий размер – 1.
	T Top()  {
		if (isEmpty())  throw 3;
		return mas[Size - 1];
	}
	

Реализация функции очистки стека. Делаем текущий размер равным нулю.
	void clearTStack() {
		Size = 0;
	}


TCalculator.h – содержит в себе объявление класса TCalculator, его поля, прототипы методов данного класса, а так же функцию приоритета операндов. 
#include "TStack.h" – подключение класса TStack

using namespace std – подключение пространства имён std

class TCalculator { - объявление класса 

	
	string postfix – строка содержащая постфиксную запись
	string infix – строка содержащая инфиксную запись
	TStack <char> stc – объект класса TStack  с элементами типа char
	TStack <double> stDc – объект класса TStack  с элементами типа double

Реализация функции приоритета. На вход символ. Для каждого нужного символа отводим свой приоритет, если похожего символа не обнаружено, то приоритет выходим из функции.

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


Объявление прототипов методов класса
public:
	void toPostfix() – функция преобразования из инфиксной записи в постфиксную
	double Calculation() – функция позволяющая находить значение по постфиксной записи
	void setInfix(const string ) – функция устанавливающая текущую строку infix
	bool Brackets(string) – функция проверяет на корректность количество скобок
	string GetPostfix() –  функция выводит строку, находящуюся в postfix
};


TCalculator.cpp – содержит в себе реализацию методов класса TCalculator
#include "TCalculator.h" – подключение прототипов методов класса
#include "TStack.h" – подключение класса TStack
#include <math.h> - подключение библиотеки математических функций


using namespace std – использование пространства имён std



Реализация функции преобразования из инфиксной записи в постфиксную. Очищаем текущую строку postfix и текущий стек stc. Создаём временную строку tmp и прибавляем в неё строку infix заключенную в скобки ( и ). Создаём цикл, в котором на каждой итерации будет проверяться символ, и если он удовлетворяет нужным условиям, то символ записывается в строку postfix, операнды добавляются в строку в соответствии с приоритетом, если приоритет текущего операнда ниже того, который находится в строке, то он добавляется в стек.

void TCalculator::toPostfix() {
	postfix = "";
	stc.clearTStack();  	string tmp = "(" + infix + ")";
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
		else if ((tmp[i] == '+') || (tmp[i] == '-') || (tmp[i] == '*') || (tmp[i] == '/') || (tmp[i] == '^') || (tmp[i] == 't') || (tmp[i] == 's') || (tmp[i] == 'c')) {    
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



Реализация функции считать.  Очищаем стек stDc, создаём переменные first, double, res. Проверяем текущую постфиксную запись на корректность ввода скобок функцией Brackets(string), если проверка пройдена, то в цикле для каждого операнда выполняем операцию с first и double, записывая результат операции в res. 

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
}


Реализация функции записать строку в infix. Очищаем текущий infix, проверяем на корректность записи скобок функцией Brackets(string), если запись корректна, то записываем в infix скобку ‘(‘, затем ‘0’ и пробел ‘ ‘. Затем по циклу записываем в infix элемент нужной строки, перед каждой открывающей скобочкой будем записывать ‘0’. В конце функции закрываем строку infix закрывающей скобочкой ‘)’.

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

Реализация функции проверяющей строку на корректность написания скобок.
На вход строка, создаём переменную Flag и приравниваем его к 0. В цикле, каждый раз, когда достигается открывающая скобка к переменной Flag прибавляется 1, если закрывающая, то из Flag вычитается 1. Если переменная Flag будет иметь отрицательное значение, то функция выдаёт ложь, т.к. закрывающая скобка будет стоять либо перед открывающей, либо их будет больше. Если в конце работы функции Flag равен 0, то возвращаем правду, иначе ложь.

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


Реализация функции которая показывает текущее значение строки postfix.
string TCalculator::GetPostfix() {
	return postfix;
}


Подробное описание модуля test

test_main.cpp –  запускает все тесты.
test_tstack.cpp  –  содержит тесты к классу TStack.
test_TCalculator.cpp –  содержит тесты к классу TCalculator.

Реализация тестов для класса TStack в test_tstack.cpp


#include "..\TStack\TStack.h" – подключение класса TStack

#include "gtest.h" – подключение фреймворка Google Test



Тест проверяет возможность создать стек положительного размера.

TEST(TStack, can_create_TStack_with_positive_length){
  ASSERT_NO_THROW(TStack<int> ts(3));                    
}                                                     

Тест проверяет возможность создать стек отрицательного размера.

TEST(TStack, can_create_TStack_with_negative_length){
	ASSERT_ANY_THROW(TStack<int> ts(-3));
}



Тест проверяет невозможность взятия элемента из пустого стека.

TEST(TStack, vzyatie_is_pustogo_TStack){
	TStack<int>ts(1);
	ASSERT_ANY_THROW(ts.Pop());
}


Тест проверяет верность функции получения верхнего элемента из стека.

TEST(TStack, vzyatie_verhnego_elementa_is_TStack){
	TStack<int>ts(2);
	ts.Push(1);
	ts.Push(2);
	ASSERT_EQ(ts.Top(),2);
}

Тест проверяет верность функции извлечение элемента из стека.

TEST(TStack, ubrat_verhniy_element_is_TStack){
	TStack<int>ts(2);
	ts.Push(1);
	ts.Push(2);
	ts.Pop();
	ASSERT_EQ(ts.Top(),1);
}


Тест на невозможность получения верхнего элемента из пустого стека.

TEST(TStack, vzyatie_verhnego_elementa_is_pystogo_TStack){
	TStack<int>ts(0);
	ASSERT_ANY_THROW(ts.Top());
}


Тест на невозможность извлечения элемента из пустого стека.

TEST(TStack, ybrat_element_is_pystogo_TStack){
	TStack<int>ts(0);
	ASSERT_ANY_THROW(ts.Pop());
}


Тест проверяет возможность создание нового стека, путём копирования исходного.

TEST(TStack, can_create_copied_TStack){
	TStack<int> m(5);
	ASSERT_NO_THROW(TStack<int> m1(m));
}

Тест проверяет на равенство два стека, где один получен путём копирования второго.

TEST(TStack, copied_TStack_is_equal_to_source_one){
	TStack <int> m(4);
	m.Push(1);
	TStack <int> m1(m);
	int a = m.Pop();
	int b = m1.Pop();
	EXPECT_EQ(a, b);
}
Тест на проверку того, что стек, созданный путём копирования другого имеет свою собственную память.

TEST(TStack, copied_TStack_has_its_own_memory){
	TStack<int> m1(4);
	m1.Push(1);
	m1.Push(2);
       TStack<int> m2(m1);
	EXPECT_FALSE(&m1 == &m2);
}



Реализация тестов для класса TCalculator в test_TCalculator.cpp


#include "..\TStack\TCalculator.h" – подключаем класс TCalculator
#include "..\TStack\TCalculator.cpp" – подключаем реализацию класса TCalculator

#include "gtest.h" – подключение фреймворка Google Test
#include <iostream> - подключение библиотеки ввода-вывода
 


Тест проверяет невозможность поместить в infix строку с неправильным набором скобок.

TEST(TCalculator, can_setInfix_with_non_equal_count_brakets_TCalculator){
	TCalculator TCR;
	ASSERT_ANY_THROW(TCR.setInfix(")((2+(2-3+1))"));
}


Тест проверяет возможность поместить в infix строку с правильным набором скобок.

TEST(TCalculator, can_setInfix_with_equal_count_brakets_TCalculator){
	TCalculator TCR;
	ASSERT_NO_THROW(TCR.setInfix("((2+(2-3+1)))"));
}


Тест проверяет возможность поместить в строку infix пустую строчку.

TEST(TCalculator, can_setInfix_void_TCalculator){
	TCalculator TCR;
	ASSERT_NO_THROW(TCR.setInfix(""));
}


Тест проверяет корректность работы функции по преобразованию infix в postfix

TEST(TCalculator, right_infix_to_postfix_TCalculator){
	TCalculator TCR;
	TCR.setInfix("3+2");
	TCR.toPostfix();
	string tmp;
	tmp = ("03 2+");
	ASSERT_EQ(TCR.GetPostfix(), tmp);
}


Тест проверяет возможность преобразования в постфикс пустой инфиксной строки.

TEST(TCalculator, can_toPostfix_empty_string_TCalculator){
	TCalculator TCR;
	TCR.setInfix("");
	ASSERT_NO_THROW( TCR.toPostfix());
}


Тест проверяет возможность преобразования в постфикс инфиксную строку с правильным набором скобок.

TEST(TCalculator, can_toPostfix_string_with_equal_brackets_TCalculator){
	TCalculator TCR;
	TCR.setInfix("(1+2+(3-4)+5)");
	ASSERT_NO_THROW(TCR.toPostfix());
}


Тест проверяет работу функции считать.

TEST(TCalculator, right_Calculation_TCalculator){
	TCalculator TCR;
	TCR.setInfix("3+2");
	TCR.toPostfix();
	ASSERT_EQ(TCR.Calculation(), 5);
}


Тест проверяет правильность выполнения сложения отрицательного и положительного числа, когда на первом месте стоит отрицательное.

TEST(TCalculator, right_otrizateliniy_Calculation_TCalculator){
	TCalculator TCR;
	TCR.setInfix("-3+2");
	TCR.toPostfix();
	ASSERT_EQ(TCR.Calculation(), -1);
}


Тест проверяет возможность считать с минусом перед скобкой.

TEST(TCalculator, minus_right_Calculation_TCalculator){
	TCalculator TCR;
	TCR.setInfix("-(-(2-(3+2)))");
	TCR.toPostfix();
	ASSERT_EQ(TCR.Calculation(), -3);
}


Тест проверяет невозможность привести к постфиксу инфиксную строку с верным количеством скобок, но неверной их расстановкой.

TEST(TCalculator, cant_toPostfix_string_with_equal_not_right_brackets_TCalculator){
	TCalculator TCR;
	TCR.setInfix(")(1+2+(3-4)+5");
	ASSERT_ANY_THROW(TCR.toPostfix());
}


Результаты тестов

 
Все созданные тесты пройдены.








Графическое представление
Создал форму, которая выглядит следующим образом:

 


Под надписью INFIX находится поле, в которое записывается исходное выражение.
Если нажать на кнопку “=”, то в поле RESULT запишется результат вычисления данного выражения, а в строку POSTFIX запишется результат преобразования инфиксной строки в постфиксную.
Записав выражение вида (3+6*(-7+1)/2)^2 в поле POSTFIX , верным ответом которого является число 225, и, нажав на кнопку “=”, получил следующее:
 


Заключение 
Выполнил поставленные задачи. Реализовал структуру хранения стек. Научился создавать тесты, на основе Google Test фреймворка, реализовал класс TCalculator, который можетпереводить инфиксные строки в постфиксные. Создал калькулятор на графическом интерфейсе, который считает выражения, записанные в постфиксной форме. Разместил программу на GitHub репозитории.

GitHub:  https://github.com/jTagWindWay/TStack.git

