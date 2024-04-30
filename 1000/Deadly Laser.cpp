#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,sx,sy,d;
        cin>>n>>m>>sx>>sy>>d;
        n--;m--;sx--;sy--;
        if((sx-d<=0&&sx+d>=n)||(sy-d<=0&&sy+d>=m)||(sx-d<=0&&sy-d<=0)||(sx+d>=n&&sy+d>=m)){
            cout<<-1<<"\n";
        }
        else{
            cout<<n+m<<"\n";
        }
    }
    return 0;
}