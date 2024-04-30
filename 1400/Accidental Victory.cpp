#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long n,c=1;
        cin>>n;
        vector<pair<long long,long long>> niz;
        vector<long long> ispis;
        vector<long long> pref(n+1);
        pref[0]=0;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            niz.emplace_back(x,i);
        }
        sort(niz.begin(),niz.end());
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+niz[i-1].first;
        }
        ispis.emplace_back(niz[n-1].second);
        for(int i=n-1;i>0;i--){
            if(pref[i]>=niz[i].first){
                ispis.emplace_back(niz[i-1].second);
                c++;
            }
            else break;
        }
        sort(ispis.begin(),ispis.end());
        cout<<c<<"\n";
        for(auto i:ispis)cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}