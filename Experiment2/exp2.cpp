#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) {
            return n;
        }

        int max_count = 0;

        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> slopes;
            int duplicates = 1; 

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                int common_divisor = gcd(dx, dy);
                dx /= common_divisor;
                dy /= common_divisor;

                slopes[{dx, dy}]++;
            }

            int current_max_for_i = 0;
            for (auto const& [slope, count] : slopes) {
                current_max_for_i = max(current_max_for_i, count);
            }
            
            max_count = max(max_count, current_max_for_i + duplicates);
        }

        return max_count;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << "Max points on a line: " << sol.maxPoints(points) << "\n"; 
    
    vector<vector<int>> points2 = {{1,1},{2,2},{3,3}};
    cout << "Max points on a line: " << sol.maxPoints(points2) << "\n"; 

    return 0;
}
