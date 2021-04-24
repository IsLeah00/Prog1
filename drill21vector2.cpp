#include "std_lib_facilities.h"


template<typename C> void print(const C& c, char sep = '\n')
{
	cout << "Floating-point values:\n";

		for (const auto ele : c)
			cout << ele << sep;

	cout << '\n';
}


class Lower_than {
	double v;

public:
	Lower_than(double vv) : v{vv} { }

	bool operator()(const double val) { return val < v; }
};


int main()
{
	const string sname {"drill21vector2.txt"};
ifstream ifs {sname};
if (!ifs) throw runtime_error("A fájl nem olvasható: " + sname);


	vector<double> vd;
		for (double d; ifs >> d;)
			vd.push_back(d);
	print(vd);



vector<int> vi (vd.size());
copy(vd.begin(), vd.end(), vi.begin());
	print(vi);



for (int i = 0; i < vd.size(); ++i)
	cout << vd[i] << '\t' << vi[i] << '\n';


double vd_sum = accumulate(vd.begin(), vd.end(), 0.0);
	cout << "Sum of the elements of vd: " << vd_sum << '\n';


double diff_sum =
		inner_product(vd.begin(), vd.end(),
				vi.begin(),
				0.0,
				plus<double>(),
				minus<double>());
cout << "The difference between the sum of vd and the sum of vi: " << diff_sum << '\n';



reverse(vd.begin(), vd.end());
	print(vd);



double vd_mean = vd_sum / vd.size();
cout << "The mean value in vd: " << vd_mean << '\n';




vector<double> vd2 (vd.size());
auto it = copy_if(vd.begin(), vd.end(), vd2.begin(),
		Lower_than(vd_mean));
		vd2.resize(distance(vd2.begin(), it));
	print(vd2);



sort(vd.begin(), vd.end());
print(vd);

}