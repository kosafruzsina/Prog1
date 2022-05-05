//g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
{
try
	{

	using namespace Graph_lib;

// 1. Make an 800-by-1000 Simple_window.
	Simple_window win{ Point{100,100}, 800, 1000, "Canvas"};

	int x_size = 800;
	int y_size = 1000;

// 2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so that each square is 100 by 100).

	int x_grid = 100;
	int y_grid = 100;

	Lines grid;
	for (int x = x_grid; x < x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,800});

	for (int y = y_grid; y <= 800; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});

	win.attach(grid);

// 3. Make the eight squares on the diagonal starting from the top left corner red (use Rectangle).

	Vector_ref<Rectangle> negyzetek;

	for (int i = 0; i < 8; ++i)
	{
		negyzetek.push_back(new Rectangle{Point{i*100, i*100},100,100});
		negyzetek[i].set_fill_color(Color::red);
		win.attach(negyzetek[i]);
	}

/* 4. Find a 200-by-200-pixel image (JPEG or GIF) and place three copies of it
on the grid (each image covering four squares). If you can’t find an image
that is exactly 200 by 200, use set_mask() to pick a 200-by-200 section of
a larger image. Don’t obscure the red squares. */

	Image pk1 {Point{200,0},"pikachu.jpeg"};
	Image pk2 {Point{0,500},"pikachu.jpeg"};
	Image pk3 {Point{600,200},"pikachu.jpeg"};

	win.attach(pk1);
	win.attach(pk2);
	win.attach(pk3);

/* 5. Add a 100-by-100 image. Have it move around from square to square
when you click the “Next” button. Just put wait_for_button() in a loop
with some code that picks a new square for your image. */

	int x1 = 100; 	
	int y1 = 0;										// kezdo poziciora allitas
	Image ch {Point{x1,y1},"charmander.jpeg"};
	win.attach(ch);

	win.wait_for_button();

// leptetes

	while (true)
	{
		int randomszam = std::rand() % 4;

		if(randomszam == 0 and x1 >= 100)
			{
				ch.move(-100,0);
				x1 = x1-100;
			}
		else if (randomszam == 1 and x1 <= 700)	
			{
				ch.move(100,0);
				x1 = x1+100;
			}
		else if (randomszam == 2 and y1 >= 100)	
			{
				ch.move(0,-100);
				y1 = y1-100;
			}
		else if (randomszam == 3 and y1 <= 700)
			{
				ch.move(0,100);
				y1 = y1+100;
			}
		win.wait_for_button();
	}
	
	}
	catch (exception& e){
		cout << "Error\n";
		return 1;
	}

	catch(...){
		cout << "Other error\n";
		return 2;
	}

}