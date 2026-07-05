class Solution {
public:
    int maxDig(int n){
        int mx=0;
        while(n>0){
            int rem=n%10;
            mx=max(mx,rem);
            n/=10;
        }
        return mx;
    }
    int minDig(int n){
        int mn=1e9;
        while(n>0){
            int rem=n%10;
            mn=min(mn,rem);
            n/=10;
        }
        return mn;
    }
    bool fxn(int n,int range){
        int mx=0;
        int mn=1e9;
        while(n>0){
            int rem=n%10;
            mx=max(mx,rem);
            mn=min(mn,rem);
            n/=10;
        }
        return mx-mn==range;
    }
    int maxDigitRange(vector<int>& v) {
        int n=v.size();
        vector<int> track(n,0);
        int maxDigrange=0;
        for(int i=0;i<n;i++){
            int mx=maxDig(v[i]);
            int mn=minDig(v[i]);
            maxDigrange=max(maxDigrange,mx-mn);
        }
        for(int i=0;i<n;i++){
            if(fxn(v[i],maxDigrange)){
                track[i]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(track[i]) ans+=v[i];
        }
        return ans;
    }
};