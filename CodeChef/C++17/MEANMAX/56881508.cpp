#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	long double a[n], pre[n], suf[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	pre[0] = a[0];
	suf[n - 1] = a[n - 1];
	for(int i = 1; i < n; ++i) pre[i] = pre[i - 1] + a[i];
	for(int i = n - 2; i >= 0; --i) suf[i] = suf[i + 1] + a[i];
	long double ans = 0;
	for(int i = 0; i < n - 1; ++i)
		ans = max(ans, pre[i] / (i+1) + suf[i + 1] / (n - i - 1));
	cout << fixed << setprecision(6) << ans << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}