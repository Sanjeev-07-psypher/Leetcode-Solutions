class Solution {
public:
    bool isBipartiteUtil(int start,vector<vector<int>>& graph,vector<int>&color){
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            for(auto neigh: graph[curr]){
                if(color[neigh]==-1){
                    int nextCol = color[curr]==0 ? 1 : 0;
                    color[neigh]=nextCol;
                    q.push(neigh);
                }
                else if(color[neigh]==color[curr]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!isBipartiteUtil(i,graph,color)){
                    return false;
                }
            }
        }
        return true;
    }
};