#include "std_lib_facilities.h"



template<class T> struct S {

	S() : val(T()) { }
	S(T d) : val(d) { }
	T& operator=(const T&);
	T& get();
	const T& get() const;
	void set(const T& d);

private:
	T val;

};



template<class T> T& S<T>::get() { return val; }
template<class T> const T& S<T>::get() const { return val; }
template<class T> void S<T>::set(const T& d) { val = d; }


template<class T> T& S<T>::operator=(const T& d)
{
    val = d;
    return val;
}


template<class T> istream& operator>>(istream& is, S<T>& ss)
{
    T v;
    cin >> v;
    if (!is) return is;
    ss = v;
    return is;
}



template<class T> void read_val(T& v) { cin >> v; }




int main()
try {

	S<int> s_int(17);
	S<char> s_char('a');
	S<double> s_double(36.95);
	S<string> s_string("String.");
	vector<int> vi;
	vi.push_back(0);
	vi.push_back(56);
	vi.push_back(7);
	vi.push_back(98);
	S<vector<int>> s_v_int(vi);

/*
cout << "S<int>: " << s_int.val << "\n";
cout << "S<char>: " << s_char.val << "\n";
cout << "S<double>: " << s_double.val << "\n";
cout << "S<string>: " << s_string.val << "\n";
for (int i = 0; i<s_v_int.val.size(); ++i)
cout << "S<vector<int>>[" << i << "]: " << s_v_int.val[i] << "\n";
*/


cout << "S<int>: " << s_int.get() << "\n";
cout << "S<char>: " << s_char.get() << "\n";
cout << "S<double>: " << s_double.get() << "\n";
cout << "S<string>: " << s_string.get() << "\n";
for (int i = 0; i<s_v_int.get().size(); ++i)
cout << "S<vector<int>>[" << i << "]: " << s_v_int.get()[i] << "\n";






 
cout << "\n";
read_val(s_int);
read_val(s_char);;
read_val(s_double);
read_val(s_string);
cout << "\ns_int: " << s_int.get() << "\n";
cout << "s_char: " << s_char.get() << "\n";
cout << "s_double: " << s_double.get() << "\n";
cout << "s_string: " << s_string.get() << "\n";



}



catch (exception& e) {
    cerr << "Exception: " << e.what() << "\n";
}
catch (...) {
    cerr << "Exception\n";
}