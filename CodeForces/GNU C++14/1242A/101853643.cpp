#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    ll n, ans = 0;
    cin >> n;
    for(ll i = 2; i * i <= n; ++i){
        if(n % i == 0){
            ll nn = n;
            while(nn % i == 0)
                nn /= i;
            if(nn == 1)
                cout << i << '\n';
            else
                cout << "1\n";
            return;
        }
    }
    cout << n << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
