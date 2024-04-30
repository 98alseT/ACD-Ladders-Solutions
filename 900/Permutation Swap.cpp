#include <bits/stdc++.h>

using namespace std;

int nzd(int a,int b){
    int r=a%b;
    if(r==0)
        return b;
    else return nzd(b,r);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,res=0;
        cin>>n;
        for(int j=1;j<=n;j++){
            int x,a;
            cin>>x;
            a=abs(x-j);
            if(a==0)continue;
            if(res==0){
                res=a;
                continue;
            }
            if(a>res){
                res=nzd(a,res);
            }
            else{
                res=nzd(res,a);
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}