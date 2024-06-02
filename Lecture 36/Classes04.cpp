#include<iostream>
#include<cstring>
using namespace std;
const int N = 0;

/*
	1. Constructor
	2. Copy Constructor
	3. Copy Assignment Operator
	4. Destructor
*/

//Constructor:

class Car {
private:
	int Price = 1000;
public:
	int Model;
	string Condition;
	double Mileage;
	char Name[100];


	//Default Constructor
	Car() {
		cout << "Default Constructor" << endl;
	}

	//Your own Constructor : Parameterised Constructor
	//Constructor Overloading
	Car(char n[] , int m, string c, double M, int p) {
		cout << "Inside My Own Parameterised Constructor" << endl;
		if (p < 850) {
			Price = 850;
		} else {
			Price = p;
		}

		Model = m;
		Condition = c;
		Mileage = m;
		strcpy(Name, n);
	}


	//Setter
	void Set_Price(double discount) {
		if (discount < 15) {
			Price = 1000 * (1 - (double)(discount / 100));
		} else {
			Price = 850;
		}
	}

	//Getter
	int Get_Price() {
		return Price;
	}

	void Print() {
		cout << Name << endl;
		cout << Model << endl;
		cout << Condition << endl;
		cout << Mileage << endl;
		cout << Price << endl;
		cout << "--------------------------" << endl;
	}
};



int main() {

	//By Default it will invoke Default Constructor
	Car d;

	Car c("BMW", 144, "Very Good", 104.7, 1000);

	c.Print();


	// int x(10);





}