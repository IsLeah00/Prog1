#include "std_lib_facilities.h"



template<typename M, typename I>
void print(const map<M,I>& m)
{
    cout << "(name,value) pairs: " << '\n';

    for (const auto& a : m)
        cout << a.first << '\t' << '\t' << a.second << '\n';

    cout << '\n';
}


void f(map<string, int>& m)
{
    string s;
    int i = 0;

    while (m.size() < 10) {
        cin >> s >> i;
        m.insert(make_pair(s, i));
    }
}



int main()
{

    map<string,int> msi;


msi["Paper"] = 23;
msi["Iron"] = 51;
msi["Bronze"] = 86;
msi["Silver"] = 90;
msi["Gold"] = 34;
msi["Plat"] = 17;
msi["Diamond"] = 49;
msi["Master"] = 66;
msi["GrandM"] = 85;
msi["Challgr"] = 78;
    
    print(msi);




msi.erase(msi.begin(), msi.end());
    print(msi);


f(msi);
print(msi);




int total = accumulate(msi.begin(), msi.end(), 0,
    [](int sum, const pair<string,int>& p)
        {
            return sum += p.second; 
        });
cout << "Sum of the integers: " << total << '\n';






    map<int,string> mis;

    for (const auto& a : msi)
        mis[a.second] = a.first;

    print(mis);

}