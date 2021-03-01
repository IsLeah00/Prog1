#include "Simple_window.h"
#include "Graph.h"



int main()
{
			using namespace Graph_lib;


	Simple_window win {Point{100,100},800,600,"Exercise 6"};

Rectangle home {Point{100,100},500,400};

Polygon window_1;
	window_1.add(Point{150,150});
	window_1.add(Point{150,300});
	window_1.add(Point{250,300});
	window_1.add(Point{250,150});

Polygon window_2;
	window_2.add(Point{300,150});
	window_2.add(Point{300,300});
	window_2.add(Point{400,300});
	window_2.add(Point{400,150});


Line door_1(Point{525,300}, Point{600,300});
Line door_2(Point{525,300}, Point{525,500});



Polygon roof;
	roof.add(Point{300,20});
	roof.add(Point{650,100});
	roof.add(Point{50,100});
	


	win.attach(home);
	win.attach(window_1);
	win.attach(window_2);
	win.attach(door_1);
	win.attach(door_2);
	win.attach(roof);



	win.wait_for_button();

}