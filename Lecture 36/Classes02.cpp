#include<iostream>
using namespace std;
const int N = 0;

//Designing of your Data Type Car.

/*
	Data Members (Variable jo is class ke ander hain.)
	Member Functions (Functions that are defined inside the class.)

	First you are creating the design of TATA (Basic Design).
	Data Members:
	Price:
	Model
	Condition
	Mileage
	char Name[];
*/

class Car {
private:
	int Price;
public:
	int Model;
	string Condition;
	double Mileage;
	char Name[100];
};



int main() {

	int x;

	//Ye vo cheez hain jo aapne actually me create kari hain.
	//This is the entity that is actually taking space inside
	//memory.

	Car c;//This is an object(It will have all the functionality of the data
	// type Car )


	/*

		This Object C can access all the public data members and member
		functions of the class Car.

		How do we access a Data Member and Member function of a
		class: using . operator


		c.Mileage;

		We are using it like this because this Mileage will be
		specific to c only.

		Car d;
		d.Mileage;


		Mileage??
	*/





}