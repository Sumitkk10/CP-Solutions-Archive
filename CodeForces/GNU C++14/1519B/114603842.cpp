#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const long long int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int n, m, k;

void solve(){
	cin >> n >> m >> k;
	cout << (((n * m) - 1) == k ? "YES\n" : "NO\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}