#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, a,  b;
    cin >> n >> a >> b;
    // the match has n turns.
    // white has A sec left and black has B seconds left.
    cout << (2 * (180 + n) - (a + b)) << '\n'; 
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
