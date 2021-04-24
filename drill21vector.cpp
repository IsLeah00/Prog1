#include "std_lib_facilities.h"



struct Item {
	string name;
	int iid;
	double value;
};


ostream& operator<<(ostream& os, const Item& it)
{
	return os << it.name << '\t'
			  << it.iid << '\t'
			  << it.value;
}


istream& operator>>(istream& is, Item& it)
{
	string ss;
	int ii;
	double dd;
	is >> ss >> ii >> dd;
	Item itt {ss, ii, dd};
		it = itt;
	return is;
}


template<typename C>
void print(const C& c, char sep = ' ')
{
    for (const auto& a : c)
        cout << a << sep;
    cout << '\n';
}





struct Largest_val {
    bool operator()(const Item& a, const Item& b)
    {
        return a.value > b.value;
    }
};


class Insert_val {
    double val;
public:
    Insert_val(double vv) : val{vv} { }
    bool operator()(const Item& x) const { return x.value < val; }
};


class Erase_by_name {
    string name;
public:
    Erase_by_name(const string& nn) : name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};


class Erase_by_iid {
    int iid;
public:
    Erase_by_iid(int id) : iid{id} { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};



int main()
{
	const string vname {"drill21vector.txt"};

ifstream ifs {vname};
if (!ifs) throw runtime_error("Nem olvasható a fájl: " + vname);

	vector<Item> vi;
		for (Item ii; ifs >> ii;)
			vi.push_back(ii);


	list<Item> li (vi.size());
		copy(vi.begin(), vi.end(), li.begin());



sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.name < b.name; });

sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.iid < b.iid; });

sort(vi.begin(), vi.end(), Largest_val());


Item tmp {"horse shoe", 99, 12.34};
vi.insert( find_if(vi.begin(), vi.end(), Insert_val(tmp.value)), tmp);

tmp = Item{"Canon S400", 9988, 499.95};
vi.insert( find_if(vi.begin(), vi.end(), Insert_val(tmp.value)), tmp);


vi.erase(find_if(vi.begin(), vi.end(), Erase_by_name("SeaOfThieves")));
vi.erase(find_if(vi.begin(), vi.end(), Erase_by_name("Postal")));


vi.erase(find_if(vi.begin(), vi.end(), Erase_by_iid(12)));
vi.erase(find_if(vi.begin(), vi.end(), Erase_by_iid(30)));

print(vi, '\n');








li.sort([](const Item& a, const Item& b) { return a.name < b.name; });
li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
li.sort([](const Item& a, const Item& b) { return a.value > b.value; });


tmp = {"horse shoe", 99, 12.34};
li.insert(find_if(li.begin(), li.end(), Insert_val(tmp.value)), tmp);

tmp = {"Canon S400", 9988, 499.95};
li.insert(find_if(li.begin(), li.end(), Insert_val(tmp.value)), tmp);


li.erase(find_if(li.begin(), li.end(), Erase_by_name("ResidentEvil")));
li.erase(find_if(li.begin(), li.end(), Erase_by_name("SaintRow")));

li.erase(find_if(li.begin(), li.end(), Erase_by_iid(46)));
li.erase(find_if(li.begin(), li.end(), Erase_by_iid(73)));

print(li, '\n');

}