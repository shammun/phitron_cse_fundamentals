#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
    public:
      /*  Function to implement Bellman Ford
       *   edges: vector of vectors which represents the graph
       *   src: source vertex
       *   V: number of vertices
       */
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
          // Code here
          vector<int> dist(V, 100000000);
          dist[src] = 0;
          
          for(int i=0; i< V-1; i++){
              for(auto edge : edges){
                  int u = edge[0];
                  int v = edge[1];
                  int w = edge[2];
                  if(dist[u] != 100000000 && dist[u] + w < dist[v]){
                      dist[v] = dist[u] + w;
                  }
              }
          }
          
          for(auto edge : edges){
              int u = edge[0];
              int v = edge[1];
              int w = edge[2];
              if(dist[u] != 100000000 && dist[u] + w < dist[v]){
                  return {-1};
              }
          }
          return dist;
      }
  };

  // Driver Code Starts.

int main() {
    int t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;
        
        vector<vector<int>> edges;
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            
            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }
        
        int src;
        cin >> src;
        cin.ignore();
        
        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);
        
        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i];
            if (i != res.size() - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}

// Driver Code Ends