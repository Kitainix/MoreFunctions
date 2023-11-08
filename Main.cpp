#include <iostream>

int NUM; // Глобальная перменная.
const double PI = 3.14; // Глобальная константа.
const int SIZE = 5; // Глобальная константа.
int ARR[SIZE]; // Глобальный массив.

void num_inc() {
	NUM++;
}
void func() {
	static int a = 0; // Статическая переменная, которая не удаляется при завершении работы программы. Создаётся один едниственный раз. 
	a++;
	std::cout << a << std::endl;
	if (a % 5 == 0)
		std::cout << "---\n";
}
int power(int num1, int num2 = 2) {
	int result = 1;
	for (int i = 1; i <= num2; i++)
		result *= num1;
	return result;
}
inline double absolute(double num) {
	return (num < 0.0 ? -num : num);
}
int max(int num1, int num2) {
	std::cout << "TWO INTS\n";
	return num1 > num2 ? num1 : num2;
}
double max(double num1, double num2) {
	std::cout << "TWO DOUBLES\n";
	return num1 > num2 ? num1 : num2;
}
char max(char sym1, char sym2) {
	std::cout << "TWO CHARS\n";
	return sym1 > sym2 ? sym1 : sym2;
}
int max(int num1, int num2, int num3) {
	std::cout << "THREE INTS\n";
	return num1 > max(num2, num3) ? num1 : max(num2, num3);
}
template <typename T>
void print_arr(T arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Области видимости данных.
	
	std::cout << NUM << std::endl;
	num_inc();
	std::cout << NUM << std::endl;
	std::cout << "PI = " << PI << std::endl;

	for (int i = 0; i < 15; i++)
		func();
	

	// Параметры по умолчанию.
	
	std::cout << "5^3 = " << power(5, 3) << std::endl;
	std::cout << "7^2 = " << power(7) << std::endl;
	std::cout << "4^4 = " << power(4, 4) << std::endl;
	std::cout << "11^2 = " << power(11) << std::endl;
	

	// Встраиваемая функция.
	
	std::cout << "Введите число: ";
	std::cin >> n;
	std::cout << '|' << n << "| = " << absolute(n) << std::endl;
	

	// Перегруженная функция.
	
	std::cout << max(5, 7) << std::endl;
	std::cout << max(1.3, 1.03) << std::endl;
	std::cout << max('k', 'K') << std::endl;
	std::cout << max(5, 7, 4) << std::endl;
	

	// Шаблонная функция.

	const int size = 5;
	int arr[size]{ 10, 20, 30, 40, 50 };
	std::cout << "Массив:\n";
	print_arr(arr, size);

	return 0;
}