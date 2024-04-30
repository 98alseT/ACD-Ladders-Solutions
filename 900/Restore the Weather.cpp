#include <bits/stdc++.h>

using namespace std;

bool dani(const pair<int,int>& a,const pair<int,int>& b){
    if(a.second<b.second)return true;
    return false;
}
bool temp(const pair<int,int>& a,const pair<int,int>& b){
    if(a.first<b.first)return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> pret,rel;
        for(int i=0;i<n;i++){
            int tuga;
            cin>>tuga;
            pret.emplace_back(tuga,i);
        }
        for(int i=0;i<n;i++){
            int tuga;
            cin>>tuga;
            rel.emplace_back(tuga,i);
        }
        sort(pret.begin(),pret.end(),temp);
        sort(rel.begin(),rel.end(),temp);
        for(int i=0;i<n;i++){
            rel[i].second=pret[i].second;
        }
        sort(rel.begin(),rel.end(),dani);
        for(int i=0;i<n;i++){
            cout<<rel[i].first<<" ";
        }
        cout<<"\n";
    }
    return 0;
}