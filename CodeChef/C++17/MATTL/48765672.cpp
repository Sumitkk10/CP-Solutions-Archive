#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long int l,r,i,flag=0;
    cin>>l>>r;
    for(i=l;i<=r;i++){
        if(i%2==0) 
        flag++;
    }
    if(flag%2==0) cout<<"PASS\n";
    else cout<<"FAIL\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
