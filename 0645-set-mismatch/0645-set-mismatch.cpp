class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(2);
        vector<bool> present(n);
        vector<int> freq(n,0);
        for(int i=0;i<n;i++){
            int j=nums[i];
            j--;
            freq[j]++;
            present[j]=true;
        }
        for(int i=0;i<n;i++){
            if(freq[i]==2){
                ans[0]=i+1;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(!present[i]){
                ans[1]=i+1;
                break;
            }
        }
        return ans;
    }
};