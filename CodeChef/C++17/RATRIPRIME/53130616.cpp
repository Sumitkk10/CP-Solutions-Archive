#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool is_prime(ll x){
    for(ll i = 2; i * i <= x; ++i){
        if(x % i == 0)
            return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    for(int m = 1; m <= n + 100; ++m){
        ll x = n*m + 1;
        if(!is_prime(x)){
            cout << m << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
