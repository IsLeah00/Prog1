#include "Simple_window.h"
#include "Graph.h"


int main()
{
          using namespace Graph_lib;


	Simple_window win {Point{100,100},600,400,"Exercise 1"};

Rectangle r {Point{300,150},150, 100};
	r.set_color(Color::blue);
		win.attach(r);


Polygon poly;
	poly.set_color(Graph_lib::Color::red);
	poly.add(Point{40,130});
	poly.add(Point{150,130});
	poly.add(Point{150,230});
	poly.add(Point{40,230});
		win.attach(poly);


win.wait_for_button();
}