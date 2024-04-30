#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int parent[100010];
vector<int> dist(100010,LLONG_MAX);
vector<pair<int,int>>graf[100010];

void dijkstra(int s){
    set<pair<int,int>>pq;
    pq.insert({0,s});
    dist[s]=0;
    parent[s]=-1;
    while(!pq.empty()){
        auto it=pq.begin();
        int u=it->second;
        pq.erase(it);
        for(auto i:graf[u]){
            int v=i.first,w=i.second;
            if(dist[u]+w<dist[v]){
                pq.erase({dist[v],v});
                pq.insert({dist[u]+w,v});
                dist[v]=dist[u]+w;
                parent[v]=u;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graf[u].push_back({v,w});
        graf[v].push_back({u,w});
    }
    dijkstra(1);
    if(dist[n]==LLONG_MAX){
        cout<<-1<<endl;
        return 0;
    }
    int node=n;
    vector<int>path;
    while(node!=-1){
        path.push_back(node);
        node=parent[node];
    }
    for(int i=path.size()-1;i>=0;i--)cout<<path[i]<<" ";
    return 0;
}