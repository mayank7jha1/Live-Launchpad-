#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long

int n, m;
int t[N] {0};

int freq[101] {0};


void Solve() {

	int TTC = 0;//Total time consumed.

	for (int i = 0; i < n; i++) {

		//Currently We are talking about the ith student.

		/*
			We have not updated our TTC till now. that means
			even though we are talking about ith student
			TTC stores value till i-1 th student.

		*/
		int diff = TTC + t[i] - m;
		int Fail = 0;

		if (diff > 0) {
			//If we are standing here then that means i have to fail some
			//students.

			//Main un student ko pehle fail karna chahta hu
			//jiska time jada hain in order for me to minimise my
			//overall fail students.

			//Since I only have students that consume time from
			//1 to 100 mins i can just iterate over the
			//freq array in desc. order and find out how many studens
			//i have to fail.

			for (int j = 100; j >= 1; j--) {

				if (freq[j] > 0) {

					//Iska matlab ye hain ki koi student hain
					//jo is current time i.e. j time ko
					//consume karta hain in range 1- i-1 th student
					//tak kyuki maine ith student ka time
					//abhi add nahi kiya kyuki main nahi chahta
					//vo galti se remove hojaaye.

					//jth time vaale student ka kya contribution hoga

					int contribution = j * freq[j];

					if (contribution >= diff) {
						//Mujhe kuch j time vaale student remove
						//karne hain.

						//Formulae lagana hain kuch students of
						//j time ko remove karne ke liye.

						Fail += ((diff + j - 1 ) / j);//Ceil value
						break;
					}

					//Agar aap directly idhar aaye iska matlab
					//mujhe saare students remove karne hain
					//j time ke.
					Fail += freq[j];
					diff -= contribution;

				}

			}
		}

		//If I directly come here without going to line number 29
		//I will not fail any student.
		freq[t[i]]++;
		TTC += t[i];//Updating for the ith student.

		cout << Fail << " ";
	}

	return;
}

int32_t main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}


	Solve();
}




// t = 50;

// 1 2  3  4  5
// 3 50 40 40 40


// 5 student ko pass karne ke liye:

// 1 se lekar 4th student tak kitne student ko fail karna padega.


// freq:

// 3--->1
// 40-->2
// 50-->1


// j=50 time vala student :



// TTC:133
// diff=133+40-50=123

// iska contribution kitna hain: 50*1:50
// 50<123:
// fail=1
// 123-50=
// 73


// j=40:
// 73:

// 40*2=80



//j=40: 40 time vale student ka kya contribution hain ye nikalna hain:

// diff=100
// diff=300

//freq[40]=5:


//40*5=200:

//300<200: saare 40 time vale students remove kar sakte ho.

//direcly remove kar diya.