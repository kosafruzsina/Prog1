#include <iostream>
#include <string>

using namespace std;
class B1{
	public:
		virtual void vf() { cout << "B1::vf()" << endl;}
		void f() {cout << "B1::f()" << endl;}
		virtual void pvf() = 0;
};

class D1 : public B1{
	public:
		virtual void vf() {cout << "D1::vf()" << endl;}
		void f() {cout << "D1::f()";}
};

class D2 : public D1{
	public:
		void pvf() {cout << "D2::pvf()" << endl;}	

};

class B2{
	public: 
		virtual void pvf() = 0;
};

class D21 : public B2{
	public:
		void pvf() {cout << s << endl;}
		string s;
};

class D22 : public B2{
	public:
		int n;
		void pvf(){cout << n << endl;}
};

void f(B2& b2){ b2.pvf();}


int main(){
	/*B1 b1;
	b1.vf();
	b1.f();
	for (int i=0; i<=4; ++i){
		b1 pvf();
	}
	
	D1 d1;
	d1.vf();
	for (int i=0; i<=3; ++i){
		d1.f();
	}
	
	B1& bref = d1;
	bref.vf();
	bref.f();
	
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();*/
	
	D21 d21;
	d21.s = "d21.s";
	d21.pvf();
	
	D22 d22;
	d22.n=22;
	d22.pvf();
	
	f(d21);
	f(d22);
}