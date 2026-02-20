#include <bits/stdc++.h>
using namespace std;



int main(){

    int MOD = 1e9+7;
    int n = 3;
    vector<int> arr = {1,3,5};


    long long ans = 0;
    for (int i = 0; i < 32; i++) {
        int count1 = 0;
        for (int val : arr) {
            if ((val >> i) & 1) count1++;
        }
        ans = (ans + (1LL * count1 * (n - count1)) % MOD) % MOD;
    }

    cout<<ans*2<<endl;
    return 0;

}
