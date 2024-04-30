#include <iostream>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'

using namespace std;

int main()
{
    speed;
    int n;
    cin>>n;
    cout<<__builtin_popcount(n)<<endl;
    return 0;
}