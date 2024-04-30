#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()

using namespace std;

int seg[800000];
int niz[200000];

void build(int v,int k,int l,int r){
    if(l==r){
        seg[v]=niz[l];
        return;
    }
    int s=(l+r)>>1;
    build(v<<1,k-1,l,s);
    build(v<<1|1,k-1,s+1,r);
    if(k%2==1)seg[v]=(seg[v<<1]|seg[v<<1|1]);
    else seg[v]=(seg[v<<1]^seg[v<<1|1]);
}

void update(int v,int k,int tl,int tr,int l,int x){
    if(tl==tr){
        seg[v]=x;
        return;
    }
    int s=(tl+tr)>>1;
    if(s>=l)update(v<<1,k-1,tl,s,l,x);
    else update(v<<1|1,k-1,s+1,tr,l,x);
    if(k%2==1)seg[v]=(seg[v<<1]|seg[v<<1|1]);
    else seg[v]=(seg[v<<1]^seg[v<<1|1]);
}

int main()
{
    speed;
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=(1<<n);i++){
        cin>>niz[i];
    }
    build(1,n,1,(1<<n));
    while(q--){
        int l,x;
        cin>>l>>x;
        update(1,n,1,(1<<n),l,x);
        cout<<seg[1]<<endl;
    }
    return 0;
}