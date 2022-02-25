#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>

int main(){

	using namespace Graph_lib;
	
try
{
	Simple_window win {Point{100,100},1030,480, "Canvas"};

	Axis xa {Axis::x, Point{30,350}, 300,10, "X Axis"};
	
	Axis ya {Axis::y, Point{30,350}, 300, 10, "Y Axis"};
	ya.set_color(Color::red);
	ya.label.set_color(Color::blue);

	Function sine {sin,0,2*3.14,Point{30,250},300,49,49};
	sine.set_color(Color::dark_blue);

	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::red);
	poly.set_style(Line_style(Line_style::dash,3));

	Rectangle r{Point{100,120}, 150,50};
	r.set_fill_color(Color::yellow);

	Closed_polyline poly_rect;
	poly_rect.add(Point{450,225});
	poly_rect.add(Point{500,200});
	poly_rect.add(Point{600,200});
	poly_rect.add(Point{550,225});
	poly_rect.add(Point{600,250});
	poly_rect.add(Point{500,250});
	poly_rect.set_style(Line_style(Line_style::dash,3));
	poly_rect.set_fill_color(Color::green);

	Text t{Point{150,70}, "Hello, graphical world!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Circle c{Point{450,330},50};
	Ellipse e{Point{450,330}, 75,25};
	e.set_color(Color::dark_red);
	Mark m{Point{450,330},'.'};

	Image ii{Point (620,50), "cica.jpg"};

	Image ii2{Point(640,70), "cica.jpg"};


	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
	win.attach(c);
	win.attach(e);
	win.attach(m);
	win.attach(ii);
	win.attach(ii2);

	win.set_label("My Window");

	win.wait_for_button();
	}
	catch (exception& e){
		cout << "error\n";
		return 1;
	}

	catch(...){
		cout << "error2\n";
		return 2;
	}
}