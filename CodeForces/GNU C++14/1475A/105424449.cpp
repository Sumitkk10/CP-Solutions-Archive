#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
const int N = 60000 + 5;
const int MOD = 1e9 + 7;
const long double ESP = 1e-12;

void solve(){
    long long n;
    cin >> n;
    if((n & (n - 1)) == 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}