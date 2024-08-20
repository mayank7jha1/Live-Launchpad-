#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n;
int a[N], b[N], c[N];

/*
	dp[i][ch]: Maximum Hapiness till ith day by performing ch activity on the
			   ith day.

	//Time Complexity: O(3*1e5)*O(1) : ~~ O(1e5)
	//Space Complexity: O(3*1e5)


	int : +- 10^8
	long int : +- 10^12
	long long int : +- 10^18

	data store : print : 10^13: int

	#define : Macros: THis is a way to make a variable constant across the program>

	#define int long long: Poore Prgram me jaha jaha int likha hain usko long long bana do:  Like: 10^14

	My Main can only return an integer: But aapne to keh diya ki poore program me jaha jha int hain usko long long kardo:
	technically
	int main(){



	}

	long long main(){

	}

	which cannot happen:

	I have ensure ki #define int long long ssare int ko change kare except the
	main vaala int.

	By default mere pc me int : 64 - bit ka hain.

	main vale int ko 32 bit ka bana do

	isse ye hoga ki #define int long long sirf 64 bit vaale int  ko long long karega and hence mera main will be int only.
*/



int Solve() {
	int dp[N][3];

	dp[1][0] = a[1];
	dp[1][1] = b[1];
	dp[1][2] = c[1];

	for (int i = 2; i <= n; i++) {
		// int x = x + 1; //1 work
		// int y = y + 1; //1 work
		// int z = z + 1; //1 work

		dp[i][0] = a[i] + max(dp[i - 1][1], dp[i - 1][2]); // 1 work
		dp[i][1] = b[i] + max(dp[i - 1][2], dp[i - 1][0]); // 1 work
		dp[i][2] = c[i] + max(dp[i - 1][0], dp[i - 1][1]); // 1 work
	}



	return max({dp[n][0], dp[n][1], dp[n][2]});
}

int32_t main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}


	cout << Solve() << endl;
}