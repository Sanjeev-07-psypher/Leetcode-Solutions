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

    void visitedNodes(vector<bool>& visited,int node){
        visited[node]=true;

        for(auto &e:adj[node]){
            if(!visited[e.dest]){
                visitedNodes(visited,e.dest);
            }
        }
    }

    bool check(vector<bool>& visited){
        int totalNodes=0;
        int degreeSum=0;

        for(int i=0;i<V;i++){
            if(visited[i]){
                totalNodes++;
                degreeSum += adj[i].size();
            }
        }

        int totalEdges = degreeSum/2;

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

        vector<bool> globalVisited(n,false);
        int ans=0;

        for(int i=0;i<n;i++){

            if(!globalVisited[i]){

                vector<bool> component(n,false);

                g.visitedNodes(component,i);

                for(int j=0;j<n;j++){
                    if(component[j]){
                        globalVisited[j]=true;
                    }
                }

                if(g.check(component)){
                    ans++;
                }
            }
        }

        return ans;
    }
};