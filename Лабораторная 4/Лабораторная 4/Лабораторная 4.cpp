// Лабораторная 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include <time.h>
#include <algorithm> //на всякий случай пусть будет. ни на что вроде не влияет
#include <conio.h> //я люблю гетч. Потом заменю на системпауз
using namespace std;
/*struct field
	{
	//	bool** fd;
		bool fd[][443];
		int deg;
		int mod = 2;
	};*/

struct field
{
	bool m[443];
	field()
	{
		for (int i = 0; i < 443; i++)
		{
			m[i] = 0;
		}
	}
};
struct matrix
{
	bool m[443][443];
	matrix()
	{
		for (int i = 0; i < 443; i++)
		{
			for (int j = 0; j < 443; j++)
			{
				m[i][j] = 0;
			}
		}
	}
};

field operator+(field a1, field a2);
field multiplication(field a1, field a2, matrix l);
field enter(field a1);
field zero();
field one();
field square(field a1);
field exp(field a1, matrix l, int e);
field inttobool(int c);
void outbool(field a1);
field slavabitam(field a1, matrix l);//обратный
int trace(field a1);
void in_x(field a1);
void checking();
int exp2(int a, int e);
int exp(int a, int e);
matrix mult();
field left(field a1);
int main()
{
	int deg = 444;
	char a;
	field f;
	for (int i = 0; i < 443; i++)
	{
		f.m[i] = 0;
	}
	f.m[442] = 1;
	f.m[28] = 1;
	f.m[3] = 1;
	f.m[1] = 1;
	f.m[0] = 1;
	field num1, num2;
	field num3;
	int tr;
	char again;
	checking();
	matrix l = mult();
	bool quit = 0;
	while (quit == 0)
	{
		cout << "Select your operation" << endl;
		cout << "================================================" << endl;
		cout << "[+] - addition" << endl; //done
		cout << "[*] - multiplication" << endl;//done
		cout << "[^] - exponentiation" << endl;//dpne
		cout << "[s] - square" << endl;//done
		cout << "[e] - obratniy" << endl;
		cout << "[1] - one" << endl; //done
		cout << "[0] - zero" << endl; //done
		cout << "[c] - check" << endl;
		cout << "[t] - trace" << endl;//done
		cout << "[q] - quit" << endl;
		cout << "================================================" << endl;
		cin >> a;
		cout << "================================================" << endl;
		switch (a)
		{
		case '^':
		{
			cout << "Enter first number" << endl;
			cout << "================================================" << endl;
			num1 = enter(num1);
			cout << "Enter int" << endl;
			cout << "================================================" << endl;
			int e;
			cin >> e;
			cout << "Exponent:" << endl;
			cout << "================================================" << endl;
			num3 = exp(num1, l, e);
			outbool(num3);
			break;
		}
		case 't':
		{
			cout << "Enter num" << endl;
			cout << "================================================" << endl;
			num1 = enter(num1);
			cout << "trace = "<< trace(num1) << endl;
			num3 = num1 + zero();
			break;
		}
		case 'c':
		{
			cout << "Enter d" << endl;
			cout << "================================================" << endl;
			num1 = enter(num1);
			cout << "d^(2^443 - 1) = " << endl;
			field a3 = slavabitam(num1, l);
			num3 = multiplication(a3, num1, l);
			outbool(num3);
			break;
		}
		case 'e':
		{
			cout << "Enter number" << endl;
			cout << "================================================" << endl;
			num1 = enter(num1);
			cout << "number^-1 = " << endl;
			num3 = slavabitam(num1, l);
			field a4 = multiplication(num3, num1, l);
			outbool(num3);
			cout << "================================================" << endl;
			cout << "num^-1 * num =" << endl;
			outbool(a4);
			break;
		}
		case '+': //done
		{
			cout << "Enter first number" << endl;
			cout << "================================================" << endl;
			num1 = enter(num1);
			cout << "Enter second number" << endl;
			cout << "================================================" << endl;
			num2 = enter(num2);
			cout << "The sum is:" << endl;
			cout << "================================================" << endl;
			num3 = num1 + num2;
			outbool(num3);
			break;
		}
		case '1'://done
		{
			cout << "Good. Behold: The One:" << endl;
			cout << "================================================" << endl;
			num3 = one();
			outbool(num3);
			break;
		}
		case '0'://done
		{
			cout << "Good. Behold: The Zero:" << endl;
			cout << "================================================" << endl;
			num3 = zero();
			outbool(num3);
			break;
		}
		case '*'://done
		{
			cout << "Enter first number" << endl;
			cout << "================================================" << endl;
			num1 = enter(num1);
			cout << "Enter second number" << endl;
			cout << "================================================" << endl;
			num2 = enter(num2);
			cout << "Multiplication:" << endl;
			num3=(multiplication(num1, num2, l));
			outbool(num3);
			break;
		}
		case 's'://done
		{
			cout << "Enter first number" << endl;
			cout << "================================================" << endl;
			num1 = enter(num1);
			cout << "The square is:" << endl;
			cout << "================================================" << endl;
			outbool(square(num1));
			break;
		}
		case 'q':
		{
			cout << "bye c:" << endl;
			quit = 1;
			break;
		}
		}
		if (quit == 0)
		{
			cout << "================================================" << endl;
			cout << "Hotite result in polinom forma?" << endl;
			cout << "================================================" << endl;
			cout << "[+] - Yes." << endl;
			cout << "[-] - No." << endl;
			cout << "================================================" << endl;
			cin >> again;
			cout << "================================================" << endl;
			switch (again)
			{
			case '+':
			{
				cout << "Great choice!" << endl;
				in_x(num3);
				break;
			}
			case '-':
			{
				cout << "Okhey." << endl;
				break;
			}
			default: {cout << "please, stop trying to break this lab. It is already on kostilyah." << endl; break; }
			}
		}
	}
	_getch();
};
void checking()
{
	cout << "================================================" << endl;
	cout << "m = 443" << endl;
	cout << "================================================" << endl;
	cout << "2m+1=p - ";
	int i = 1;
	while (443%i !=0)
	{
		i++;
		if (i > sqrt(433)) 
		{
			i = 0;
			break;
		}
	}
	if (i==0)
	{
		cout << "primitive" << endl;
	}
	else
	{
		cout << "non-primitive" << endl;
	}
	cout << "================================================" << endl;
	int k = 8;
	int r=10;
	while(r%443!=1)
	{
		k++;
		r = exp(2,k);
		r = r % 443;
	}
	cout << "2^k=1 mod 443, k = " << k << endl;
	if (k==442)
	{
		cout << "1. k=442 = 2m" << endl;
		cout << "E optimal basis" << endl;
	}
	else
	{
		if ((k == 221) && (443 % 4 == 3))
		{
			cout << "2. k=221 = m, 443 = 3mod4"<<endl;
			cout << "E optimal basis" << endl;
		}
		else
		{
			cout << "no optimal basis" << endl;
		}
	}

}

