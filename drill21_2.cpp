#include <stdexcept>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

struct Item{
	public:
		string name;
		int iid;
		double value;
		Item(string n, int i, double v): name{n}, iid{i}, value{v} {}
};

ostream& operator<<(ostream& os, const Item& t){
		os << t.name <<'\t' << t.iid << '\t'<< t.value;
		return os;
}

struct Item_cmp{
	bool operator() ( const Item a, const Item b){
	//return a.name < b.name; 	//sort by name
	//return a.iid < b.iid; 	//sort by iid
	//return a.value < b.value;	//sort by value
	return b.value < a.value;	//sort by value (largest value first)
	}
	
};

template<typename C>
void print(const C& c, char sep='\n'){
	cout<<"Container elements: \n";
	for (const auto elem : c){
		cout<<elem<<sep;
	}
	cout<<endl;
}

int main()
try{
	cout<<"Vector:\n";
	vector<Item> vi {
	Item{"Plum", 24, 15.0},
	Item{"Apple", 141, 1.20},
	Item{"Banana", 22, 32.2},
	Item{"Cherry", 40, 98.2},
	Item{"Mango", 26, 7.3},
	Item{"Lemon", 34, 122.57},
	Item{"Grape", 25, 38.2},
	Item{"Strawberry", 32, 10.0},
	Item{"Peach", 80, 4.13},
	Item{"Watermelon", 26, 22.19},
	};
	print(vi);
	
	sort(vi.begin(), vi.end(),Item_cmp());
	cout<<"Sort by value: \n";
	print(vi);

	vi.push_back(Item("horse shoe",99, 12.34));
	vi.push_back(Item("Canon",9988, 499.95));
	cout<<"After adding horse shoe and Canon S400: \n";
	print(vi);
	
	vector<Item>::iterator ptr;
	string nameKey="Plum";
	for(ptr=vi.begin(); ptr < vi.end(); ptr++){
	if(ptr->name==nameKey) break;
	}
	vi.erase(ptr);
	
	nameKey="Lemon";
	for(ptr=vi.begin(); ptr < vi.end(); ptr++){
	if(ptr->name==nameKey) break;
	}
	vi.erase(ptr);
	
	cout<<"After removing plum and lemon : \n";
	print(vi);
	
	int iidKey=22;
	for(ptr=vi.begin(); ptr < vi.end(); ptr++){
	if(ptr->iid==iidKey) break;
	}
	vi.erase(ptr);
	
	iidKey=32;
	for(ptr=vi.begin(); ptr < vi.end(); ptr++){
	if(ptr->iid==iidKey) break;
	}
	vi.erase(ptr);
	
	cout<<"After removing iid 22 and 32 : \n";
	print(vi);
	
	cout<<"List:\n";
	list<Item> li {
	Item{"Plum", 24, 15.0},
	Item{"Apple", 141, 1.20},
	Item{"Banana", 22, 32.2},
	Item{"Cherry", 40, 98.2},
	Item{"Mango", 26, 7.3},
	Item{"Lemon", 34, 122.57},
	Item{"Grape", 25, 38.2},
	Item{"Strawberry", 32, 10.0},
	Item{"Peach", 80, 4.13},
	Item{"Watermelon", 26, 22.19},
	};
	print(li);
	
	li.sort(Item_cmp());
	cout<<"After sorting by value: \n";
	print(li);

	li.push_back(Item("horse shoe",99, 12.34));
	li.push_back(Item("Canon",9988, 499.95));
	cout<<"After adding horse shoe and Canon S400: \n";
	print(li);
	
	 
	nameKey= "Plum";
	for(list<Item>::iterator ptr2=li.begin(); ptr2 != li.end(); ptr2++){
	if(ptr2->name==nameKey) {
		li.erase(ptr2);
		break; 
		}
	}
	
	nameKey="Lemon";
	for(list<Item>::iterator ptr2=li.begin(); ptr2 != li.end(); ptr2++){
	if(ptr2->name==nameKey) {
		li.erase(ptr2);
		break;
		}
	}
	
	cout<<"After plum Haas and lemon: \n";
	print(li);
	
	iidKey=22;
	for(list<Item>::iterator ptr2=li.begin(); ptr2 != li.end(); ptr2++){
	if(ptr2->iid==iidKey) {
		li.erase(ptr2);
		break;
		}
	}
	iidKey=32;
	for(list<Item>::iterator ptr2=li.begin(); ptr2 != li.end(); ptr2++){
	if(ptr2->iid==iidKey) {
		li.erase(ptr2);
		break;
		}
	}
	cout<<"After removing iid 22 and 32 : \n";
	print(li);
}
catch(exception& e) {
	cerr<<e.what()<<'\n';
	return 1;
}catch(...) {
	cerr<<"Unknown exception";
	return 2;
}