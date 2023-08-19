#include<bits/stdc++.h>
using namespace std;

int cat[100005],res,m;

void dfs(int ver,vector<int>graph[],int par,int maxc,int ct){
    if(cat[ver])ct++;
    else ct=0;
    maxc=max(ct,maxc);
    int height=0;
    for(int ch: graph[ver]){
        if(ch==par)continue;
        dfs(ch,graph,ver,maxc,ct);
        height++;
    }
    if(height==0&&maxc<=m)res++;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cat[i];
    }
    int v1,v2;
    vector<int>graph[n+1];
    for(int i=0;i<n-1;i++){
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1,graph,0,0,0);
    cout<<res<<"\n";

    return 0;
}