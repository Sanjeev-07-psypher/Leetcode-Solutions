class Solution {
public:
    int gcd(int a,int b){
        a=abs(a);
        b=abs(b);
        while(b){
            int rem=b;
            b=a%b;
            a=rem;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        return gcd(mn,mx);
    }
};