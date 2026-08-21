class Solution {
public:
    long long count(vector<int>& v, long long x) {
        int n=v.size();
        long long ans=0;

        for(int mask=1;mask<(1<<n);mask++){
            long long l=1;
            int bits=0;
            bool ok=1;

            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    bits++;
                    long long g=__gcd(l,(long long)v[i]);
                    l=l/g*v[i];
                    if(l>x){
                        ok=0;
                        break;
                    }
                }
            }

            if(!ok) continue;

            if(bits&1) ans+=x/l;
            else ans-=x/l;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& v, int k) {
        long long l=1;
        long long r=1LL*(*min_element(v.begin(),v.end()))*k;

        while(l<r){
            long long m=l+(r-l)/2;
            if(count(v,m)>=k) r=m;
            else l=m+1;
        }
        return l;
    }
};