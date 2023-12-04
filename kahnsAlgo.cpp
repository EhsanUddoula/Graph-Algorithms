#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int>gr[N];

int indeg[N];
vector<int>ans;

void kahn(int n){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)q.push(i);
    }
    while(!q.empty()){
        int ver=q.front();
        ans.push_back(ver);
        q.pop();
        for(auto ch: gr[ver]){
            indeg[ch]--;
            if(indeg[ch]==0)q.push(ch);
        }
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
        indeg[b]++;
    }

    kahn(n);

    cout<<"TopoSort- "<<endl;
    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}