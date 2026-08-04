class Solution {
public:
    vector<int> findMissingElements(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        vector<int> ans;
        int num=*min_element(v.begin(),v.end());
        for(int i=0;i<n;i++){
            
                while(v[i]!=num){
                    ans.push_back(num);
                    num++;
                }
            num++;
        }
        return ans;

    }
};