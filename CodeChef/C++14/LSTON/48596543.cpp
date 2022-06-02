#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long n;
    cin >> n;
    long long cur = 3, ans = 10, ok = 1;
    while(ok < n){
        cur += 3;
        ans = (cur*cur) + 1;
        ++ok;
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
