#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while (n > 1) {
            for (int i = 0; i < n - 1; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            n--;
        }
        return nums.empty() ? 0 : nums[0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.triangularSum(nums);

    cout << result << "\n";

    return 0;
}