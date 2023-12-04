 #include<bits/stdc++.h>
    using namespace std;
 
    #define INF 1000000007
 
    vector<int> gr[100005];
    vector<int> tgr[100005];
    bool vis[100005];
    vector<int> topo;
    vector<int> ans;
 
    
    void dfs(int ver){
        vis[ver]=true;
        for(auto ch: gr[ver]){
            if(vis[ch])continue;
            dfs(ch);
        }
        topo.push_back(ver);
    }
 
    void dfs2(int ver){
        vis[ver]=true;
        for(auto ch: tgr[ver]){
            if(vis[ch])continue;
            dfs2(ch);
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
            tgr[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            dfs(i);
        }
 
        memset(vis,0,sizeof vis);
        reverse(topo.begin(),topo.end());
        vector<int > vec(n+2);
        int k=1;
        for(int i: topo){
            if(!vis[i]){
                ans.clear();
                dfs2(i);
                for(int i: ans){
                    vec[i]=k;
                }
                k++;
            }
        }
        cout<<k-1<<endl;
        for(int i=1;i<=n;i++){
            cout<<vec[i]<<" ";
        }
        
        cout<<"\n";
 
        return 0;
    }
