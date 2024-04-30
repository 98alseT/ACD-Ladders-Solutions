#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        long long rez=0;
        cin>>n;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            rez+=mp[x-i];
            mp[x-i]++;
        }
        cout<<rez<<'\n';
    }
    return 0;
}