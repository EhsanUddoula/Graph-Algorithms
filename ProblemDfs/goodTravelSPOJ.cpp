#include<bits/stdc++.h>
    using namespace std;
 
    #define INF 1000000007
 
    vector<int>gr[1000005];
    vector<int>tgr[1000005];
    vector<int>topo;
    bool vis[1000005];
    vector<int>compo;
    unordered_map<int, unordered_set<int> >mp(1000005);
    long long ans[1000005];
    int s,e;
 
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
        compo.push_back(ver);
 
        for(auto ch: tgr[ver]){
            if(vis[ch])continue;
            dfs2(ch);
        }
    }
 
    void solve(int ver,long long dp[],int roots[]){
        if(ver==roots[e])return;
        for(auto i: mp[ver]){
            ans[i]=max(ans[i],ans[ver]+dp[i]);
            solve(i,dp,roots);
        }
    }
 
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
 
        int n,m;
        cin>>n>>m>>s>>e;
        int fi[n+5];
        for(int i=1;i<=n;i++){
            cin>>fi[i];
            ans[i]=-1;
        }
        int a,b;
        memset(vis,0,sizeof vis);
        topo.clear();
 
        for(int i=0;i<m;i++){
            cin>>a>>b;
            gr[a].push_back(b);
            tgr[b].push_back(a);
        }
 
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            dfs(i);
        }
 
        memset(vis, 0, sizeof vis);
        compo.clear();
        reverse(topo.begin(),topo.end());
        int roots[n+5];
        long long dp[n+5];
        memset(dp,0,sizeof dp);
        memset(ans,0,sizeof ans);
        //vector<int>roots_node;
        int k=1;
        for(auto i: topo){
            if(vis[i])continue;
            dfs2(i);
            k++;
            int root=compo.front();
            for(auto u: compo){
                roots[u]=root;
                dp[root]+=fi[u];
            }
            //roots_node.push_back(root);
            compo.clear();
        }
 
        for(int i=1;i<=n;i++){
            for(auto j: gr[i]){
                if(roots[i] != roots[j])
                    mp[roots[i]].insert(roots[j]);
            }
        }
        memset(vis, 0, sizeof vis);
 
        //int k=roots_node.size();
        
        //queue<int> Q;
        //Q.push(roots[s]);
        ans[roots[s]] = dp[roots[s]];
        // while(!Q.empty()){
        //     int node = Q.front();
        //     Q.pop();
        //     vis[node] = 1;
        //     for(int i : mp[node]){
        //         if(vis[i])
        //             continue;
        //         if(ans[i] < ans[node] + dp[i]){
        //             ans[i] = ans[node] + dp[i];
        //             Q.push(i);
        //         }
        //     }
        // }
        ans[roots[s]]=dp[roots[s]];
 
        solve(roots[s],dp,roots);
        cout<<ans[roots[e]]<<endl;
        
 
 
 
        return 0;
    } 