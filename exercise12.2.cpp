#include "Simple_window.h"
#include "Graph.h"

int main()
{
	    using namespace Graph_lib;

	Simple_window win {Point{100,100},600,400,"Exercise 2"};


Rectangle r {Point{250,180},100, 50};
	win.attach(r);

Text t {Point{280, 200}, "Howdy!"};
	win.attach(t);


	win.wait_for_button();
}

