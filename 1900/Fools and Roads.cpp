#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> in,out,prolaz;
vector<vector<int>> stablo,up;
map<pair<int,int>,int> grane;
int n,logn=20,timer=0;
 
void suma(int cvor,int prev){
    int sum = prolaz[cvor];
    for(auto i:stablo[cvor]){
        if(i!=prev){
            suma(i,cvor);
            if(cvor<i)sum+=grane[{cvor,i}];
            else sum+=grane[{i,cvor}];
        }
    }
    if(prev<cvor)grane[{prev,cvor}]=sum;
    else grane[{cvor,prev}]=sum;
}
 
void dfs(int cvor,int prev){
    up[cvor][0]=prev;
    in[cvor]=++timer;
    for(auto i:stablo[cvor]){
        if(i!=prev){
            dfs(i,cvor);
        }
    }
    out[cvor]=++timer;
    return;
}
 
void preci(){
    for(int i=1;i<logn;i++){
        for(int j=0;j<n;j++){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
}
 
int lca(int v,int u){
    if(v==u)
        return v;
    if(in[v]<in[u]&&out[v]>out[u])
        return v;
    if(in[u]<in[v]&&out[u]>out[v])
        return u;
    for(int i=logn-1;i>=0;i--){
        if(!(in[up[v][i]]<in[u]&&out[up[v][i]]>out[u])){
            v=up[v][i];
        }
    }
    return up[v][0];
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    int unos[n][2];
    up = vector<vector<int>> (n,vector<int>(logn));
    stablo = vector<vector<int>> (n);
    in = vector<int> (n);
    out = vector<int> (n);
    prolaz = vector<int> (n,0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;a--;b--;
        if(a>b)swap(a,b);
        unos[i][0]=a;
        unos[i][1]=b;
        stablo[a].emplace_back(b);
        stablo[b].emplace_back(a);
    }
    dfs(0,0);
    preci();
    int t;
    cin>>t;
    while(t--){
        int v,u,l;
        cin>>v>>u;v--;u--;
        l=lca(v,u);
        prolaz[v]++;
        prolaz[u]++;
        prolaz[l]-=2;
    }
    suma(0,0);
    for(int i=0;i<n-1;i++){
        cout<<grane[{unos[i][0],unos[i][1]}]<<endl;
    }
    return 0;
}