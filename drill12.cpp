#include "Simple_window.h"
#include "Graph.h"



int main()
{
          using namespace Graph_lib;

          Point tl {100,100};

          Simple_window win {tl,600,400, "Canvas"};
          win.set_label("My label");


          Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
          win.attach(xa);

          Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
          ya.set_color(Color::blue);
          ya.label.set_color(Color::cyan);
          win.attach(ya);



          Function sine {sin,0,100,Point{20,150},1000,50,50};
          sine.set_color(Color::green);
          win.attach(sine);



          Polygon poly;
          poly.add(Point{200,300});
          poly.add(Point{100,350});
          poly.add(Point{200,400});
          poly.set_color(Color::dark_red);
          poly.set_style(Line_style::dash);
          win.attach(poly);



          Rectangle r{Point{200,200}, 100, 50};
          r.set_fill_color(Color::white);
          win.attach(r);



          Closed_polyline poly_rect;
          poly_rect.add(Point{50,100});
          poly_rect.add(Point{50,200});
          poly_rect.add(Point{100,200});
          poly_rect.add(Point{100,100});
          poly_rect.add(Point{75,50});
          poly_rect.set_style(Line_style(Line_style::dash,2));
          win.attach(poly_rect);



          Text t {Point{150,150}, "Hello, graphical world!"};
          t.set_font(Font::times_bold);
          t.set_font_size(36);
          win.attach(t);

win.wait_for_button();



          Image ii {Point{100,50}, "badge.jpg"};
          win.attach(ii);
          win.set_label("Picture");

win.wait_for_button();

}