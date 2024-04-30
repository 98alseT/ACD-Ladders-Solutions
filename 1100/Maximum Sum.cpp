#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k,l=0;
        long long sum=0;
        cin>>n>>k;
        vector<long long> jevtic(n),pref(n,0);
        cin>>jevtic[0];
        for(int j=1;j<n;j++){
            cin>>jevtic[j];
        }
        sort(jevtic.begin(),jevtic.end());
        pref[0]=jevtic[0];
        for(int j=1;j<n;j++){
            pref[j]+=pref[j-1]+jevtic[j];
        }
        sum=pref[k*2-1];
        for(int j=1;j<k;j++){
            sum=min(sum,(pref[(k*2-j*2)-1]+(pref[n-1]-pref[(n-1)-j])));
        }
        sum=min(sum,(pref[n-1]-pref[(n-1)-k]));
        cout<<pref[n-1]-sum<<"\n";
    }
    return 0;
}