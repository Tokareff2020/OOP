#define _CRT_SECURE_NO_WARNINGS
// Лаба по ОПП номер 2
//Создать класс Money для работы с денежными суммами. Сумма денег должна быть представлено двумя полями: типа unsigned long long для рублей и типа unsigned char – для копеек. Дробная часть (копейки) при выводе на экран должна быть отделена от целой части запятой. Реализовать сложение сумм, вычитание, деление сумм, деление суммы на дробное число, умножение на дробное число и операции сравнения.

#include <iostream>
using namespace std;

class Money {
private:
	unsigned long long roubles;
	unsigned char kopecks;
public:
	Money()
	{
		roubles = 0;
		kopecks = 0;
	}
	Money(unsigned long long a, unsigned char b)
	{
		roubles = a;
		kopecks = b;
	}
	Money input()
	{
		
		cout << "Enter your amount:";
		cin >> roubles;
		scanf("%hhu", &kopecks);
		if (roubles >= 0 && kopecks >= 0)
		{
			while (kopecks >= 100 && roubles >= 0)
			{
				cout << "Kopecks must be less then 100" << endl;
				cout << "Enter kopecks:";
				cin >> kopecks;
				cout << endl;
			}
			return Money(roubles, kopecks);
		}
		
		
	}
	void output()
	{
		if (kopecks < 10)
			printf("%llu,0%u roubles\n", roubles, kopecks);
		else 
			printf("%llu,%u roubles\n", roubles, kopecks);
		
	}
	Money operator + (const Money &b)
	{
		Money c(0, 0);
		int x = 100 * roubles + kopecks;
		int y = 100 * b.roubles + b.kopecks;
		int sum = x + y;
		c.roubles = sum / 100;
		c.kopecks = sum % 100;
		return c;
		
	}
	Money operator - (const Money& b)
	{
		Money c(0, 0);
		int x = 100 * roubles + kopecks;
		int y = 100 * b.roubles + b.kopecks;
		while (1)
		{
			if ((x - y) < 0)
			{
				cout << "Second amount more or amounts are equal" << endl;
				c.roubles = 0;
				c.kopecks = 0;
				return c;
				break;
			}
			else {
				int min = x - y;
				c.roubles = min / 100;
				c.kopecks = min % 100;
				return c;
				break;
			}
		}
	}
	Money operator * (const Money& b)
	{
		Money c(0, 0);
		int x = 100 * roubles + kopecks;
		int y = 100 * b.roubles + b.kopecks;
		int mult = (x * y) / 100;
		c.roubles = mult / 100;
		c.kopecks = mult % 100;
		return c;
	}
	Money operator / (const Money& b)
	{
		Money c(0, 0);
		int x = 100 * roubles + kopecks;
		int y = 100 * roubles + kopecks;
		while (1)
		{
			if (x / y == 0)
			{
				cout << "Your amount equal 0, enter other value";
				c.roubles = 0;
				c.kopecks = 0;
				return c;
				break;
			}
			else {
				int div = x / y;
				c.roubles = div / 100;
				c.kopecks = div % 100;
				return c;
				break;
			}
		}
	}
	Money operator / (double frac)
	{
		Money c(0, 0);
		double x = 100 * roubles + kopecks;
		if (frac == 0)
		{
			cout << "Your frac equal 0, enter other value" << endl;
			c.roubles = 0;
			c.kopecks = 0;
			return c;
		}
		else {
			int y = x / frac;
			c.roubles = y / 100;
			c.kopecks = y % 100;
			return c;
		}
	}
	Money operator * (double frac)
	{
		Money c(0, 0);
		double x = 100 * roubles + kopecks;
		int y = x * frac;
		c.roubles = y / 100;
		c.kopecks = y % 100;
		return c;
	}
	bool operator > (const Money& b)
	{
		int x = roubles * 100 + kopecks;
		int y = b.roubles * 100 + b.kopecks;
		if (x > y)
			return true;
		else
			return false;
	}
	bool operator == (const Money& b)
	{
		int x = roubles * 100 + kopecks;
		int y = b.roubles * 100 + b.kopecks;
		if (x == y)
			return true;
		else
			return false;
	}
	bool operator < (const Money& b)
	{
		int x = roubles * 100 + kopecks;
		int y = b.roubles * 100 + b.kopecks;
		if (x < y)
			return true;
		else
			return false;
	}
	

};

int main()
{
	int g = 0;
	Money a(0, 0);
	Money b(0, 0);
	Money c(0, 0);
	double frac = 0;
	a = a.input();
	a.output();
	while (g != 10)
	{
		cout << "Menu:\n1 - data input\n2 - data output\n3 - adding amounts\n4 - subtracting amounts\n5 - multiplication of amounts\n6 - dividing amounts\n7 - multiplication by a fractional number\n8 - find out what's more\n9 - division by fraction \n10 - exit\nYour choice:";
		cin >> g;
		switch (g)
		{
		case 1:
			a = a.input();
			a.output();
			break;
		case 2:
			a.output();
			break;
		case 3:
			b = b.input();
			a = a + b;
			a.output();
			break;
		case 4:
			b = b.input();
			a = a - b;
			a.output();
			break;
		case 5:
			b = b.input();
			a = a * b;
			a.output();
			break;
		case 6:
			b = b.input();
			a = a / b;
			a.output();
			break;
		case 7:
			cout << "Enter your fractional number:";
				cin >> frac;
				a = a * frac;
				a.output();
				break;
		case 8:
			b = b.input();
			if (a > b)
				cout << "First amount more" << endl;
			if (a == b)
				cout << "Amouts are equal" << endl;
			if (a < b)
				cout << "Second amount more" << endl;
			break;
		case 9:
			cout << "Enter your fractional number:";
			cin >> frac;
			a = a / frac;
			a.output();
			break;
		case 10:
			cout << "Good bye!";
		default :
			cout << "Wrong value, try again";

		}

	}
}
