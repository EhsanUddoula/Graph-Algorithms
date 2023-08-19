#include<bits/stdc++.h>
using namespace std;
 
char s[1005][1005];
bool vis[1005][1005];
 
void dfs(int i,int j,int n,int m){
    if(i<1||i>n||j<0||j>=m)return;
    if(s[i][j]!='.')return;
    if(vis[i][j])return;
    vis[i][j]=true;
    dfs(i,j+1,n,m);
    dfs(i,j-1,n,m);
    dfs(i+1,j,n,m);
    dfs(i-1,j,n,m);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("\n");
        scanf("%s",s[i]);
    }
    int ct=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='.'&&vis[i][j]==0){
                dfs(i,j,n,m);
                ct++;
            }
        }
    }
    printf("%d\n",ct);
 
    return 0;
}
