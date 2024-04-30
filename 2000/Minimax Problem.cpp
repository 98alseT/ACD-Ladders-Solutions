#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>>mat;
pair<int,int> res;

bool moze(int x){
    vector<int>vr(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]>=x){
                vr[i]|=1<<j;
            }
        }
    }
    vector<bool> vecBio(256,false);
    vector<pair<int,int>> brojevi;
    for(int i=0;i<n;i++){
        if(vecBio[vr[i]])continue;
        vecBio[vr[i]]=true;
        brojevi.push_back({vr[i],i});
    }
    for(int i=0;i<brojevi.size();i++){
        for(int j=i;j<brojevi.size();j++){
             if((brojevi[i].first|brojevi[j].first)==(1<<m)-1){
                res={brojevi[i].second,brojevi[j].second};
                return true;
             }
        }
    }
    return false;
}

void binPret(){
    int l=0,r=1e9;
    while(l<r){
        int sred=(l+r+1)>>1;
        if(moze(sred))
            l=sred;
        else r=sred-1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    mat=vector<vector<int>>(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
    }
    binPret();
    cout<<res.first+1<<" "<<res.second+1<<"\n";
    return 0;
}