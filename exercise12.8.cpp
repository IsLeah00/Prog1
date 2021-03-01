#include "Simple_window.h"
#include "Graph.h"


int main()
{

			using namespace Graph_lib;


	Simple_window win {Point{100,100},800,600,"Olympic symbol"};


	Circle o1 {Point{150,150},50};
	o1.set_style(Line_style(Line_style::solid,2));
	o1.set_color(Color::blue);
	win.attach(o1);


	Circle o2 {Point{255,150},50};
	o2.set_style(Line_style(Line_style::solid,2));
	o2.set_color(Color::black);
	win.attach(o2);


	Circle o3 {Point{360,150},50};
	o3.set_style(Line_style(Line_style::solid,2));
	o3.set_color(Color::red);
	win.attach(o3);


	Circle o4 {Point{200,200},50};
	o4.set_style(Line_style(Line_style::solid,2));
	o4.set_color(Color::yellow);
	win.attach(o4);


	Circle o5 {Point{305,200},50};
	o5.set_style(Line_style(Line_style::solid,2));
	o5.set_color(Color::green);
	win.attach(o5);

	win.wait_for_button();
}