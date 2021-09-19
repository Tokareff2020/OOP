#include <iostream>
#include <typeinfo>
using namespace std;



class BritishMoney 
{
private: 

    float x;
    unsigned long long pound, shilling, penny = 0;
    float pound1, shilling1, penny1, penny2 = 0;
    unsigned long long newpound,newshilling,
        newpenny = 0;
public: 

    
    void set(unsigned long long set_pound, unsigned long long set_shilling, unsigned long long set_penny) // инициализация суммы
    {
        pound = set_pound;
        shilling = set_shilling;
        penny = set_penny;
    }
    void get() // вывод суммы
    {
        cout << "Your balance: " << pound << " pounds " << shilling << " shillings " << penny << " penny " << endl;
    }
    void penny_to_amount(unsigned long long set_penny1, unsigned long long set_pound, unsigned long long set_shilling, unsigned long long set_penny) // перевод всей суммы в пенни
    {
        pound = set_penny1 / 240;
        set_penny1 = set_penny1 - 240 * pound;
        shilling = set_penny1 / 12;
        set_penny1 = set_penny1 - 12 * shilling;
        penny = set_penny1;
    }
    void sum(unsigned long long set_pound, unsigned long long set_shilling, unsigned long long set_penny) // сложение сумм
    {
        pound += set_pound;
        shilling += set_shilling;
        penny += set_penny;
    }
    void min(unsigned long long set_pound, unsigned long long set_shilling, unsigned long long set_penny) // вычитание сумм
    {
        penny1 = 240 * pound + 12 * shilling + penny;
        penny2 = 240 * set_pound + 12 * set_shilling + set_pound;
        if (penny1 > penny2)
        {
            penny1 = penny1 - penny2;
            penny_to_amount(penny1, pound, shilling, penny);
        }
        else
        {
            cout << "Your amounts are equal or the second amount is greater than the first." << endl;
            pound = 0;
            shilling = 0;
            penny = 0;
        };
        
    }
    void max(float penny1, float penny2) // нахождение максимального числа
    {
        if (penny1 > penny2)
            cout << "First amount more!" << endl;
        if (penny1 == penny2)
            cout << "Amounts are equal!" << endl;
        if (penny1 < penny2)
            cout << "Second amount more!" << endl;

    }
    void transPenny(unsigned long long set_pound, unsigned long long set_shilling, unsigned long long set_penny) // деление сумм
    {
        penny1 = 240 * pound + 12 * shilling + penny;
        penny2 = 240 * set_pound + 12 * set_shilling + set_pound;
        if (penny1 == 0 || penny2 == 0)
            cout << "One amount equal 0";
        else
        {
            x = penny1 / penny2;
            penny1 = penny1 / penny2;
            penny_to_amount(penny1, pound, shilling, penny);
            cout << "The difference is " << x << " times" << endl;
        }
        
    }
    void transAmount() // перевод суммы в корректный вид 
    {
        while (penny >= 12)
        {
            shilling++;
            penny -= 12;
        }
        while (shilling >= 20)
        {
            pound++;
            shilling -= 20;
        }
    }

    void div(unsigned long long pound, unsigned long long shilling, unsigned long long penny, float frac) // деление суммы на дробное число
    {
        penny1 = 240 * pound + 12 * shilling + penny;
        penny1 = penny1 / frac;
        penny_to_amount(penny1, pound, shilling, penny);

    }
    void mult(unsigned long long pound, unsigned long long shilling, unsigned long long penny, float frac) // умножение суммы на дробное число
    {
        penny1 = 240 * pound + 12 * shilling + penny;
        penny1 = penny1 * frac;
        penny_to_amount(penny1, pound, shilling, penny);

    }
    void more(unsigned long long set_pound, unsigned long long set_shilling, unsigned long long set_penny) // нахождение большей суммы
    {
        penny1 = 240 * pound + 12 * shilling + penny;
        penny2 = 240 * set_pound + 12 * set_shilling + set_pound;
        max(penny1, penny2);
    }

}; 

int main()
{
    int x = 0, a = 1;
    float frac = 0;
    unsigned long long pound, shilling,
        penny = 0;
    unsigned long long newpound, newshilling, newpenny = 0;

    BritishMoney objBritishMoney;
    cout << "Enter your amount:\n";
    cout << "Pounds: ";     cin >> pound;
    cout << "Shillings: ";    cin >> shilling;
    cout << "Penny: ";  cin >> penny;
    objBritishMoney.set(pound, shilling, penny);
    objBritishMoney.get();
   
    while (a != 10)
    {
        cout << "Menu:\n1 - data input\n2 - data output\n3 - adding amounts\n4 - subtracting amounts\n5 - dividing amounts\n6 - division by fraction\n7 - multiplication by a fractional number\n8 - find out what's more\n9 - converted to the correct format \n10 - exit\nYour choice:";
        cin >> a;
            switch (a)
            {
            case 1: cout << "Enter your amount:\n";
                cout << "Pounds: ";     cin >> pound;
                cout << "Shillings: ";    cin >> shilling;
                cout << "Penny: ";  cin >> penny;
                objBritishMoney.set(pound, shilling, penny);
                objBritishMoney.get();
                
                break;
            
                  
            case 2: objBritishMoney.get();
                break;
            case 3: 
                cout << "Enter your amount:\n";
                cout << "Pounds: ";     cin >> newpound;
                cout << "Shillings: ";    cin >> newshilling;
                cout << "Penny: ";  cin >> newpenny;
                objBritishMoney.sum(newpound, newshilling, newpenny);
                objBritishMoney.get();
                break;
            
            case 4:
            
                cout << "Enter your amount:\n";
                cout << "Pounds: ";     cin >> newpound;
                cout << "Shillings: ";    cin >> newshilling;
                cout << "Penny: ";  cin >> newpenny;
                objBritishMoney.min(newpound, newshilling, newpenny);
                objBritishMoney.get();
                break;
            case 5:
                cout << "Enter your amount:\n";
                cout << "Pounds: ";     cin >> newpound;
                cout << "Shillings: ";    cin >> newshilling;
                cout << "Penny: ";  cin >> newpenny;
                objBritishMoney.transPenny(newpound, newshilling, newpenny);
                break;
            case 6:
                cout << "Enter your fraction:\n";
                cin >> frac;
                objBritishMoney.div(pound, shilling, penny, frac);
                objBritishMoney.get();
                break;
            case 7 :
                cout << "Enter your fraction:\n";
                cin >> frac;
                objBritishMoney.mult(pound, shilling, penny, frac);
                objBritishMoney.get();
                break;
            case 8 :
                cout << "Enter your amount:\n";
                cout << "Pounds: ";     cin >> newpound;
                cout << "Shillings: ";    cin >> newshilling;
                cout << "Penny: ";  cin >> newpenny;
                objBritishMoney.more(newpound, newshilling, newpenny);
                break;
            case 9 :
                objBritishMoney.transAmount();
                cout << "Your amount has been converted to the correct format." << endl;
                objBritishMoney.get();
                break;
            case 10 :
                cout << "Good luck!";
                break;
            default :
                cout << "Wrong value" << endl;
                
            }
                  
    }
}
