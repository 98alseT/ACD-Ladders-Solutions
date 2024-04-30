#include <bits/stdc++.h>
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define push_back emplace_back
#define ll long long

using namespace std;

int main()
{
    speed;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int mat[n][m],dp1[n][m],dp2[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }
        //cerr<<"min"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0)dp1[0][0]=mat[0][0];
                else if(j==0)dp1[i][j]=dp1[i-1][j]+mat[i][0];
                else if(i==0)dp1[0][j]=dp1[0][j-1]+mat[0][j];
                else dp1[i][j]=min(dp1[i-1][j],dp1[i][j-1])+mat[i][j];
                //cerr<<dp1[i][j]<<" ";
            }
            //cerr<<endl;
        }
        //cerr<<"max"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0)dp2[0][0]=mat[0][0];
                else if(j==0)dp2[i][0]=dp2[i-1][0]+mat[i][0];
                else if(i==0)dp2[0][j]=dp2[0][j-1]+mat[0][j];
                else dp2[i][j]=max(dp2[i-1][j],dp2[i][j-1])+mat[i][j];
                //cerr<<dp2[i][j]<<" ";
            }
            //cerr<<endl;
        }
        if(((n+m-1)%2)!=0)cout<<"NO"<<endl;
        else if(dp1[n-1][m-1]<=0&&dp2[n-1][m-1]>=0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}