class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        int ans=1e7;
        int n=v.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int sum=v[i]+v[j]+v[k];
                    if(abs(sum-target)<abs(ans-target)){
                        ans=sum;
                    }
                }
            }
        }
        return ans;
    }
};