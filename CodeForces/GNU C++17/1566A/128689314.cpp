#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

/*
keep elements before n/2 as 0.
*/

void solve(){
    ll n, s;
    cin >> n >> s;
    if(n == 1){
        cout << s << '\n';
        return;
    }
    if(n == 2){
        cout << s/2 << '\n';
        return;
    }
    if(n % 2 == 0){
        cout << s / (n - (n/2 - 1)) << '\n';
        return;
    }
    cout << s / (n - (n / 2)) << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
