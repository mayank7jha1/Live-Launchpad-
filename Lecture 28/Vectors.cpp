#include<iostream>
#include<vector>
using namespace std;
const int N = 0;

int Solve(vector<int>ptr) {
	ptr[2] = 103;
	int n = ptr.size();

	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += ptr[i];
	}

	return sum;
}


vector<int>Check(vector<int>&a) {

	vector<int>ans{10, 11, 12, 12, 13, 14, 59, 10};

	return ans;
}

int main() {

	// int n;
	// cin >> n;
	// vector<int>v(n);
	// vector<int>v2;//This is a Vector of size 1.

	//vector<int>v1{2, 3, 4, 1, 7, 9};

	//v = v1;//You have copied all the values of v1 into v.

	//cout << v1.size() << endl;//This  size function Returns integer representing the size of the vector.
	//v.resize(2 * n);//This resize function helps you to resize your dynamic array.
	//v1.clear();//This Helps you to clear your vector.

//	cout << v1.empty() << endl;

	// for (int i = 0; i < n; i++) {
	// 	//You are trying to acces lets say index 3.
	// 	cin >> v[i];
	// }

	// int ans = Solve(v);

	// for (int i = 0; i < n; i++) {
	// 	cout << v[i] << " ";
	// }

	// cout << endl << ans << endl;

	// vector<int>value = Check(v);

	// for (int i = 0; i < value.size(); i++) {
	// 	cout << value[i] << " ";
	// }

	/*
		General Containers Properties:
		You can always copy a container of the same type into another.
		You can return a container from any function i.e it is treated as a data type only.
		You can Pass a container inside a function.
		COntainers By-default are passed by value only if you want to pass them
		by reference use a & operator.

	*/


	vector<int>mp;
	mp.push_back(56);
	mp.push_back(104);
	mp.push_back(111);

	for (int i = 0; i < mp.size(); i++) {
		cout << mp[i] << " ";
	}

	cout << endl;

	int n;
	cin >> n;
	cout << n << endl;
	vector<int>mp1;

	for (int i = 0; i < n; i++) {

		int x;
		cin >> x;

		mp1.push_back(x);
	}


	for (int i = 0; i < mp1.size(); i++) {
		cout << mp1[i] << " ";
	}




}