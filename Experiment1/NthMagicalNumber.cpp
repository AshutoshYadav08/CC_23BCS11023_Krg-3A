const int mod=1e9+7;
class Solution {
public:

    long long gcd(long long a,long long b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    long long lcm(long long a,long long b){
        return a/gcd(a,b)*b;
    }



    int nthMagicalNumber(int n, int a, int b) {
        long long ans=0;
        long long l=1,r=2e18;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if((mid/a) + (mid/b) - (mid/lcm(a,b))>=n){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans%mod;
    }
};