#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;

int dist[20][20];
int memo[1 << 20][20];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }















    
    if (memo[mask][pos] != -1) {
        return memo[mask][pos];
    }

    int ans = INF;
    
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { 
            int current_cost = dist[pos][city] + tsp(mask|(1<<city),city);
            ans = min(ans,current_cost );
        }
    }

    return memo[mask][pos] = ans;
}

int main() {
    n = 2; 
    int graph[2][2] = {
        {0,111},
        {112,0}
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }


    memset(memo, -1, sizeof(memo));

    cout<<"Minimum cost:"<<tsp(1, 0)<<"\n";

    return 0;
}
