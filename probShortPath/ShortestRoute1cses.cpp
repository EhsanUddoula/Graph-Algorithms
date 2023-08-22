#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const long long inf=1e17+10;

vector<pair<int,int>>gr[N];
vector<long long>dis(N,inf);
int vis[N];

void dijkstra(int source){
    set<pair<long,long>>st;
    st.insert({0,source});
    dis[source]=0;
    while(st.size()){
        auto child=*st.begin();
        int dist=child.first;
        int node=child.second;
        st.erase(st.begin());
        if(vis[node])continue;
        vis[node]=1;
        for(auto ch: gr[node]){
            if(dis[node]+ch.second*1LL<dis[ch.first]){
                dis[ch.first]=dis[node]+ch.second*1LL;
                st.insert({dis[ch.first],ch.first*1LL});
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        gr[u].push_back({v,wt});
        //gr[v].push_back({u,wt});
    }

    dijkstra(1);

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<"\n";


    return 0;
}