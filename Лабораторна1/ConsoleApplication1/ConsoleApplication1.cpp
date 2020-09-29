// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include <time.h>
#include <algorithm> //на всякий случай пусть будет. ни на что вроде не влияет
#include <conio.h> //я люблю гетч. Потом заменю на системпауз
using namespace std;
struct bignum
{
	int* num;
	int length = 1;
};

bignum cnum16 (string num16, bignum n16);
bignum operator+ (bignum a1, bignum a2);
bignum operator- (bignum a1, bignum a2);
bignum operator* (bignum a1, int a);
bignum operator* (bignum a1, bignum a2);
bignum operator^ (bignum a1, bignum a2);
bignum kvadrat (bignum a1);
bignum operator/ (bignum a1, bignum a2);
bignum zero_one(short a);
bignum uborka(bignum a1);
int bigger(bignum a1, bignum a2);
int* boolform(bignum a2);
void cout16(bignum a);
void oldi(bignum a1);
using namespace std;


int main()
{
	string num16, num16_2;
	bignum num1, num2, num3;
	clock_t start, finish;
	double d;
	int l=0;
	char a;
	cout << "Welcome to our first laboratorna robota!"<<endl;
	cout << "================================================" << endl;
	bool quit = 0;
	while (quit == 0)
	{
		cout << "Select your operation" << endl;
		cout << "================================================" << endl;
		cout << "[+] - addition" << endl;
		cout << "[-] - subtraction" << endl;
		cout << "[*] - multiplication" << endl;
		cout << "[/] - division" << endl;
		cout << "[^] - exponentiation" << endl;
		cout << "[0] - 16 to 2" << endl;
		cout << "[s] - starsha stepen (starsha ediniza)" << endl;
		cout << "[c] - check" << endl;
		cout << "[q] - quit" << endl;
		cout << "================================================" << endl;
		cin >> a;
		cout << "================================================" << endl;
		switch (a)
		{
		case '+': 
		{cout << "Great choice! Enter 2 numbers" << endl; 
		cin >> num16;
		cin >> num16_2;
		num1 = cnum16(num16, num1);
		num2 = cnum16(num16_2, num2);
		start = clock();
		num3 = num1 + num2;
		finish = clock();
		cout << "result = "; cout16(num3); cout << endl;
		d = ((double)(finish)-(double)(start)) * 1000000000 / CLOCKS_PER_SEC;
		cout << endl << "time=" << d << " nanoseconds" << endl;
		break;
		}
		case '-':
		{
			cout << "Great choice! Enter 2 numbers" << endl;
		cin >> num16;
		cin >> num16_2;
		num1 = cnum16(num16, num1);
		num2 = cnum16(num16_2, num2);
		start = clock();
		num3 = num1 - num2;
		finish = clock();
		cout << "result = "; cout16(num3); cout << endl;
		d = ((double)(finish)-(double)(start)) * 1000000000 / CLOCKS_PER_SEC;
		cout << endl << "time=" << d << " nanoseconds" << endl;
		break;
		}
		case '*':
		{cout << "Great choice! Enter 2 numbers" << endl;
		cin >> num16;
		cin >> num16_2;
		num1 = cnum16(num16, num1);
		num2 = cnum16(num16_2, num2);
		start = clock();
		num3 = num1 * num2;
		finish = clock();
		cout << "result = "; cout16(num3); cout << endl;
		d = ((double)(finish)-(double)(start)) * 1000000000 / CLOCKS_PER_SEC;
		cout << endl << "time=" << d << " nanoseconds" << endl;
		break; }
		case '/':
		{
		cout << "Great choice! Enter 2 numbers" << endl;
		cin >> num16;
		cin >> num16_2;
		num1 = cnum16(num16, num1);
		num2 = cnum16(num16_2, num2);
		start = clock();
		num3 = num1 / num2;
		finish = clock();
		cout << "result = "; cout16(num3); cout << endl;
		d = ((double)(finish)-(double)(start)) * 1000000000 / CLOCKS_PER_SEC;
		cout << endl << "time=" << d << " nanoseconds" << endl;
		break; 
		}
		case '^':
		{
			cout << "Great choice! Enter 2 numbers" << endl;
			cin >> num16;
			cin >> num16_2;
			num1 = cnum16(num16, num1);
			num2 = cnum16(num16_2, num2);
			start = clock();
			num3 = num1 ^ num2;
			finish = clock();
			cout << "result = "; cout16(num3); cout << endl;
			d = ((double)(finish)-(double)(start))*1000000000 / CLOCKS_PER_SEC;
			cout << endl << "time=" << d << " nanoseconds" << endl;
			break;
		}
		case '0':
		{
			cout << "Great choice! Enter 1 number" << endl;
			cin >> num16;
			num3 = cnum16(num16, num3);
			int* b = boolform(num3);
			for (int i = 0; i < 4 * num16.length(); i++)
			{
				cout << b[i];
			}
			cout << endl;
			break;
		}
		case 's':
		{
			cout << "Great choice! Enter 1 number" << endl;
			cin >> num16;
			num3 = cnum16(num16, num3);
			oldi(num3);
			cout << endl;
			break;
		}
		case 'c':
		{
		cout << "Great choice! Enter 3 numbers and 1 int number" << endl;
		cin >> num16;
		cin >> num16_2;
		string num_c;
		cin >> num_c;
		int n;
		cin >> n;
		num1 = cnum16(num16, num1);
		num2 = cnum16(num16_2, num2);
		bignum num4 = cnum16(num_c, num2);
		num3 = (num1 + num2) * num4;
		cout << "result of (a+b)c = "; cout16(num3); cout << endl;
		num3 = (num1 * num4) + (num2 * num4);
		cout << "result of a*c + b*c = "; cout16(num3); cout << endl;
		num3 = num1 * n;
		cout << "result of a*n = "; cout16(num3); cout << endl;
		num3 = num1;
		for (int i = 0; i<n-1; i++)
		{
			num3 = num3 + num1;
		}
		cout << "result of a+a+... = "; cout16(num3); cout << endl;
		break;
		}
		case 'q':
		{
			cout << "bye c:" << endl;
			quit = 1;
			break;
		}
		default: {cout<<"please, stop trying to break this lab. It is already on kostilyah."<<endl; break; }

		}
		if (quit == 0)
		{
			cout << "================================================" << endl;
			cout << "Hotite result in booleva forma?" << endl;
			cout << "================================================" << endl;
			cout << "[+] - Yes." << endl;
			cout << "[-] - No." << endl;
			cout << "================================================" << endl;
			cin >> a;
			cout << "================================================" << endl;
			switch (a)
			{
			case '+':
			{
				cout << "Great choice!" << endl;
				int* b = boolform(num3);
				for (int i = 0; i < 4 * num3.length; i++)
				{
					cout << b[i];
				}
				cout << endl;
				break;
			}
			case '-':
			{
				cout << "Okhey." << endl;
				break;
			}
			default: {cout << "please, stop trying to break this lab. It is already on kostilyah."<<endl; break; }
			}
		}
	}
	_getch();
}
bignum kvadrat(bignum a1)
{
	a1 = a1 * a1;
	return a1;
}
void oldi(bignum a1)  //старшая степень
{
	int* b = boolform(a1);
	int k=(a1.length)*4-1;
	while (b[k]==0)
	{
		k--;
	}
	cout << "starsha stepin:= " << k+1 << endl;
}
int * boolform(bignum a2) //что-бы вернуть массив
{
	int* bool_a2 = new int[a2.length * 4];  //строка в булевом представлении
	int ostacha;
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
	return (bool_a2);
}
bignum uborka(bignum a1) //убирает лишнии нули перед числом
{
	int k = a1.length;
	bignum a3;
	while (a1.num[k - 1] == 0)
	{
		k = k - 1;
	}
	if (k == 0) { k = 1; }
	a3.length = k;
	a3.num = new int[a3.length];
	for (int i = 0; i < a3.length; i++)
	{
		a3.num[i] = a1.num[i];
	}
	delete[] a1.num;
	return a3;
}
bignum operator/ (bignum a1, bignum a2)
{
	int t;
	int k = a2.length;
	bignum r, temp;
	r.length = a1.length;
	r.num = new int[r.length];
	for (int i =0; i<r.length; i++)
	{
		r.num[i] = a1.num[i];
	}
	bignum q = zero_one(0);
	bignum two = zero_one(2);
	bignum to = zero_one(1);
	while (bigger(r, a2) >= 0)
	{
		t = r.length;
		temp.length = a2.length+(t-k);
		temp.num = new int[temp.length];
		for (int j = 0; j < temp.length; j++)
		{
			temp.num[j] = 0;
		}
		for (int j = 0; j < temp.length-t+k; j++)
		{
			temp.num[j+t-k] = a2.num[j];
		}
		if ((bigger(r, temp) == -1)&&(t-k>=0))
		{
			delete[] temp.num;
			t = t - 1;
			temp.length = a2.length + (t - k);
			temp.num = new int[temp.length];
			for (int j = 0; j < temp.length; j++)
			{
				temp.num[j] = 0;
			}
			for (int j = 0; j < temp.length - t + k; j++)
			{
				temp.num[j + t - k] = a2.num[j];
			}
		}
					//это на всякий случай, ибо иногда у меня остача на 1 раз больше отнимается
		r = r - temp;
		q = q + (two ^ (to * (t - k) * 4));
		
	}
	cout << "ostacha: = ";
	cout16(r);
	cout << endl;
	return (q);
}
bignum zero_one(short a)
{
	bignum a3;
	a3.num = new int[a3.length];
	a3.num[0] = a;
	return a3;
}

bignum operator^ (bignum a1, bignum a2)
{
	bignum a3;
	a3.length = a1.length;
	a3.num = new int[a3.length];
	a3.num[0] = 1;
	for (int i = 1; i<a3.length; i++)
	{
		a3.num[i] = 0;
	}
	int* bool_a2 = boolform(a2);
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
		delete[] temp.num;
	}
	/*int k = a3.length;
	while (a3.num[k - 1] == 0) //в процессе оптимизация затраченной памяти
	{
		
	}*/
	a3 = uborka(a3);
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
	a3 = uborka(a3);
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
				if (a1.num[i] > a2.num[i]) { b = 1;}
				if (a2.num[i] > a1.num[i]) { b = -1;}
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
		int i = a1.length - 1;
		while (a1.num[i] == a2.num[i]) //нахожу старший бит в котором есть отличия
		{
			i--;
		}
		if (i < 0) { i=0; }
		if (a1.num[i] >= a2.num[i])
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
	a3 = uborka(a3);
	return a3;
}

void cout16(bignum a) //вывод
{
	int k = a.length-1;
	/*while (a.num[k]==0)  больше не нужно, спасибо уборке, но оставлю тут на память
	{
		k--;
	}*/
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
		default: {cout << a.num[i]; break; }
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
