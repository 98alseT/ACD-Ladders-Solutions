#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define int long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()

using namespace std;

int n,k,komb1=0,komb2=0;
int dp[50010][510];
bool mark[50010];
vector<int>graf[50010];

void postavi(int cvor){
    mark[cvor]=true;
    dp[cvor][0]=1;
    for(auto i:graf[cvor]){
        if(mark[i])continue;
        postavi(i);
        for(int j=1;j<=k;j++)dp[cvor][j]+=dp[i][j-1];
    }
}

void racunaj(int cvor,int p){
    komb1+=dp[cvor][k];
    for(auto i:graf[cvor]){
        if(i==p)continue;
        //cerr<<i<<" ";
        for(int j=1;j<k;j++){
            komb2+=(dp[cvor][k-j]-dp[i][k-j-1])*dp[i][j-1];
            //cerr<<"k = "<<komb2<<" ";
        }
        racunaj(i,cvor);
    }
}

signed main()
{
    speed;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        graf[a].pb(b);
        graf[b].pb(a);
    }
    postavi(1);
    racunaj(1,1);
    //cerr<<endl;
    cout<<komb1+(komb2>>1)<<endl;
    /*
    for(int i=1;i<=n;i++){
        cerr<<i<<" :-----------------------:"<<endl;
        for(int j=1;j<=k;j++){
            cerr<<"dp["<<j<<"] = "<<dp[i][j]<<endl;
        }
    }
    cout<<komb1<<" "<<komb2<<endl;
    cout<<dp[3][0]<<" "<<dp[2][k-0-1]-dp[3][k-0-2]<<endl;
    */
    return 0;
}