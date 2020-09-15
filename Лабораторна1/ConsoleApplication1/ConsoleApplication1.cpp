// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include <algorithm> //я не хочу по ифу элсу или тернарной операции на каждое сравнение двух чисел писать
#include <conio.h> //я люблю гетч. Потом заменю на системпауз
using namespace std;
struct bignum
{
	int* num;
	int length = 0;
};

bignum cnum16 (string num16, bignum n16);
bignum operator+ (bignum a1, bignum a2);
void cout16(bignum a);
using namespace std;

int main()
{
	string num16, num16_2;
	int l=0;	
	cin >> num16;
	cin >> num16_2;
	bignum num1, num2;
	num1 = cnum16(num16, num1);
	num2 = cnum16(num16_2, num2);
	bignum num3 = num1 + num2;
	cout16(num3);

	_getch();
}

void cout16(bignum a)
{
	for (int i = 0; i < a.length; i++)
	{
		switch (a.num[i])
		{
		case 1: {cout<<"1"; break; }
		case 2: {cout << "2"; break; }
		case 3: {cout << "3"; break; }
		case 4: {cout << "4"; break; }
		case 5: {cout << "5"; break; }
		case 6: {cout << "6"; break; }
		case 7: {cout << "7"; break; }
		case 8: {cout << "8"; break; }
		case 9: {cout << "9"; break; }
		case 0: {cout << "0"; break; }
		case 10: {cout << "A"; break; }
		case 11: {cout << "B"; break; }
		case 12: {cout << "C"; break; }
		case 13: {cout << "D"; break; }
		case 14: {cout << "E"; break; }
		case 15: {cout << "F"; break; }		
		default: {cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"; break; }
		}
	}
}

bignum operator+ (bignum a1, bignum a2)
{
	bignum a3;
	int l_max = max(a1.length, a2.length);
	a3.length = l_max + 1;
	a3.num = new int[a3.length];
	int l_min=min(a1.length, a2.length);
	for (int i = 0; i <a3.length; i++) { a3.num[i] = 0; }
	for (int i = l_max - 1; i > l_min-2; i--)
	{
		a3.num[i+1] = a1.num[i] + a2.num[i] + a3.num[i+1];
		if (a3.num[i+1] >= 16) { a3.num[i+1] = a3.num[i+1] - 16; a3.num[i]++; }
	}
	for (int i = l_min-2; i >= 0; i--)
	{
		a3.num[i+1] = a3.num[i+1] + a2.num[i];
		if (a3.num[i+1] >= 16) { a3.num[i+1] = a3.num[i+1] - 16; a3.num[i]++; }
	}
	return a3;
};

bignum cnum16(string a, bignum n16)
{
	n16.length = a.length();
	n16.num = new int[n16.length];
	for (int i = 0; i < n16.length; i++)
	{
		switch (a[n16.length - i - 1])
		{
		case '1': {n16.num[i] = 1; break; }
		case '2': {n16.num[i] = 2; break; }
		case '3': {n16.num[i] = 3; break; }
		case '4': {n16.num[i] = 4; break; }
		case '5': {n16.num[i] = 5; break; }
		case '6': {n16.num[i] = 6; break; }
		case '7': {n16.num[i] = 7; break; }
		case '8': {n16.num[i] = 8; break; }
		case '9': {n16.num[i] = 9; break; }
		case '0': {n16.num[i] = 0; break; }
		case 'A': {n16.num[i] = 10; break; }
		case 'B': {n16.num[i] = 11; break; }
		case 'C': {n16.num[i] = 12; break; }
		case 'D': {n16.num[i] = 13; break; }
		case 'E': {n16.num[i] = 14; break; }
		case 'F': {n16.num[i] = 15; break; }
		default: {cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"; break; }
		}
	}
	return n16;
};
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
