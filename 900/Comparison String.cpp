#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        char znak;
        int score=1,n,maxscore=1;
        cin>>n;
        string s;
        cin>>s;
        znak=s[0];
        for(int i=1;i<n;i++){
            if(znak==s[i]){
                score++;
                maxscore=max(maxscore,score);
            }
            else{
                score=1;
                znak=s[i];
            }
        }
        cout<<maxscore+1<<"\n";
    }
    return 0;
}