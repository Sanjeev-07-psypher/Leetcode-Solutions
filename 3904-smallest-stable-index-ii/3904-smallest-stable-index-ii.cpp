class Solution {
public:
    int firstStableIndex(vector<int>& v, int k) {
        int n=v.size();
        int ans=-1;
        int currk=k;
        int max=v[0];
        vector<int> aux(n);
        aux[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            aux[i]=min(v[i],aux[i+1]);
        }
        int idx=1;
        int min=aux[0];
        for(int i=0;i<n;i++){
            if(max<=v[i]){
                max=v[i];
            }
            min=aux[i];
            if(max-min<=currk){
                if(ans==-1)
                    ans=i;
                else if(i<ans)
                    ans=i;
                // currk=max-min;
            }
            
        }
        return ans;
    }
};