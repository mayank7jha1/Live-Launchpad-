

class Solution {
public:
    vector<vector<int>>ans;

    void Solve(vector<int>&current, int k, int n, int sum, int size, int element ) {

        if (size == k and sum == n) {
            ans.push_back(current);
            return;
        } else if (sum > n or size > k) {
            return;
        }



        for (int i = element; i <= 9; i++) {
            current.push_back(i);
            sum += i;
            Solve(current, k, n, sum, size + 1, i + 1);

            sum -= i;
            current.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>current;
        int sum = 0;
        Solve(current, k, n, 0, 0, 1);
        return ans;
    }
};


