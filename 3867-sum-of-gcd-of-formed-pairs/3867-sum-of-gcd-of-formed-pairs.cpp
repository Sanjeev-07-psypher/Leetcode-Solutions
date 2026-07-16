class Solution {
public:
    long long gcd(long long a,long long b){
        a=llabs(a);
        b=llabs(b);
        while(b){
            long long rem=b;
            b=a%b;
            a=rem;
        }
        return a;
    }
    long long gcdSum(vector<int>& v) {
        long long ans=0;
        int n=v.size();
        int mx=v[0];
        vector<int> prefix(n);
        for(int i=0;i<n;i++){
            mx=max(mx,v[i]);
            prefix[i]=gcd(v[i],mx);
        }
        sort(prefix.begin(),prefix.end());
        int l=0,r=n-1;
        while(l<r){
            ans+= gcd((long long)prefix[l],(long long)prefix[r]);
            l++;
            r--;
        }
        return ans;
    }
};