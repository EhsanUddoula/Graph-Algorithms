#include<bits/stdc++.h>
using namespace std;

#define N 100005

vector<int>gr[N];
bool vis[N];
int inTime[N];
int ct=0;

void dfs(int ver){
    vis[ver]=true;
    inTime[ver]=ct++;
    for(auto ch: gr[ver]){
        if(vis[ch])continue;
        dfs(ch);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        dfs(i);
    }

    for(int i=1;i<=n;i++){
        cout<<inTime[i]<<endl;
    }


    return 0;
}