int exp(int a, int e)
{
	int j=0;
	int a3=1;
	field a2 = inttobool(e);
	for (int i = 444; i > 0; i--)
	{
		if (a2.m[i] == 1)
		{
			j = i;
			break;
		}
	}
	for (int i = j; i > 0; i--)
	{
		if (a2.m[i] == 1) { a3 = a3 * a; }
		a3 = a3 * a3;
		a3 = a3 % 443;
	}
	if (a2.m[0] == 1)
	{
		a3 =a3*a;
		a3 = a3 % 443;
	}

	return a3;
};

int exp2(int a, int e)
{
	int j = 0;
	int a3 = 1;
	field a2 = inttobool(e);
	for (int i = 444; i > 0; i--)
	{
		if (a2.m[i] == 1)
		{
			j = i;
			break;
		}
	}
	for (int i = j; i > 0; i--)
	{
		if (a2.m[i] == 1) { a3 = a3 * a; }
		a3 = a3 * a3;
		a3 = a3 % 887;
	}
	if (a2.m[0] == 1)
	{
		a3 = a3 * a;
		a3 = a3 % 887;
	}

	return a3;
};

void in_x(field a1)
{
	int j = 1;
	cout << "================================================" << endl;
	if (a1.m[0] == 1)
	{
		cout << "b +";
	}
	else
	{
		while (a1.m[j]==0)
		{
			j++;
		}
		cout << "b^2^"<<j;
	}
	for (int i = j+1; i < 443; i++)
	{
		if (a1.m[i] == 1)
		{
			cout << "+ b^2^" << i << " ";
		}
	}
	cout << endl;
	cout << "================================================" << endl;
}

