#include <iostream>
using namespace std;
class Inhert{
	public:
		virtual void print(){
			cout << "Inhert" << endl;
		}	
};

class Daughter : public Inhert {

	public:
		void print(){
			cout << "Daughter" << endl;
		}

		void funka(string * ez){
			//cout << *ez << endl;
			*ez = "test";
		}
		string * test[5];

		void add(string * ez, int a){
			test[a] = ez;
		}
		void get(int a){
			cout << *test[a] <<endl;
		}
};

int main(){
	// Inhert inh;
	// inh.print();
	// Daughter dd;
	// dd.print();

	// Inhert * ad;
	// ad = &dd;
	// ad->print();

	// Inhert * das[10];
	// das[0] = &dd;
	// das[0]->print();
	Daughter d; 
	string hello = "hey";
	d.add(&hello, 1);
	d.get(1);
	d.funka(&hello);
	d.add(&hello, 2);
	d.get(1);
	d.get(2);
}