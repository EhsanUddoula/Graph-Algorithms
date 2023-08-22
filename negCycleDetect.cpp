#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const long long inf=1e17+10;

int n,m;

struct Edge{
    int a,b,cost;
};

vector<Edge>edge(N);
long long dis[N];

void bellman(int source){
    int p[n+1];
    int x;
    memset(p,-1,sizeof p);
    for(int i=0;i<n;i++){
        x=-1;
        for(auto e:edge){
            if(dis[e.b]>dis[e.a]+e.cost){
                dis[e.b] = min(dis[e.b], dis[e.a] + e.cost);
                p[e.b]=e.a;
                x=e.b;
            }
        }
    }

    if(x==-1){
        cout<<"No cycle\n";
    }
    else{
        int y=x;
        for(int i=0;i<n;i++){
            y=p[y];
        }

        vector<int> path;
        for (int cur = y;; cur = p[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());

        cout << "Negative cycle: ";
        for (int u : path)
            cout << u << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   
    cin>>n>>m;

    for(int i=0;i<n+3;i++){
        dis[i]=inf;
    }

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }

    bellman(1);


    return 0;
}