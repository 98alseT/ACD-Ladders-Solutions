#include <bits/stdc++.h>
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define push_back emplace_back
#define ll long long

using namespace std;

int n,dist=-1,dis[200010],parent[200010],mark[200010];
vector<int>graf[200010];
queue<int>qu;


void spremi(int p,int k){
    int cvor=p;
    while(cvor!=k){
        qu.push(cvor);
        dis[cvor]=0;
        mark[cvor]=3;
        cvor=parent[cvor];
    }
    qu.push(k);
    mark[k]=3;
}

int bfs(int color,int& c){
    int d=0;
    while(!qu.empty()){
        int cvor=qu.front();
        qu.pop();
        mark[cvor]=color;
        for(auto i:graf[cvor]){
            if(mark[i]==color)continue;
            dis[i]=dis[cvor]+1;
            qu.push(i);
        }
        c=cvor;
    }
    return dis[c];
}

void dfs(int cvor,int d,int& c,int color){
    if(d>dist){
        c=cvor;
        dist=d;
    }
    mark[cvor]=color;
    for(auto i:graf[cvor]){
        if(mark[i]==color)continue;
        parent[i]=cvor;
        dfs(i,d+1,c,color);
    }
}

int main()
{
    speed;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        --a;--b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int c1=-1,c2=-1;
    dfs(0,0,c1,1);
    dist=-1;
    dfs(c1,0,c2,2);
    if(dist==n-1){
        cout<<dist<<endl;
        cout<<c1+1<<" "<<c2+1<<" "<<parent[c2]+1<<endl;
    }
    else{
        int c3=-1;
        spremi(c2,c1);
        cout<<dist+bfs(3,c3)<<endl;
        cout<<c1+1<<" "<<c2+1<<" "<<c3+1<<endl;
    }
    return 0;
}