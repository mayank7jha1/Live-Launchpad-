#include<iostream>
using namespace std;
const int N = 0;


//To Access the Private Data Members and Member Functions
//on your Terms WE have Getters and Setters.

class Car {
private:
	int Price = 1000;
public:
	int Model;
	string Condition;
	double Mileage;
	char Name[100];

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

	Car c;//Object

	c.Model = 144;
	c.Condition = "Very Good";
	c.Mileage = 105.7;
	c.Name[0] = 'B';
	c.Name[1] = 'M';
	c.Name[2] = 'W';
	c.Name[3] = '\0';
	//c.Price = 100;

	c.Print();


	c.Set_Price(8);
	cout << c.Get_Price() << endl;



	// cout << c.Name << endl;
	// cout << c.Model << endl;
	// cout << c.Condition << endl;
	// cout << c.Mileage << endl;
	// cout << c.Price << endl;


}