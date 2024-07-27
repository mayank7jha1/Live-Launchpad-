#include<bits/stdc++.h>
using namespace std;
const int N = 0;


class Solution {
public:
	vector<int> advantageCount(vector<int>& a, vector<int>& b1) {

		int n = a.size();

		sort(a.begin(), a.end());

		vector<pair<int, int>>b;

		for (int i = 0; i < n; i++) {
			b.push_back({b1[i], i});
		}

		sort(b.begin(), b.end());

		vector<int>ans(n, -1);
		vector<int>extra;

		int j = 0;//J is to iterate over ans.

		for (int i = 0; i < n; i++) {

			if (a[i] > b[j].first) {
				ans[b[j].second] = a[i];
				j++;
			} else {
				extra.push_back(a[i]);
			}
		}



		if (extra.size() == 0) {
			return ans;
		}

		j = 0; //Extra par iterate karna hain.

		for (int i = 0; i < n; i++) {

			if (ans[i] == -1) {
				ans[i] = extra[j];
				j++;
			}

			if (j == extra.size()) {
				break;
			}
		}

		return ans;
	}
};


class Solution {
public:
	vector<int> advantageCount2(vector<int>& a, vector<int>& b) {

		set<int>s;

		for (auto x : a) {
			s.insert()
		}

	}
};




int main() {

}