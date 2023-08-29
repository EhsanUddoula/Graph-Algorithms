#include<bits/stdc++.h>
using namespace std;

const int N=2515;
const long long inf=1e17+10;

struct Edge{
    int a,b,cost;
};

vector<Edge>edge;
long long dis[N],dis1[N];
int n,m;

bool cycle(int source){
    for(int i=0;i<=n;i++)dis1[i]=inf;
    int x;
    for(int i=0;i<n;i++){
        x=-1;
        for(auto e:edge){
            if(dis1[e.b]>dis1[e.a]+e.cost*1LL){
                dis1[e.b] = min(dis1[e.b], dis1[e.a] + e.cost*1LL);
                x=e.a;
            }
        }
    }
    if(x==-1)return true;
    else return false;
}

void bellman(int source){

    for(int i=0;i<=n;i++)dis[i]=inf;
    dis[source]=0LL;
    for(int i=0;i<n-1;i++){
        bool any=false;
        for(auto e: edge){
            if(dis[e.a]<inf){
                if(dis[e.b]>dis[e.a]+e.cost*1LL){
                    dis[e.b]=dis[e.a]+e.cost*1LL;
                    any=true;
                }
            }   
        }
        if(!any)break;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    int u,v,wt;
    edge.resize(n);
    for(int i=0;i<m;i++){
        cin>>u>>v>>wt;
        edge.push_back({u,v,-wt});
    }
    if(cycle(1)){
        bellman(1);
        cout<<-dis[n]<<"\n";
    }
    else {
        bellman(1);
        long long y=dis[n];
        for(auto e: edge){
            if(dis[e.a]<inf){
                if(dis[e.b]>dis[e.a]+e.cost*1LL){
                    dis[e.b]=dis[e.a]+e.cost*1LL;
                }
            }
        }
        if(dis[n]==y)cout<<-dis[n]<<"\n";
        else
         cout<<-1<<"\n";
    }

    return 0;
}