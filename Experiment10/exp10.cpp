#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> bit;
    int maxVal;

    void update(int idx, int val) {
        while (idx <= maxVal) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 10001; 
        maxVal = 20001;  
        bit.assign(maxVal + 1, 0);
        
        vector<int> counts(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int mappedVal = nums[i] + offset;
            counts[i] = query(mappedVal - 1);
            update(mappedVal, 1);
        }
        
        return counts;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {5, 2, 6, 1};
    vector<int> nums2 = {-1};
    vector<int> nums3 = {-1, -1};

    auto printVec = [](const vector<int>& v) { cout << "["; for(int i=0; i<v.size(); ++i) cout << v[i] << (i==v.size()-1 ? "" : ","); cout << "]\n"; };
    
    cout << "Example 1 Output: "; printVec(sol.countSmaller(nums1));
    cout << "Example 2 Output: "; printVec(sol.countSmaller(nums2));
    cout << "Example 3 Output: "; printVec(sol.countSmaller(nums3));

    return 0;
}