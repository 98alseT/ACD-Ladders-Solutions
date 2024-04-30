#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
 
ll n,m,sum=0;
vector<ll>niz;
 
bool check(ll s){
    ll l=0,r=n-s-1;
    //cerr<<"check za "<<s<<endl;
    if(l<r&&niz[l]+niz[r]>m)return 0;
    //cerr<<"preziveo"<<l<<" "<<r<<endl;
    while(l<r){
        r--;
        if(l<r&&niz[l]+niz[r]>m)return 0;
        //cerr<<"preziveo"<<l<<" "<<r<<endl;
        l++;
        if(l<r&&niz[l]+niz[r]>m)return 0;
        //cerr<<"preziveo"<<l<<" "<<r<<endl;
    }
    //cerr<<"YIPPE"<<endl;
    return 1;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    niz=vector<ll>(n);
    for(int i=0;i<n;i++){
        cin>>niz[i];
        sum+=niz[i];
    }
    sort(niz.begin(),niz.end());
    ll l=0,r=n-1,k=0;
    if(l<r&&niz[l]+niz[r]>m)k++;
    while(l<r){
        r--;
        if(l<r&&niz[l]+niz[r]>m)k++;
        l++;
        if(l<r&&niz[l]+niz[r]>m)k++;
    }
    l=0;r=k;
    while(l<r){
        ll s=(l+r)>>1;
        if(check(s))r=s;
        else l=s+1;
    }
    cout<<n+sum-(n-r-1)<<endl;
}