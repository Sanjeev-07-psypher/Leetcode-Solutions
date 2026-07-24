class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool> has(2048,false);
        vector<int> unq;
        for(int x:nums){
            if(!has[x]){
                has[x]=true;
                unq.push_back(x);
            }
        }
        
        vector<bool> pxor(2048,false);
        int k=unq.size();
        for(int i=0; i<k; i++){
            for(int j=i; j<k; j++){
                pxor[unq[i]^unq[j]]=true;
            }
        }
        
        vector<bool> txor(2048,false);
        int ans=0;
        for(int i=0; i<2048; i++){
            if(pxor[i]){
                for(int x:unq){
                    int val=i^x;
                    if(!txor[val]){
                        txor[val]=true;
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};