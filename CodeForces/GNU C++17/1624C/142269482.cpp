#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
 
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	int mp[n + 1];
	memset(mp, 0, sizeof mp);
	for(int i = 0; i < n; ++i){
		int x = a[i];
		while(x > n)
			x /= 2;
		while(mp[x] > 0)
			x /= 2;
		if(x != 0) mp[x]++;
		a[i] = x;
		// cout << x << ' ';
	}
	sort(a, a + n);
	for(int i = 1; i <= n; ++i){
		if(a[i - 1] != i){
			cout << "NO\n";
			return;
		}
	}
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