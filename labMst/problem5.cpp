#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;cin>>n;
    vector<int> nums(n);

    for(int i = 0;i<n;i++) cin>>nums[i];

    int result = 0;
    for(int i = 0;i<=31;i++){
        int cnt = 0;
        for(auto x : nums) {
            if((x & (1<<i)) != 0) cnt++; 
        }
        if(cnt%3 != 0) result = result | (1<<i);
    }

    cout<<result;



}