int trace(field a1) //done
{
	int a4=0;
	for (int i = 0; i < 442; i++)
	{
		a4 = a4 + a1.m[i];
	}
	a4 = a4 % 2;
	return (a4);
}
field inttobool(int c)
{
	field a1;
	int i = 0;
	while (c != 0)
	{
		a1.m[i] = c % 2;
		i++;
		c = c / 2;
	}
	return (a1);
}
field slavabitam(field a1, matrix l) //обратный элемент. Слава битовому представлению.  //дописать завтра
{
	field a3 = one();
	field a2;
	for (int i = 442; i > 0; i--)
	{
		a2.m[i] = 1;
	}
	a2.m[0] = 0;
	for (int i = 442; i > 0; i--)
	{
		if (a2.m[i] == 1) { a3 = multiplication(a3, a1, l); }
		a3 = square(a3);
	}
	if (a2.m[0] == 1)
	{
		a3 = multiplication(a3, a1, l);
	}
	return a3;
};
field exp(field a1, matrix l, int e) //просто замените на field e тут и чуть выше, и будет для bignumbers
{
	field a3 = one();
	field a2 = inttobool(e);
	int j = 0;
	for (int i = 444; i > 0; i--)
	{
		if (a2.m[i] == 1)
		{
			j = i;
			break;
		}
	}
	for (int i = j; i > 0; i--)
	{
		if (a2.m[i] == 1) { a3 = multiplication(a3,a1, l); }
		a3 = square(a3);
	}
	if (a2.m[0] == 1)
	{
		a3 = multiplication(a3,a1, l);
	}
	return a3;
};
field square(field a1) //done
{
	field a3;
	for (int i = 0; i < 442; i++)
	{
		a3.m[i + 1] = a1.m[i];
	}
	a3.m[0] = a1.m[442];
	return a3;
};

field left(field a1) //done
{
	field a3;
	for (int i = 1; i < 443; i++)
	{
		a3.m[i - 1] = a1.m[i];
	}
	a3.m[442] = a1.m[0];
	return a3;
};

field operator+(field a1, field a2) //done
{
	field a3;
	for (int i = 0; i < 443; i++)
	{
		a3.m[i] = a1.m[i] ^ a2.m[i]; //xor
	}
	return a3;
};

field multiplication(field a1, field a2, matrix l) //done
{
	bool k;
	field a3;
	field a4;
	for (int r = 0; r < 443; r++) {
		for (int i = 0; i < 443; i++)
		{
			k = 0;
			for (int j = 0; j < 443; j++)
			{
				k = k ^ (a1.m[j] * l.m[j][i]);
			}
			a3.m[i] = k;
		}
		k = 0;
		for (int i = 0; i < 443; i++)
		{
				k = k ^ (a3.m[i] * a2.m[i]);
		}
		a4.m[r] = k;
		a1=left(a1);
		a2 = left(a2);
	}
	return a4;
}

field one() //done
{
	field a1;
	for (int i = 0; i < 443; i++)
	{
		a1.m[i] = 1;
	}
	return a1;
};

field zero()
{
	field a1;
	outbool(a1);
	return a1;
};

matrix mult() //done
{
	matrix l;
	for (int i = 0; i < 443; i++)
	{
		for (int j = 0; j < 443; j++)
		{
			if (((exp2(2, i) + exp2(2, j)) % 887) == 1)
			{
				l.m[i][j] = 1;
			}
			if (((exp2(2, i) - exp2(2, j) + 887) % 887) == 1)
			{
				l.m[i][j] = 1;
			}
			if (((-exp2(2, i) - exp2(2, j) + 887) % 887) == 1)
			{
				l.m[i][j] = 1;
			}
			if (((exp2(2, j) - exp2(2, i) + 887) % 887) == 1)
			{
				l.m[i][j] = 1;
			}
		}
	}
/*	for (int i = 0; i < 443; i++)
	{
		for (int j = 0; j < 443; j++)
		{
			cout << l.m[i][j];
		}
		cout << endl;
	}*/
	cout << "Matrix Lambda calculated" << endl;
	return l;
}

field enter(field a1)
{
	for (int i = 0; i < 443; i++)
	{
		a1.m[i] = 0;
	}
	string a;
	int q = 0;
	cout << "enter degree for line input" << endl;
	cout << "================================================" << endl;
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '1')
		{
			a1.m[i] = 1;
		}
	}
	outbool(a1);
	return a1;
};
/*
field enter(field a1)
{
	for (int i = 0; i < 444; i++)
	{
		a1.m[i] = 0;
	}
	int q = 0;
	cout << "enter degree for x to set +1, enter larger than 555 number to continue" << endl;
	cout << "================================================" << endl;
	while (q < 444)
	{
		cin >> q;
		a1.m[q] = a1.m[q] ^ 1; //otmena vvoda
	}
	outbool(a1);
	return a1;
};
*/

void outbool(field a1) //x^max  a_(max-1)*x^(max-1)... a_0*x^0
{
	/*int j = 0;
	while ((a1.m[443 - j] == 0) && (j < 443))
	{
		j++;
	}*/
	cout << "================================================" << endl;
	for (int i = 0; i < 443; i++)
	{
		cout << a1.m[i];
	}
	cout << endl;
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
