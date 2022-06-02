#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define F first
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	long long a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	long long ans = 0;
	for(int i = 1; i < n - 1; ++i){
		ans = max(ans, (a[i] - a[0]) * a[n - 1]);
		ans = max(ans, a[i] * (a[n - 1] - a[0]));
	}
	cout << ans << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}