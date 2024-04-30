#include <bits/stdc++.h>

using namespace std;

vector<long long> b;
long long x;

bool binPret(long long tr){
    int l=0,d=1e4;
    while(l<=d){
        int s=(l+d)>>1;
        long long v=b[s]*b[s]*b[s];
        if(v==tr)return true;
        if(v>tr)d=s-1;
        else l=s+1;
    }
    return false;
}

int main()
{
    for(int i=1;i<1e4+1;i++){
        b.emplace_back(i);
    }
    int t;
    cin>>t;
    while(t--){
        cin>>x;
        bool p=false;
        for(long long i=1;i*i*i<x;i++){
            long long ti=i*i*i;
            if(binPret(x-ti)){
                p=true;
                break;
            }
        }
        if(p)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}