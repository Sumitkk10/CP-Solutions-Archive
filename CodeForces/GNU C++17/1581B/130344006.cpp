#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    if(k == 0 or k == 1){
        cout << "NO\n";
        return;
    }
    if(n == 1){
        if(m > 0){
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        return;
    }
    if(m < n - 1){
        cout << "NO\n";
        return;
    }
    if(m > (n*(n - 1))/2){
        cout << "NO\n";
        return;
    }
    if(k - 2 >= 2){
        cout << "YES\n";
        return;
    }
    if(k - 2 == 1){
        if(m >= (n*(n - 1))/2){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
