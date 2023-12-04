#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int>gr[N];
int in[N],out[N],inTime[N],outTime[N],vis[N];
int inTimer=0,outTimer=0;

void dfs(int ver){
    inTimer++;
    vis[ver]=1;
    inTime[ver]=inTimer;

    for(auto ch: gr[ver]){
        if(vis[ch])continue;
        dfs(ch);
    }

    outTimer++;
    outTime[ver]=outTimer;
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
        in[b]++;
        out[a]++;
    }

    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        dfs(i);
    }

    for(int i=1;i<=n;i++){
        cout<<"For "<<i<<":"<<endl;
        cout<<"Indegree- "<<in[i]<<" Outdegree- "<<out[i]<<" InTime- "<<inTime[i]<<" OutTime- "<<outTime[i]<<endl;
    }


    return 0;
}