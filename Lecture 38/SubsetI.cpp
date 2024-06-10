#include<bits/stdc++.h>
using namespace std;
const int N = 0;


class Solution {
    vector<vector<int>>ans;

    void Solve(vector<int>&nums, int index, vector<int>&Current, int n) {

        if (index == n) {
            ans.push_back(Current);
            return;
        }

        //Not Taking the element.
        Solve(nums, index + 1, Current, n);

        //Taking the element.
        Current.push_back(nums[index]);
        Solve(nums, index + 1, Current, n);
    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>Current;
        Solve(nums, 0, Current, n);
        return ans;
    }
};



int main() {

}