#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int>gr[N];
vector<int>tgr[N];
vector<int>compo;

vector<int>topo;
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
    compo.push_back(ver);
    for(auto ch: tgr[ver]){
        if(vis[ch])continue;
        dfs1(ch);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        gr[a].push_back(b);
        tgr[b].push_back(a);
    }
    memset(vis,false, sizeof(vis));
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        dfs(i);
    }
    reverse(topo.begin(),topo.end());
    memset(vis,false, sizeof(vis));

    for(auto i: topo){
        if(vis[i])continue;
        dfs1(i);
        for(auto j: compo){
            cout<<j<<" ";
        }
        cout<<endl;
        compo.clear();
    }


    return 0;
}