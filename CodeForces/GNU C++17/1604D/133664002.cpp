#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long x, y;

void solve(){
    cin >> x >> y;
    if(x == y){
        cout << x << '\n';
        return;
    }
    if(x > y){
        long long div = y/x;
        long long ans = (div + 1) * x;
        cout << ans + y << '\n';
        return;
    }
    if(x < y and y % x != 0){
        // we need to keep n in b/w x and y;
        long long mod = y % x;
        cout << y - mod/2 << '\n';
        return;
    }
    cout << y << '\n';
    return;
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}