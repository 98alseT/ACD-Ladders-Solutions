#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int v=s.size();
        if(v>10){
            cout<<s[0]<<v-2<<s[v-1]<<"\n";
        }
        else cout<<s<<"\n";
    }
    return 0;
}