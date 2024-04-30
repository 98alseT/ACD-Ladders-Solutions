#include <bits/stdc++.h>
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

int main()
{
    speed;
    ll n,sum=0;
    cin>>n;
    vector<ll>niz(n);
    unordered_map<ll,bool> left,right;
    for(int i=0;i<n;i++){
        cin>>niz[i];
        sum+=niz[i];
    }
    if(sum%2!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    ll lsum=0,rsum=0;
    for(int i=0;i<n;i++){
        left[niz[i]]=true;
        lsum+=niz[i];
        if(lsum==sum/2){
            cout<<"YES"<<endl;
            return 0;
        }
        if(lsum>sum/2&&left[lsum-sum/2]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    for(int i=n-1;i>=0;i--){
        right[niz[i]]=true;
        rsum+=niz[i];
        if(rsum==sum/2){
            cout<<"YES"<<endl;
            return 0;
        }
        if(rsum>sum/2&&right[rsum-sum/2]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}