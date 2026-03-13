#include <bits/stdc++.h>
using namespace std;


int main(){

    int n;cin>>n;
    vector<int> tokens(n);

    for(int i = 0;i<n;i++) cin>>tokens[i];
    int power;cin>>power;



    sort(tokens.begin(),tokens.end());

    int l = 0;
    int r = n-1;
    int maxScore = 0;
    int score = 0;
    while(l < r){

        if(power >= tokens[l]){
            score++;
            power -= tokens[l];
            l++;
        }

        else if(score > 0 ){
            power += tokens[r];
            r--;
            score--;
        }
        else break;

        maxScore = max(score,maxScore);

    }

    cout<<maxScore;
    



}