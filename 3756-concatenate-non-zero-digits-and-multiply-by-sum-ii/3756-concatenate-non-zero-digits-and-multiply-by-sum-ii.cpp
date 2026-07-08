class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        using ll=long long;
        ll MOD=1e9+7;
        int n=s.size();  
        vector<ll> p10(n+1,1);
        for(int i=1;i<=n;i++){
            p10[i]=(p10[i-1]*10)%MOD;
        }
        
        vector<ll> prefV={0};
        vector<ll> prefS={0};
        vector<int> mapIdx(n);

        int nz=0;
        
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                nz++;
                prefV.push_back((prefV.back()*10+(s[i]-'0'))%MOD);
                prefS.push_back(prefS.back()+(s[i]-'0'));

            }
            mapIdx[i]=nz;
        }
        
        vector<int> ans;
        for(auto &q:queries){
            int l=q[0], r=q[1];
            int R=mapIdx[r];
            int L=(l==0)?0:mapIdx[l-1];
            
            if(R==L){
                ans.push_back(0);
            } else {
                int len=R-L;
                ll x=(prefV[R]-prefV[L]*p10[len])%MOD;
                
                if(x<0) x+=MOD;
                
                ll sum=prefS[R]-prefS[L];
                ans.push_back((x*sum)%MOD);
            }
        }
        return ans;
    }
};