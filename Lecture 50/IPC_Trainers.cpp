#include<bits/stdc++.h>
using namespace std;
const int N = 1e + 10;
#define int long long

int Solve() {

	int Trainers, Days;
	cin >> Trainers >> Days;

	int AD[N] {0}, Sadness[N] {0}, Lecture[N] {0};

	priority_queue<pair<int, int>>pq;//Max Heap : { Sadness,index }

	for (int i = 0; i < Trainers; i++) {
		cin >> AD[i] >> Lecture[i] >> Sadness[i];
		pq.push({Sadness[i], i});
	}

	int Lecture_Taken[N] {0};


	set<int>AvailableDay;

	for (int i = 1; i <= Days; i++) {
		AvailableDay.insert(i);
	}



	//Ek ek karke har teacher ko jitne lecture desakta hu
	//dedunga.

	while (!pq.empty()) {

		pair<int, int>p1 = pq.top();//Trainer with max sadness till now
		pq.pop();

		int Current_Trainer_Index = p1.second;
		int Current_Trainer_Sadness = p1.first;


		int Idea_Start_Day = AD[Current_Trainer_Index];
		int Idea_End_Day = Idea_Start_Day + Lecture[Current_Trainer_Index] - 1;


		for (int i = Idea_Start_Day; i <= Idea_End_Day; i++) {

			auto f = AvailableDay.lower_bound(i);
			if (f == AvailableDay.end()) {
				//Koi din ab bacha nahi hain is teacher ke liye and
				//hence ye teacher aur lecture nahi lepaayega.
				break;
			} else {

				Lecture_Taken[Current_Trainer_Index]++;
				AvailableDay.erase(f);
			}

		}
	}


	int Total_Sadness = 0;

	for (int i = 0; i < Trainers; i++) {
		Total_Sadness += (Lecture[i] - Lecture_Taken[i]) * Sadness[i];
	}


	return Total_Sadness;
}


int32_t main() {

	int t; cin >> t;

	while (t--) {

		cout << Solve() << endl;

	}

}