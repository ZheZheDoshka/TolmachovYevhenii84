// лабораторна3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	bool m[444];
	field()
	{
		for (int i = 0; i < 444; i++)
		{
			m[i] = 0;
		}
	}
};

field operator+(field a1, field a2);
field multiplication(field a1, field a2, field f);
field enter(field a1);
field zero();
field one();
field square(field a1, field f);
field exp(field a1, field f, int e);
field inttobool(int c);
void outbool(field a1);
field slavabitam(field a1, field f);//обратный
field trace(field a1, field f);
void in_x(field a1);
int main()
{
	int deg = 444;
	char a;
	field f;
	for (int i = 0; i < 444; i++)
	{
		f.m[i] = 0;
	}
	f.m[443] = 1;
	f.m[28] = 1;
	f.m[3] = 1;
	f.m[1] = 1;
	f.m[0] = 1;
	field num1, num2;
	field num3;
	char again;
	bool quit = 0;
	while (quit == 0)
	{
		cout << "Select your operation" << endl;
		cout << "================================================" << endl;
		cout << "[+] - addition" << endl;
		cout << "[*] - multiplication" << endl;
		cout << "[^] - exponentiation" << endl;
		cout << "[s] - square" << endl;
		cout << "[e] - obratniy" << endl;
		cout << "[1] - one" << endl;
		cout << "[0] - zero" << endl;
		cout << "[c] - check" << endl;
		cout << "[t] - trace" << endl;
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
			num3 = exp(num1, f, e);
			outbool(num3);
			break;
		}
		case 't':
		{
			cout << "Enter num" << endl;
			cout << "================================================" << endl;
			num1 = enter(num1);
			cout << "trace = " << endl;
			num3 = trace(num1, f);
			outbool(num3);
			break;
		}
		case 'c':
		{
			cout << "Enter d" << endl;
			cout << "================================================" << endl;
			num1 = enter(num1);
			cout << "d^(2^443 - 1) = " << endl;
			field a3 = slavabitam(num1, f);
			num3 = multiplication(a3, num1, f);
			outbool(num3);
			break;
		}
		case 'e':
		{
			cout << "Enter number" << endl;
			cout << "================================================" << endl;
			num1 = enter(num1);
			cout << "number^-1 = " << endl;
			num3 = slavabitam(num1, f);
			field a4 = multiplication(num3, num1, f);
			outbool(num3);
			cout << "================================================" << endl;
			cout << "num^-1 * num =" << endl;
			outbool(a4);
			break;
		}
		case '+':
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
		case '1':
		{
			cout << "Good. Behold: The One:" << endl;
			cout << "================================================" << endl;
			num3 = one();
			outbool(num3);
			break;
		}
		case '0':
		{
			cout << "Good. Behold: The Zero:" << endl;
			cout << "================================================" << endl;
			num3 = zero();
			outbool(num3);
			break;
		}
		case '*':
		{
			cout << "Enter first number" << endl;
			cout << "================================================" << endl;
			num1 = enter(num1);
			cout << "Enter second number" << endl;
			cout << "================================================" << endl;
			num2 = enter(num2);
			cout << "Multiplication:" << endl;			
			num3 = (multiplication(num1, num2, f));
			outbool(num3);
			break;
		}
		case 's':
		{
			cout << "Enter first number" << endl;
			cout << "================================================" << endl;
			num1 = enter(num1);
			cout << "The square is:" << endl;
			cout << "================================================" << endl;
			outbool(square(num1, f));
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
void in_x(field a1)
{
	int j=0;
	cout << "================================================" << endl;
	for (int i = 443; i > 0; i--)
	{
		if (a1.m[i] == 1)
		{
			j = i;
			break;
		}
	}
	cout << "x^" << j << " ";
	for (int i = j-1; i > 0; i--)
	{
		if (a1.m[i] == 1)
		{
			cout << "+ x^" << i << " ";
		}
	}
	if (a1.m[0] == 1)
	{
	cout << "+ 1";
	}
	cout<< endl;
	cout << "================================================" << endl;
}

field trace(field a1, field f)
{
	field a3=one();
	field a4;
	field a2;
	int j;
	for (int k = 1; k < 443; k++)
	{
		a2.m[k] = 1;
		a2.m[k - 1] = 0;
		for (int i = 443; i > 0; i--)
		{
			if (a2.m[i] == 1)
			{
				j = i;
				break;
			}
		}
		for (int i = j; i > 0; i--)
		{
			if (a2.m[i] == 1) { a3 = multiplication(a3, a1, f); }
			a3 = square(a3, f);
		}
		if (a2.m[0] == 1)
		{
			a3 = multiplication(a3, a1, f);
		}
		a4 = a4 + a3;
		a3 = one();
	}
	a4 = a4 + a1;
	return (a4);
}
field inttobool(int c)
{
	field a1;
	int i = 0;
	while (c!=0)
	{
		a1.m[i] = c % 2;
		i++;
		c = c / 2;
	}
	return (a1);
}
field slavabitam(field a1, field f) //обратный элемент. Слава битовому представлению. 
{
	field a3 = one();
	int j;
	field a2;
	for (int i = 1; i < 444; i++)
	{
		a2.m[i] = 1;
	}
	a2.m[0] = 0;
	a2.m[443] = 0;
	for (int i = 443; i > 0; i--)
	{
		if (a2.m[i] == 1)
		{
			j = i;
			break;
		}
	}
	for (int i = j; i > 0; i--)
	{
		if (a2.m[i] == 1) { a3 = multiplication(a3, a1, f); }
		a3 = square(a3, f);
	}
	if (a2.m[0] == 1)
	{
		a3 = multiplication(a3, a1, f);
	}

	return a3;
};
field exp(field a1, field f, int e)
{
	field a3=one();
	int j;
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
		if (a2.m[i] == 1) { a3 = multiplication(a3,a1,f); }
		a3 = square(a3, f);
	}
	if (a2.m[0] == 1)
	{
		a3 = multiplication(a3, a1, f);
	}

	return a3;
};
field square(field a1, field f)
{
	bool a[887];
	field a3;
	for (int i = 0; i < 887; i++)
	{
		a[i] = 0;
	}
	for (int i = 0; i < 444; i++)
	{
		a[2*i] = a1.m[i];
	}
	for (int i = 887; i > 443; i--)
	{
		if (a[i] == 1)
		{
			for (int j = 0; j < 444; j++)
			{
				a[j - 443 + i] = a[j - 443 + i] ^ f.m[j];
			}
		}
	}
	for (int i = 0; i < 444; i++)
	{
		a3.m[i] = a[i];
	}
	return a3;
};

field operator+(field a1, field a2)
{
	field a3;
	for (int i = 0; i < 444; i++)
	{
		a3.m[i] = a1.m[i] ^ a2.m[i]; //xor
	}
	return a3;
};
field multiplication(field a1, field a2, field f)
{
	/*field a3;
	delete[] a3.m;
	*(a3.m) = new bool[887];
	for (int i = 0; i < 887; i++)
	{
		a1.m[i] = 0;
	}

	*(a3.m) = new bool[887];*/
	bool a[887];
	field a3;
	for (int i = 0; i < 887; i++)
	{
		a[i] = 0;
	}
	for (int i = 0; i < 444; i++)
	{
		if (a1.m[i] == 1) {
			for (int j = 0; j < 444; j++)
			{
				a[j + i] = a[j + i] ^ a2.m[j];
			}
		}
	}
	for (int i = 887; i >= 443; i--)
	{
		if (a[i] == 1)
		{
			for (int j = 0; j < 444; j++)
			{
				a[j - 443 + i] = a[j - 443 + i]^ f.m[j];
			}
		}
	}
	for (int i = 0; i < 444; i++)
	{
		a3.m[i] = a[i];
	}
	return a3;
}

field one()
{
	field a1;
	for (int i = 0; i < 444; i++)
	{
		a1.m[i] = 0;
	}
	a1.m[0] = 1;
	return a1;
};

field zero()
{
	field a1;
	outbool(a1);
	return a1;
};

field enter(field a1)
{
	for (int i = 0; i < 444; i++)
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
			a1.m[a.length()-i-1] = 1;
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
	int j = 0;
	while ((a1.m[443 - j] == 0)&&(j<443))
	{
		j++;
	}
	cout << "================================================" << endl;
	for (int i = 0; i < 444-j; i++)
	{
		cout<<a1.m[443-i-j];
	}
	cout<<endl;
};
/*field createfield(field f)
{
	cin >>f.deg;
	f.fd = new bool*[f.deg];
	for (int i = 0; i<f.deg; i++)
}*/
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
