#include <iostream>
#include "Calculator.h"
#include "Adder.h"
using namespace std;
void Calculator::Run() {
	cout << "�ΰ��� ���� �Է��Ͻÿ�: ";
	int a, b;
	Adder adder(a,b);
	cout << adder.Process() << endl;
}
