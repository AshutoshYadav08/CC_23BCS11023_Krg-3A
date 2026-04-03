#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        queue<pair<int, int>> q;
        q.push({src, 0});

        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        int stops = 0;
        while (!q.empty() && stops <= k) {
            int sz = q.size();
            while (sz--) {
                auto [node, cost] = q.front();
                q.pop();
                
                for (const auto& edge : adj[node]) {
                    int neighbor = edge.first;
                    int price = edge.second;
                    
                    if (cost + price < dist[neighbor]) {
                        dist[neighbor] = cost + price;
                        q.push({neighbor, cost + price});
                    }
                }
            }
            stops++;
        }
        
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

int main() {
    Solution sol;
    
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0, dst = 3, k = 1;
    
    cout << "Cheapest price: " << sol.findCheapestPrice(n, flights, src, dst, k) << "\n";
    return 0;
}
