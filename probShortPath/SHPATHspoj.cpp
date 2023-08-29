#include<bits/stdc++.h>
using namespace std;

const int inf=1000000009;

bool vis[10005];
vector<pair<int,int>>gr[10005];
int dis[10005];


void dijkstra(int source,int dest){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater <pair<int,int>>>st;
    st.push({0,source});
    dis[source]=0;

    while(st.size()){
        auto child=st.top();
        int node=child.second;
        st.pop();
        if(node==dest)return;
        if(vis[node])continue;
        vis[node]=true;
        for(auto ch: gr[node]){
            if(dis[ch.first]>dis[node]+ch.second){
                dis[ch.first]=dis[node]+ch.second;
                st.push({dis[ch.first],ch.first});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t,n,m,r,i;
    cin>>t;
    
    while(t--){
        unordered_map<string,int>mp;
        cin>>n;
        for(i=1;i<=n;i++){
            string s;
            cin>>s;
            mp[s]=i;
            cin>>m;
            for(int j=0;j<m;j++){
                int a,b;
                cin>>a>>b;
                gr[i].push_back({a,b});
            }
        }
        cin>>r;
        while(r--){
            string s,ts;
            cin>>s>>ts;
            for(int j=0;j<=n;j++){
                dis[j]=inf;
                vis[j]=false;
            }
            dijkstra(mp[s],mp[ts]);
            printf("%d\n",dis[mp[ts]]);
        }
        for(int j=0;j<n+1;j++){
            gr[j].clear();
            vis[j]=false;
        }
    }


    return 0;
}