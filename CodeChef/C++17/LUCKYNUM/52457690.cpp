#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int N = 1e6 + 5;

void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a == 7 or b == 7 or c == 7 ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
