#include "std_lib_facilities.h"


class Height_weight
{
public:
    double height;
    double weight;
    Height_weight()
    {
        height=0;
        weight=0;
    }
    Height_weight(double h, double w) {height=h; weight=w;}

    friend ostream &operator << (ostream &os, const Height_weight &hw)
    {
        float bmi;
            bmi=(hw.weight)/(hw.height*hw.height*0.01*0.01);


        cout<<"Magassága: ";
        if (hw.height>250) {cout<<"Hibás testmagasság."<<"\n"; return os;};
        os << hw.height << " cm\n";

        cout << "Súlya: ";
        if (hw.weight>230) {cout<<"Hibás testsúly."<<"\n"; return os;};
        os << hw.weight << " kg\n";

        cout <<"BMI index: ";
        os << bmi << "\n";
        return os;      
    }

    friend istream &operator>>( istream  &is, Height_weight &hw) 
    { 
    cout << "Írja be a magasságát (cm): ";
    is >> hw.height;
    cout << "Írja be a súlyát (kg): ";
    is >> hw.weight;
    return is;            
    }

};

class Sex
{
public:
    char sex;

    Sex()
    {
        sex=' ';
    }
    Sex(char s) {sex=s;}

        friend ostream &operator << (ostream &os, Sex &s)
        { 
        cout << "Neme: ";
        os << s.sex <<"\n";
        return os;
        }

        friend istream &operator>>( istream  &is, Sex &s) 
        { 
        cout << "Írja be a nemét (n=nő,f=férfi): ";
        is >> s.sex;
        return is;            
        }
};

class Age
{
public:
    int age;

    Age()
    {
        age=0;
    }
    Age(int a) {age=a;}

        friend ostream &operator << (ostream &os, const Age &a)
        { 
        cout << "Kora: ";
        if (a.age>120) {cout<<"Hibás életkor."<<"\n"; return os;};
        os << a.age << "\n";
        return os;
        }

        friend istream &operator>>( istream  &is, Age &a) 
        { 
        cout << "Írja be az életkorát: ";
        is >> a.age;
        return is;            
        }    

};


int main()
{
	Height_weight hw;
    Sex s;
    Age a;

	cin >> s;
    cin >> a;
    cin >> hw;

	cout << s;
    cout << a;
    cout << hw;


return 0;
}