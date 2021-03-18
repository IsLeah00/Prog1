#include "Simple_window.h"
#include "Graph.h"




int main()
{
	using namespace Graph_lib;

    Point tl {100, 100};
    Simple_window win {tl, 800, 1000, "Drill 13"};





    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;



    Lines grid;
    for (int x = x_grid; x < x_size; x += x_grid)
        grid.add(Point{x, 0}, Point{x, y_size});
    for (int y = y_grid; y < y_size; y += y_grid)
        grid.add(Point{0, y}, Point{x_size, y});

    grid.set_color(Color::red);

    win.attach(grid);







    Vector_ref<Rectangle> rects;
    for (int i = 0; i < x_size; i += x_grid) {
        rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rects[rects.size() - 1].set_color(Color::invisible);
        rects[rects.size() - 1].set_fill_color(Color::red);
        win.attach(rects[rects.size() - 1]);
    }

    win.wait_for_button();






    Image jpeg1 {Point{0,300}, "2021.jpeg"};
	    jpeg1.set_mask(Point(200,200),200,200);
    Image jpeg2 {Point{300,600}, "2021.jpeg"};
    	jpeg2.set_mask(Point(200,200),200,200);
    Image jpeg3 {Point{500,100}, "2021.jpeg"};
	    jpeg3.set_mask(Point(200,200),200,200);

    win.attach(jpeg1);
    win.attach(jpeg2);
    win.attach(jpeg3);
    win.wait_for_button();






    Image loop {Point{0,0}, "loop.jpg"};
    loop.set_mask(Point(100,100),100,100);
    win.attach(loop);
    win.wait_for_button();

    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
    while (true) {
        x = randint(8);
        y = randint(8);
        dx = 100*x - loop.point(0).x;
        dy = 100*y - loop.point(0).y;
        loop.move(dx,dy);

        win.wait_for_button();
    }
}
