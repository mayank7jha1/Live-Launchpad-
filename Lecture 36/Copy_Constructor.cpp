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

//Copy Constructor:

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


	//Copy Constructor:

	Car(Car &l) {
		cout << "You are Inside Your own Copy Constructor" << endl;
		Price = l.Price;
		Model = l.Model;
		Condition = l.Condition;
		Mileage = l.Mileage;
		strcpy(Name, l.Name);
	};


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


//Pass By Value:
/*
	Niche se jo value of x and y aayi hain vo copy
	hogi in values of a and b and uske baad jo kaam karna hain
	vo hoga.


*/
int sum(int a, int b) {
	return a + b;
}


int main() {

	Car d;//Default Constructor

	//Parameterised Constructor
	Car c("BMW", 144, "Very Good", 104.7, 1000);



	//Default Copy Constructor is Invoked (Which Do Shallow Copy).
	Car e(c);//Copy Constructor

	c.Print();

	e.Print();

	/*
		Shallow and Deep Copy:

		Default Copy Constructor is Shallow Copy
		Own Copy Constructor Deep Copy.
	*/

	int x = 10, y = 20;

	cout << sum(x, y) << endl;;

}



/*
	Main Copy Constructor bana raha hu
	to copy one object into another object.


	Pass By Value : Jo cheez niche
	argument me passed hain uski value pass hogi
	and vo copy hogi argument of the function.


	Agar aapne Argument for copy constructor
	pass by reference ya reference ke through
	nahi banaya to aap kya keh rahe ho?

	Ex:
	Car e(c).

	Main e object ke ander c ko copy karna chahta hu
	for this main ek copy constructor bana raha hu
	kyuki compiler ko nahi pata copy kaise karna hain for
	you own compiler and then if you pass object by value
	you are saying ki object ki copy bhejo copy constructor
	me jo mere liye copy karna sikhata hain compiler ko
	but agar compiler ko bina copy constructor ke copy karna
	nahi aata to vo c ki value ko argument me copy kaise karega?



*/






/*


Pass By Value hain:
Niche se jo object c aaraha hain vo copy hoga in  l.

Copy kaise hoga?
Copy karne ke liye to copy constructor chahhiye ?
(x) Ussi ka code to likh rahe ho.

toh copy constructor nahi hain to copy nahi hoga and
agar copy nahi hua copy constructor ka code kaise likhe?

Car(Car l){



}

Car e(c);



*/