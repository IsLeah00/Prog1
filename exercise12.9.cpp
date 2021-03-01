#include "Simple_window.h"
#include "Graph.h"


int main()
{

			using namespace Graph_lib;


	Simple_window win {Point{100,100},800,600,"Exercise 9"};


	Image photo{Point{200,200}, "badge.jpg"};

	Text t{Point{320,530}, "Twitch badge"};

	win.attach(photo);
	win.attach(t);

	
	win.wait_for_button();
}