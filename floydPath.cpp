#include<bits/stdc++.h>
using namespace std;

const int N=510;
const long long inf=1e17+10;

int n,m;
long long dis[N][N];
int prec[N][N];

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]<inf && dis[k][j]<inf){
                    if(dis[i][j]>dis[i][k]+dis[k][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                        prec[i][j]=prec[k][j];
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dis[i][j]=0;
                prec[i][j]=i;
            }
            else {
                dis[i][j]=inf;
                prec[i][j]=-1;
            }
        }
    }
    int u,v,wt;
    for(int i=0;i<m;i++){
        cin>>u>>v>>wt;
        dis[u][v]=min(dis[u][v],wt*1LL);
        dis[v][u]=dis[u][v];
        prec[u][v]=u;
    }

    floyd();

    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<dis[a][b]<<endl;
        if(prec[a][b]==-1)cout<<-1<<endl;
        else{
            vector<int>path;
            while(a!=b){
                path.push_back(b);
                b=prec[a][b];
            }
            path.push_back(a);
            reverse(path.begin(),path.end());
            for(auto i:path){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    


    return 0;
}