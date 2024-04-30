#include <bits/stdc++.h>
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define push_back emplace_back
#define ll long long
#define ull unsigned long long

using namespace std;

vector<ull>niz;

void uradi(ull num,int br,int ind,int n){
    if(br>3)return;
    if(ind==n){
        niz.push_back(num);
        return;
    }
    uradi(num*10,br,ind+1,n);
    for(int i=1;i<10;i++)uradi(num*10+i,br+1,ind+1,n);
}

int proveri(ull x){
    int r=0;
    while(x>0){
        if(x%10>0)r++;
        x/=10;
    }
    return r;
}

void resi(){
    ull l,r;
    cin>>l>>r;
    if(l==r&&proveri(l)<=3)cout<<1<<endl;
    else{
        int lind=lower_bound(niz.begin(),niz.end(),l)-niz.begin();
        int rind=upper_bound(niz.begin(),niz.end(),r)-niz.begin();
        cout<<rind-lind<<endl;
    }
}

int main()
{
    speed;
    for(int i=1;i<=19;i++){
        for(int j=1;j<10;j++){
            uradi(j,1,1,i);
        }
    }
    niz.push_back(0);
    sort(niz.begin(),niz.end());
    int t;
    cin>>t;
    while(t--){
        resi();
    }
    return 0;
}