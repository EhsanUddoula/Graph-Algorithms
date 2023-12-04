#include<bits/stdc++.h>
using namespace std;

#define mod 1000000000
#define N 200005

vector<int>gr[N];
vector<int>tgr[N];
vector<int>adj[N];
vector<int>topo;
vector<int>comp;
bool vis[N];

void dfs(int ver){
    vis[ver]=true;

    for(auto ch: gr[ver]){
        if(vis[ch])continue;
        dfs(ch);
    }

    topo.push_back(ver);
}

void dfs1(int ver){
    vis[ver]=true;
    comp.push_back(ver);

    for(auto ch: tgr[ver]){
        if(vis[ch])continue;
        dfs1(ch);
    }
} 
void dfs2(int ver){
    vis[ver]=true;
    comp.push_back(ver);

    for(auto ch: adj[ver]){
        if(vis[ch])continue;
        dfs2(ch);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        tgr[b].push_back(a);
    }

    memset(vis, false,sizeof vis);
    topo.clear();
    comp.clear();
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        dfs(i);
    }

    memset(vis, false,sizeof vis);
    int ct=0;
    reverse(topo.begin(),topo.end());
    vector<int>root_nodes;
    int roots[N];
    for(auto i: topo){
        if(vis[i])continue;
        dfs1(i);

        if(comp.size()<=1)ct=ct;
        else ct+=comp.size(), root_nodes.push_back(comp.front());
        int root = comp.front();
        for (auto u : comp) roots[u] = root;

        comp.clear();
    }

    for (int v = 1; v <= n; v++){
        for (auto u : gr[v]) {
            int root_v = roots[v],
                root_u = roots[u];

            if (root_u != root_v)
                adj[root_u].push_back(root_v);
        }
    }
    memset(vis, false,sizeof vis);
    comp.clear();

    for(auto i: root_nodes){
        if(vis[i])continue;
        dfs2(i);
        ct+=comp.size()-1;
        comp.clear();
    }

    cout<<ct<<endl;





    return 0;
}