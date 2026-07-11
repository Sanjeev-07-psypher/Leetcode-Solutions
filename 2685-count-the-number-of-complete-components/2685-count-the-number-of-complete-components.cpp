class Edge{
public:
    int src;
    int dest;

    Edge(int u,int v){
        src=u;
        dest=v;
    }
};

class Graph{
public:
    int V;
    vector<vector<Edge>> adj;

    Graph(int V){
        this->V=V;
        adj.resize(V);
    }

    void addEdge(int u,int v){
        adj[u].push_back(Edge(u,v));
        adj[v].push_back(Edge(v,u));
    }

    void visitedC(vector<bool>& visited,vector<bool>& global,int i){
        visited[i]=true;
        global[i]=true;
        for(auto &e: adj[i]){
            if(!visited[e.dest]){
                visitedC(visited,global,e.dest);
            }
        }
    }

    bool count(vector<bool>& visited,int i){
        int totalNodes=0;
        int degSum=0;
        for(int i=0;i<V;i++){
            if(visited[i]){
                totalNodes++;
                degSum+=adj[i].size();
            }
        }
        int totalEdges=degSum/2;
        return totalEdges == (totalNodes*(totalNodes-1))/2;
    }


    
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        Graph g(n);

        for(auto &e:edges){
            g.addEdge(e[0],e[1]);
        }

        int ans=0;
        vector<bool> globalVisited(n+1,false);
        for(int i=0;i<n;i++){
            vector<bool> components(n+1,false);
            if(!globalVisited[i]){
                g.visitedC(components,globalVisited,i);
                if(g.count(components,i)){
                    ans++;
                }
            }
        }

        return ans;
    }
};