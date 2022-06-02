#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, k1, k2, w, b;
    cin >> n >> k1 >> k2 >> w >> b;
    if(w <= (min(k1, k2) + (max(k1, k2) - min(k1, k2)) / 2) and b <= (min(n-k1, n-k2) + (max(n - k1, n - k2) - min(n - k1, n - k2)) / 2))
        cout << "yEs\n";
    else
        cout << "nO\n";
}

int main() {
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
	return 0;
}
