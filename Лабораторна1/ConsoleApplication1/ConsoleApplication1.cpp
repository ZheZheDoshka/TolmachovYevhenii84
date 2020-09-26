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
bignum operator- (bignum a1, bignum a2);
bignum operator* (bignum a1, int a);
bignum operator* (bignum a1, bignum a2);
bignum operator^ (bignum a1, bignum a2);
bignum kvadrat (bignum a1);
int bigger(bignum a1, bignum a2);
void cout16(bignum a);
using namespace std;

int main()
{
	string num16, num16_2;
	int l=0;	
	cin >> num16;
	cin >> num16_2;
	bignum num1, num2, num3;
	num1 = cnum16(num16, num1);
	num2 = cnum16(num16_2, num2);
	/*bignum num3 = num1 - num2;*/
	num3 = num1^num2;
	cout16(num3);
	_getch();
}
bignum kvadrat(bignum a1)
{
	a1 = a1 * a1;
	return a1;
}

bignum operator^ (bignum a1, bignum a2)
{
	int* bool_a2 = new int[a2.length *4];  //строка в булевом представлении
	int ostacha;
	bignum a3;
	a3.length = a1.length;
	a3.num = new int[a3.length];
	a3.num[0] = 1;
	for (int i = 1; i<a3.length; i++)
	{
		a3.num[i] = 0;
	}
	for (int i = 0; i < a2.length; i++)
	{
		ostacha = a2.num[i];  //почти использовал pow
		bool_a2[4 * i] = ostacha % 2;
		ostacha = ostacha / 2;
		bool_a2[4 * i + 1] = ostacha % 2;
		ostacha = ostacha / 2;
		bool_a2[4 * i + 2] = ostacha % 2;
		ostacha = ostacha / 2;
		bool_a2[4 * i + 3] = ostacha % 2;
		ostacha = ostacha / 2;
	}
	for (int i = a2.length * 4 - 1; i >= 0; i--)
	{
		cout << bool_a2[i];
	}
	for (int i = 0; i < a2.length*4; i++)
	{
		if (bool_a2[a2.length * 4 - i] == 1) { a3 = a3 * a1; }
		a3 = kvadrat(a3);
	}
	if (bool_a2[0] == 1) {a3 = a3 * a1;}
	return (a3);
}

bignum operator* (bignum a1, int a)  //умножаю на инт
{
	bignum a3;
	a3.length = a1.length + 1;
	a3.num = new int[a3.length];
	a3.num[a3.length-1] = 0;
	for (int i = 0; i < a1.length; i++) { a3.num[i] = a1.num[i]*a; }
	for (int i = 0; i < a3.length-1; i++) 
	{ 
		while (a3.num[i] >= 16) { a3.num[i] = a3.num[i] - 16; a3.num[i + 1]++; }
	}
	return a3;
}
bignum operator* (bignum a1, bignum a2) //умножаю
{
	bignum a3, temp;
	a3.length = a1.length + a2.length;
	a3.num = new int[a3.length];
	for (int i = 0; i < a3.length; i++)
	{
		a3.num[i] = 0;
	}
	for (int i = 0; i < a2.length; i++) //в этой функции по сути добавляю то же умножение но на порядок выше. По аналогии с
	{								//десятиричным исчислением типо 15*12 = 15*2 + 150*1 (я его даже в тетрадку записал когда придумать пытался)
		temp.length = a1.length + i;
		temp.num = new int[temp.length];
		for (int j = 0; j < temp.length; j++)
		{
			temp.num[j] = 0;
		}
		for (int j = 0; j < a1.length; j++)
		{
			temp.num[j+i] = a1.num[j];
		}
		a3 = a3 + (temp * a2.num[i]); //вот тут эти самые 15*2 и 150*1 и их сумма и происходят
	}
	return a3;
}
bignum operator+ (bignum a1, bignum a2)  //суммирую
{
	bignum a3;
	int l_max, l_min;
	if (a1.length >= a2.length) {l_max = a1.length; l_min = a2.length; } 
	else {l_max = a2.length; l_min = a1.length; }
	a3.length = l_max + 1;
	a3.num = new int[a3.length];
	a3.num[l_max] = 0;
	if (a1.length >= a2.length)
	{
		for (int i = 0; i < a1.length; i++) { a3.num[i] = a1.num[i]; }
		for (int i = 0; i < a2.length; i++) { a3.num[i] = a3.num[i] + a2.num[i];}
	}
	else
	{
		for (int i = 0; i < a2.length; i++) { a3.num[i] = a2.num[i]; }
		for (int i = 0; i < a1.length; i++) { a3.num[i] = a3.num[i] + a1.num[i]; }
	}
	for (int i = 0; i < a3.length; i++) { if (a3.num[i] >= 16) { a3.num[i] = a3.num[i] - 16; a3.num[i + 1]++; } }
	return a3;
}
int bigger(bignum a1, bignum a2) //сравниваю
{
	int b=0;
	if (a1.length > a2.length) { b = 1; }
	else
	{
		if (a2.length > a1.length) { b = -1; }
		else {
			int i = a1.length-1;
			while ((a1.num[i] == a2.num[i])&&(i>0))
				{
					i--;
				}
			if (a1.num[i] == a2.num[i]) { b = 0; }
			else {
				if (a1.num[i] > a2.num[i]) { b = 1; }
				if (a2.num[i] > a1.num[i]) { b = -1; }
			}
			}
	}
	return b;
}

