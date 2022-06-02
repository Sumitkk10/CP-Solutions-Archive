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
    cout << "1 ";
    for(ll i = 0; i <= n - 1; ++i){
        ll cur = 1;
        for(int j = 0; j < i; ++j)
            cur = (cur * 2);
        cout << cur << ' ';
    }
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
