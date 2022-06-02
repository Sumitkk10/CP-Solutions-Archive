#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const long long int N = 1e10;
const int MOD = 1e9 + 7;

void solve(){
    long long x;
    cin >> x;
    for(long long i = 1; i <= sqrt(x); ++i)
        cout << i*i << ' ';
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