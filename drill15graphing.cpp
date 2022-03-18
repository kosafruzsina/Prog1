#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

double one   (double x){return 1  ;}
double slope (double x){return x/2;}
double square(double x){return x*x;}
double sloping_cos(double x){return cos(x)+slope(x);}

int main()
{
	try
	{

		using namespace Graph_lib;
		int constexpr xmax = 600;
		int constexpr ymax = 600;
		Simple_window win{ Point{100,100}, xmax, ymax, "Canvas"};
		
		constexpr int Origx = xmax/2; constexpr int Origy = ymax/2;
		Point Origo{Origx,Origy};
		constexpr int xlen = 400; constexpr int ylen = 400;


		Axis x {Axis::x,Point{100,Origy}, xlen, 20, "1=20 pixels"};
		x.set_color(Color::red);
		Axis y {Axis::y,Point{Origx,ylen+100}, ylen, 20, "1=20 pixels"};
		y.set_color(Color::red);
		win.attach(x);
		win.attach(y);


		constexpr int r_min = -10; constexpr int r_max = 11;
		constexpr int xscale = 20; constexpr int yscale = 20;
		constexpr int pts = 400;

		Function konstans{one, r_min, r_max, Origo, pts, xscale, yscale};
		Function linearis{slope, r_min, r_max, Origo, pts, xscale, yscale};	Text label{Point{100,Origy+85}, "x/2"};
		Function parabola{square, r_min, r_max, Origo, pts, xscale, yscale};
		Function cosinus{cos, r_min, r_max, Origo, pts, xscale, yscale}; cosinus.set_color(Color::blue);
		Function sloping_cosinus{sloping_cos,r_min, r_max, Origo, pts, xscale, yscale};

		win.attach(konstans);
		win.attach(linearis);
		win.attach(parabola);
		win.attach(cosinus);
		win.attach(sloping_cosinus);

		win.wait_for_button();
	}

	catch(exception& e){
		cerr<<"error: " << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch(...){
		cerr << "unknown excp." << endl;
		keep_window_open();
		return 2;
	}
	return 0;
}