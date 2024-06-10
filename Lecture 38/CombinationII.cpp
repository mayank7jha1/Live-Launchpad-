class Solution {
public:
    vector<vector<int>>ans;

    void Solve(vector<int>&current, int index, int sum, vector<int>&a, int target) {

        if (sum == target) {
            ans.push_back(current);
            return;
        } else if (sum > target) {
            return;
        }



        for (int i = index; i < a.size(); i++) {
            if (i != index and a[i] == a[i - 1]) {
                continue;
            }
            current.push_back(a[i]);
            sum += a[i];
            Solve(current, i + 1, sum, a, target);
            sum -= a[i];
            current.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        vector<int>current;
        int sum = 0;
        sort(a.begin(), a.end());
        Solve(current, 0, sum, a, target);
        return ans;
    }
};