#include<bits/stdc++.h>
using namespace std;

const int N=510;
const long long inf=1e17+10;

int n,m;
long long dis[N][N];

void floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][k]<inf && dis[k][j]<inf){
                    if(dis[i][j]>dis[i][k]+dis[k][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j)dis[i][j]=0;
            else dis[i][j]=inf;
        }
    }
    int q;
    cin>>n>>m;
    int u,v,wt;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>wt;
        dis[u][v]=min(dis[u][v],wt*1LL);
        dis[v][u]=dis[u][v];
    }

    floyd();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dis[i][j]==inf)cout<<-1<<" ";
            else cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    // int a,b;
    // while(q--){
    //     cin>>a>>b;
    //     if(dis[a][b]==inf)cout<<-1<<endl;
    //     else cout<<dis[a][b]<<endl;
    // }


    return 0;
}