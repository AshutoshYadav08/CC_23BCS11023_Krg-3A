#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            int current_max = 0;
            for (int j = 1; j <= k && i - j >= 0; ++j) {
                current_max = max(current_max, arr[i - j]);
                
                dp[i] = max(dp[i], dp[i - j] + current_max * j);
            }
        }
        
        return dp[n];
    }
};
