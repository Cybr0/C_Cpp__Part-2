#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double plus_f(double a, double b){
	return a + b;
}

double minus_f(double a, double b){
	return a - b;
}

double multiplication_f(double a, double b){
	return a * b;
}

double division_f(double a, double b){
	return a / b;
}

int main(int argc, char** argv) {
	setlocale (LC_ALL, "RUS");
	double (* arr[4])(double, double) = {plus_f, minus_f, multiplication_f, division_f};
	double a = 9, b = 2, c = 0;
	
	cout << "У Вас есть 2 числа - a и b." << endl
		<< "Введите a: ";
		cin >> a;
	cout << "Введите b: ";
		cin >> b;
	cout << "Выберете желаемое действие:" << endl
		<< "1.Плюс\n"
		<< "2.Минус\n"
		<< "3.Умножение\n"
		<< "4.Деление\n>";
	int choose = 0;
	cin >> choose;
	c = arr[choose-1](a,b);
	cout << "Ответ: " << c;
	return 0;
}
