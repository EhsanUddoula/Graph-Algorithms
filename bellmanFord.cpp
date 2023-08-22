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
    dis[source]=0;
    int p[n+1];
    memset(p,-1,sizeof p);
    for(;;){
        bool any=false;
        for(auto e:edge){
            if(dis[e.a]<inf){
                if(dis[e.b]>dis[e.a]+e.cost){
                    dis[e.b]=dis[e.a]+e.cost;
                    p[e.b]=e.a;
                    any=true;
                }
            }
        }
        if(!any)break;
    }
    //distance printing

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<"\n";
    //path printing
    vector<int>path;
    if(dis[n]==inf)cout<<"No path\n";
    else{
        for(int i=n;i!=1;i=p[i]){
            path.push_back(i);
        }
        path.push_back(1);

        reverse(path.begin(),path.end());
        for(auto i : path){
            cout<<i<<" ";
        }
        cout<<endl;
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