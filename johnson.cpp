#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 500;
vector <pair<int, int>> G[M];

vector <int> bellmanFord(int &N, vector <vector<int>> edges){
   
   for(int i = 1; i <= N; i++){
       edges.push_back({0, i, 0});
   }
  
   vector <int> d(N + 1, INT_MAX);
   d[0] = 0;
   while(true){
       bool check = false;
       for(auto e : edges){
           int u = e[0];
           int v = e[1];
           int w = e[2];
           if(d[v] > d[u] + w){
               d[v] = d[u] + w;
               check = true;
           }
       }
       if(!check)
           break;
   }

   return d;
}

void Dijkstra(int src, vector <vector<int>> &path, int &N){
   
   priority_queue<pair<int, int>> pq;
   vector <int> vis(N + 1);
   path[src][src] = 0;
   pq.push({0, src});
   while(!pq.empty()){
       int f = pq.top().second;
       pq.pop();
       if(!vis[f]){
           vis[f] = true;
           for(auto u : G[f]){
               int s = u.first;
               int w = u.second;
               if(path[src][f] + w < path[src][s]){
                   path[src][s] = path[src][f] + w;
                   pq.push({-path[src][s], s});
               }
           }
       }
   }
}

signed main(){
   
   int N, M;
   cin >> N >> M;
   
   vector <vector<int>> edges;
   for(int i = 1; i <= M; i++){
       int u, v, w;
       cin >> u >> v >> w;
       edges.push_back({u, v, w});
   }
   
   vector <int> C = bellmanFord(N, edges);
   for(int i = 0; i < M; i++){
       int u = edges[i][0];
       int v = edges[i][1];
       edges[i][2] += (C[u] - C[v]);
   }
  
   vector <vector<int>> path(N + 1, vector <int> (N + 1, INT_MAX));
   
   for(auto e : edges){
       G[e[0]].push_back({e[1], e[2]});
   }

   for(int i = 1; i <= N; i++){
       Dijkstra(i, path, N);
   }
   for(int i = 1; i <= N; i++){
       for(int j = 1; j <= N; j++){
           if(path[i][j] == INT_MAX)
               cout << -1 << " ";
           else
               cout << path[i][j] - (C[i] - C[j]) << " ";
       }
       cout << "\n";
   }
   return 0;
}   