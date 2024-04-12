#include<bits/stdc++.h>
using namespace std;
const int N = 0;

void Solve(int* x, int* y) {

	*x = (*x) * --(*y);
}

int main() {
	int n = 30;
	Solve(&n, &n);
	cout << n << endl;
	cout << 30 * 29 << endl;

	string s = "CelebAI.";
	s.back() = '!';
	cout << s << endl;

	string st = "spaces in text";
	st.erase(remove(st.begin(), st.end(), ' '), st.end());
	cout << st << endl;

}