#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int LCS(string &s, string &t, int i, int j) {

	//Base Condition:

	if (i >= s.length() or j >= t.length()) { //Indexing is 0 to s.length-1 tak or 0 to t.length-1 tak.

		return 0;
	}



	if (s[i] == t[j]) {

		int ans = 1 + LCS(s, t, i + 1, j + 1);
		return ans;

	} else {

		int Op1 = LCS(s, t, i + 1, j);//Assumed jth character of string t is part of LCS.

		int Op2 = LCS(s, t, i, j + 1);//Assumed ith character of string s is part of LCS.

		int ans = max(Op1, Op2);
		return ans;

	}


}

int longestCommonSubsequence(string s, string t) {

	return LCS(s, t, 0, 0);
}



int main() {
	string s, t;
	cin >> s >> t;

	cout << longestCommonSubsequence(s, t) << endl;
}

// string s = "";
// string t = "abcdeg";


/*

Solve(0, 3);  State

LCS from 0 - 0 index in string 1 and 3 - 5 index in string 2;

ans = 0;


string s = "abd";
string t = "abcdegza";


Solve(0, 0): LCS from (0 - 2) index in string1 and (0 - 7) index in string2.

Solve(3,2): LCS from 3--2 Index in string 1 and (2-7) index in string2.
ans=0;



Solve(1,8): LCS from 1-2 index in string1 and 8-7 index in string 2.
ans=0;

*/