bignum operator- (bignum a1, bignum a2) //отнимание
{
	bignum a3;
	if (a1.length > a2.length)
	{
		for (int i = 0; i < a2.length; i++) { a1.num[i] = a1.num[i] - a2.num[i]; }
		for (int i = 0; i < a1.length; i++) { if (a1.num[i] < 0) { a1.num[i] = a1.num[i]+16 ; a1.num[i + 1]--; } }
		a3 = a1;
	}
	if (a1.length < a2.length) //типо делаю вид что вычетание работает просто поменяв местами цифры
	{
		for (int i = 0; i < a1.length; i++) { a2.num[i] = a2.num[i] - a1.num[i]; }
		for (int i = 0; i < a2.length; i++) { if (a2.num[i] < 0) { a2.num[i] = a2.num[i] + 16; a2.num[i + 1]--; } }
		a3 = a2;
		cout << "-";
	}
	if (a1.length == a2.length)
	{
		int i = a1.length-1;
		while (a1.num[i]==a2.num[i]) //нахожу старший бит в котором есть отличия
		{
			i--;
		}
		if (a1.num[i] > a2.num[i])
		{
			for (int i = 0; i < a2.length; i++) { a1.num[i] = a1.num[i] - a2.num[i]; }
			for (int i = 0; i < a1.length; i++) { if (a1.num[i] < 0) { a1.num[i] = a1.num[i] + 16; a1.num[i + 1]--; } }
			a3 = a1;
		}
		else  //типо делаю вид что вычетание работает просто поменяв местами цифры
		{
			for (int i = 0; i < a1.length; i++) { a2.num[i] = a2.num[i] - a1.num[i]; }
			for (int i = 0; i < a2.length; i++) { if (a2.num[i] < 0) { a2.num[i] = a2.num[i] + 16; a2.num[i + 1]--; } }
			a3 = a2;
			cout << "-";
		}
	}
	return a3;
}

void cout16(bignum a) //вывод
{
	int k = a.length-1;
	while (a.num[k]==0)
	{
		k--;
	}
	for (int i = k; i >= 0; i--)
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

/*bignum operator+ (bignum a1, bignum a2)
{
	bignum a3;
	int l_max = max(a1.length, a2.length);
	a3.length = l_max + 1;
	a3.num = new int[a3.length];
	int l_min=min(a1.length, a2.length);
	for (int i = 0; i <a3.length; i++) { a3.num[i] = 0; }
	for (int i = l_max - 1; i > l_min-2; i--)
	{
		a3.num[i] = a1.num[i] + a2.num[i] + a3.num[i];
		if (a3.num[i] >= 16) { a3.num[i] = a3.num[i] - 16; a3.num[i-1]++; }
	}
	for (int i = l_min-2; i >= 1; i--)
	{
		a3.num[i] = a3.num[i] + a2.num[i];
		if (a3.num[i] >= 16) { a3.num[i] = a3.num[i] - 16; a3.num[i-1]++; }
	}
	a3.num[0] = a3.num[0] + a2.num[0];
	return a3;
};*/

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
