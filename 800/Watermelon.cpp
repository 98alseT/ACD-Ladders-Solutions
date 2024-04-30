#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if(n<<31==0&&n>3) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}