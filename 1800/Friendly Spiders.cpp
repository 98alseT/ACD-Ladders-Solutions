#include <bits/stdc++.h>
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define push_back emplace_back
#define ll long long

using namespace std;

const int pom=3*1e5+1,maxn=3*1e5+1;
bool mark[maxn<<1];
int parent[maxn<<1],dist[maxn<<1];
vector<int>graf[maxn<<1];

void bfs(int x,int k){
    queue<int>qu;
    qu.push(x);
    mark[x]=true;
    parent[x]=-1;
    while(!qu.empty()){
        int cvor=qu.front();
        qu.pop();
        if(cvor==k)return;
        for(auto i:graf[cvor]){
            if(mark[i])continue;
            mark[i]=true;
            qu.push(i);
            dist[i]=dist[cvor]+1;
            parent[i]=cvor;
        }
    }
}

void spoji(int x){
    int br=x;
    for(int i=2;i<=sqrt(x);i++){
        if(br%i==0){
            graf[x].push_back(i+pom);
            graf[i+pom].push_back(x);
            while(br%i==0)br/=i;
        }
    }
    if(br!=1){
        graf[x].push_back(br+pom);
        graf[br+pom].push_back(x);
    }
}

signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>pauk(n);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>pauk[i];
        if(pauk[i]==1){
            graf[1].push_back(pom+1);
            graf[pom+1].push_back(1);
        }
        else spoji(pauk[i]);
    }
    int a,b;
    cin>>a>>b;
    --a;--b;
    if(a!=b&&(pauk[a]==1||pauk[b]==1))cout<<-1<<endl;
    else if(a==b)cout<<1<<endl<<a+1<<endl;
    else if(pauk[a]==pauk[b])cout<<2<<endl<<a+1<<" "<<b+1<<endl;
    else{
        mp[pauk[a]]=a+1;
        mp[pauk[b]]=b+1;
        for(int i=0;i<n;i++){
            if(pauk[i]==pauk[a]||pauk[i]==pauk[b])continue;
            mp[pauk[i]]=i+1;
        }
        bfs(pauk[a],pauk[b]);
        if(dist[pauk[b]]==0)cout<<-1<<endl;
        else{
            int ind=0,cvor=pauk[b],daljina=(dist[pauk[b]]>>1)+1;
            vector<int>res;
            while(parent[cvor]!=-1){
                if(ind%2==0)res.push_back(cvor);
                cvor=parent[cvor];
                ind++;
            }
            res.push_back(cvor);
            cout<<daljina<<endl;
            for(int i=res.size()-1;i>=0;i--){
                cout<<mp[res[i]]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}