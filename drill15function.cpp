#include "Window.h"
#include "Simple_window.h"
#include "Graph.h"



	const int xmax = 600;
    const int ymax = 600;

    const int x_orig = xmax/2;
    const int y_orig = ymax/2;

    const Point orig(x_orig,y_orig);
    const int n_points = 400;

    const int x_scale = 20;
    const int y_scale = 20;



double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }



int main()
{

	using namespace Graph_lib;


Point tl(600,50);
Simple_window win {tl,xmax,ymax, "Function graphs"};



Axis x(Axis::x,Point(100,y_orig),400,400/x_scale,"1 == 20 pixels");
    x.set_color(Color::red);
    win.attach(x);

Axis y(Axis::y,Point(x_orig,500),400,400/y_scale,"1 == 20 pixels");
    y.set_color(Color::red);
    win.attach(y);

		win.wait_for_button();




Function shape0(one,-10,11,orig,n_points);
    win.attach(shape0);
    win.wait_for_button();



Function shape1(one,-10,11,orig,n_points,x_scale,y_scale);
    win.attach(shape1);
    win.wait_for_button();



Function shape2(slope,-10,11,orig,n_points,x_scale,y_scale);
    win.attach(shape2);
Text tshape2(Point(100,380),"x/2");
    win.attach(tshape2);
    win.wait_for_button();



Function shape3(square,-10,11,orig,n_points,x_scale,y_scale);
    win.attach(shape3);
    win.wait_for_button();



Function shape4(cos,-10,11,orig,n_points,x_scale,y_scale);
    	shape4.set_color(Color::blue);
    win.attach(shape4);
    win.wait_for_button();



Function shape5(sloping_cos,-10,11,orig,n_points,x_scale,y_scale);
    win.attach(shape5);
    win.wait_for_button();

}