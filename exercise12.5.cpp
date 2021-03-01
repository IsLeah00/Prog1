#include "Simple_window.h"
#include "Graph.h"


int main()
{

			using namespace Graph_lib;


	Simple_window win {Point{0,0},1280,1024,"Exercise 5"};

	
		Rectangle r {Point{150,20},853,923};
	r.set_style(Line_style(Line_style::solid, 4));
	win.attach(r);


		Polygon frame;
	frame.add(Point{145,15});
	frame.add(Point{1006,15});
	frame.add(Point{1006,946});
	frame.add(Point{145,946});
	frame.set_color(Color::dark_red);
	win.attach(frame);


	win.wait_for_button();
}