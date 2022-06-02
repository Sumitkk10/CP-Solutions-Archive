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
    long long even_sum = n/2 * (2 + (n/2) - 1);
    long long odd_sum = (n + 1)/2 * (1 + ((n + 1) / 2) - 1);
    cout << even_sum - odd_sum << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
