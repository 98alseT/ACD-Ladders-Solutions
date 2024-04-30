#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> a,niz;

bool proveri(){
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(niz[j][i]!=niz[j-1][i])return false;
        }
    }
    return true;
}

void xoruj(int red){
    for(int i=0;i<n;i++){
        niz[red][i]^=1;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        a = vector<vector<int>> (n,vector<int>(n));
        niz = vector<vector<int>> (n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char c;
                cin>>c;
                a[i][j]=c-'0';
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char b;
                cin>>b;
                if(b-'0'==a[i][j])niz[i][j]=0;
                else niz[i][j]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(niz[i][0]==1)xoruj(i);
        }
        if(proveri())cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}