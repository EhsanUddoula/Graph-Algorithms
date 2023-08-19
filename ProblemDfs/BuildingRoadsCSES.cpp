#include<bits/stdc++.h>
using namespace std;
 
const int N=1e5+7;
 
vector<int> g[N];
vector<int> save;
bool vis[N];
 
void dfs(int ver){
    vis[ver]=true;
    for(int ch: g[ver]){
        if(vis[ch])continue;
        dfs(ch);
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ct=0;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        ct++;
        dfs(i);
        save.push_back(i);
    }
    if(ct==1)cout<<"0\n";
    else {
        cout<<ct-1<<endl;
        for(auto ch: save){
            if(ch!=1)cout<<ch-1<<' '<<ch<<endl;
        }
    }
 
    return 0;
}