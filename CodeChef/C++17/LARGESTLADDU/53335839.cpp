#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int mx = 0, mn = INT_MAX, cur = (1 << n);
    for(int i = 0; i < cur; ++i){
        int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    cout << (mx - mn <= 1 ? "YES\n" : "NO\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}