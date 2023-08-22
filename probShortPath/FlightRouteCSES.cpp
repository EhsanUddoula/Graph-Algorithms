#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const long long inf=1e17+10;

int n,m,k;
vector<pair<int,int>>gr[N];
vector<long long>dis[N];

void dijk(int source){
    multiset<pair<long long,int>>st;
    st.insert({0LL,source});

    while(st.size()){
        auto child=*st.begin();
        long long dist=child.first;
        int node=child.second;
        st.erase(st.begin());
        if(dis[node].size()==k)continue;
        dis[node].push_back(dist);
        for(auto ch: gr[node]){
            st.insert({dist+ch.second*1LL,ch.first});
        }
    }

    for(int i=0;i<k;i++){
        cout<<dis[n][i]<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 

    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        gr[u].push_back({v,wt});
    }

    dijk(1);

    return 0;
}