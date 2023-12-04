#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int>gr[N];

bool vis[N];
vector<int>ans;

void dfs(int ver){
    vis[ver]=true;
    for(auto ch:gr[ver]){
        if(vis[ch])continue;
        dfs(ch);
    }
    ans.push_back(ver);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        gr[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        dfs(i);
    }

    reverse(ans.begin(),ans.end());
    cout<<"TopoSort- "<<endl;
    for(auto i: ans){
        cout<<i<<" ";
    }


    return 0;
}