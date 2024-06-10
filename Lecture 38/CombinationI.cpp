#include<bits/stdc++.h>
using namespace std;
const int N = 0;


class Solution {
public:

    vector<vector<int>>ans;

    void Solve(vector<int>&current, int sum, int index, int target, vector<int>&a) {

        if (sum == target) {
            ans.push_back(current);
            return;
        } else if (sum > target) {
            return;
        }

        int n = a.size();

        for (int i = index; i < n; i++) {

            if (i != index and a[i] == a[i - 1]) {
                continue;
            }

            current.push_back(a[i]);
            sum += a[i];

            Solve(current, sum, i + 1, target, a);

            //You will backtracking

            sum -= a[i];
            current.pop_back();

        }


    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<int>current;
        int sum = 0;

        sort(candidates.begin(), candidates.end());
        Solve(current, sum, 0, target, candidates);

        return ans;

    }
};



int main() {

}
