#include<bits/stdc++.h>
    using namespace std;
 
    #define INF 1000000007
 
    vector<int>gr[100005];
    vector<int>tgr[100005];
    vector<int>topo;
    bool vis[100005];
    vector<int>compo;
    unordered_map<int, unordered_set<int> >mp(100005);
 
 
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
 
    void dfs3(int ver){
        vis[ver]=true;
        for(auto i: mp[ver]){
            if(vis[ver])continue;
            dfs3(i);
        }
        topo.push_back(ver);
    }
 
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
 
        int n,m;
        cin>>n>>m;
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
        vector<int>roots_node;
        int k=1;
        for(auto i: topo){
            if(vis[i])continue;
            dfs2(i);
            k++;
            int root=compo.front();
            for(auto u: compo){
                roots[u]=root;
            }
            roots_node.push_back(root);
            compo.clear();
        }
 
        for(int i=1;i<=n;i++){
            for(auto j: gr[i]){
                if(roots[i] != roots[j])
                    mp[roots[j]].insert(roots[i]);
            }
        }
        memset(vis, 0, sizeof vis);
        topo.clear();
 
        int f=0;
        
        for(auto i: roots_node){
            if(vis[i])continue;
            dfs3(i);
        }
        
        reverse(topo.begin(),topo.end());
        memset(vis, 0, sizeof vis);
 
        int ans=topo.front();
        dfs2(ans);
        for(int i=1;i<=k;i++){
            if(vis[i]==0){
                f=1;
                break;
            }
        }
        vector<int>vec;
        int ct=0;
        if(f==1)cout<<0<<"\n";
        else{
            for(int i=1;i<=n;i++){
                if(roots[i]==ans){
                    ct++;
                    vec.push_back(i);
                }
            }
            cout<<ct<<"\n";
            for(int i: vec){
                cout<<i<<" ";
            }
        }
        cout<<"\n";
 
        
 
 
 
        return 0;
    } 