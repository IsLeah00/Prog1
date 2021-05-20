#include "std_lib_facilities.h"


class Person
{
public:
    double height;
    double weight;
    char sex;
    int age;

    Person()
    {
        height=0;
        weight=0;
        sex=' ';
        age=0;
    }

    Person(double magassag, double suly, char nem, int kor)
    {height=magassag; weight=suly; sex=nem; age=kor;}

    friend istream &operator >> ( istream &is, Person &P)
    {
        cout << "Írja be a nemét (n=nő,f=férfi): ";
        is >> P.sex;

        cout << "Írja be az életkorát: ";
        is >> P.age;

        cout << "Írja be a magasságát (cm): ";
        is >> P.height;

        cout << "Írja be a súlyát (kg): ";
        is >> P.weight;


    return is;
    }


    friend ostream &operator << ( ostream &os, Person &P)
    {
        cout << "Neme: ";
        os << P.sex <<"\n";

        cout << "Kora: ";
        if (P.age>120) {cout<<"Hibás életkor."<<"\n";}
        else {os << P.age << "\n";};

        cout<<"Magassága: ";
        if (P.height>250) {cout<<"Hibás testmagasság."<<"\n";}
        else {os << P.height << " cm\n";};

        cout << "Súlya: ";
        if (P.weight>230) {cout<<"Hibás testsúly."<<"\n";}
        else {os << P.weight << " kg\n";};

        cout << "BMI index: ";


    return os;
    }
};

int main()
{
    Person P;

	cin >> P;
    	cout << P;
	
	auto bmi=[P]() {return P.weight/((P.height*P.height)*0.0001);};
    	cout << bmi() << endl;

return 0;
}
