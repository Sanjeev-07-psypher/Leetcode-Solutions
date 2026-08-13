class Solution {
public:
    struct Node {
        int pre,suf,mx,len;
        char l,r;
    };

    vector<Node> st;

    Node merge(Node a,Node b){
        if(a.len==0) return b;
        if(b.len==0) return a;

        Node c;
        c.len=a.len+b.len;
        c.l=a.l;
        c.r=b.r;
        c.pre=a.pre;
        c.suf=b.suf;
        c.mx=max(a.mx,b.mx);

        if(a.r==b.l){
            c.mx=max(c.mx,a.suf+b.pre);
            if(a.pre==a.len)c.pre=a.len+b.pre;

            if(b.suf==b.len)c.suf=b.len+a.suf;
        }

        return c;
    }

    void build(int p,int l,int r,string &s){
        if(l==r){
            st[p]={1,1,1,1,s[l],s[l]};
            return;
        }
        int m=(l+r)/2;
        build(p*2,l,m,s);
        build(p*2+1,m+1,r,s);
        st[p]=merge(st[p*2],st[p*2+1]);
    }

    void update(int p,int l,int r,int idx,char ch){
        if(l==r){
            st[p]={1,1,1,1,ch,ch};
            return;
        }
        int m=(l+r)/2;
        if(idx<=m) update(p*2,l,m,idx,ch);
        else  update(p*2+1,m+1,r,idx,ch);

        st[p]=merge(st[p*2],st[p*2+1]);
    }

    vector<int> longestRepeating(string s,string queryCharacters,vector<int>& queryIndices){
        int n=s.size();
        int k=queryCharacters.size();
        st.resize(4*n+5);
        build(1,0,n-1,s);
        vector<int> ans;
        for(int i=0;i<k;i++){
            update(1,0,n-1,queryIndices[i],queryCharacters[i]);
            ans.push_back(st[1].mx);
        }

        return ans;
    }
};