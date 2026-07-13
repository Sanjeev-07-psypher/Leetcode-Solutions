class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num="123456789";
        int len=2;
        vector<int> ans;
        int n=stoi(num.substr(0,len));
        string add="11";
        while(true){
            if(n>=low && n<=high){
                ans.push_back(n);
            }
            if(n>high) break;
            if(n%10==9){
                len++;
                if(len>9)break;
                n=stoi(num.substr(0,len));
                add=add+'1';
                continue;
            }
            n+= stoi(add);
        }
        return ans;
    }
};