#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
using namespace std;
const int N = 2500 + 5;
int n, k;
multiset<long long> a, b, c, d;

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		a.insert(x);
		c.insert(x);
	}
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		b.insert(x);
		d.insert(x);
	}
	long long ans = LLONG_MAX;
	ans = min(ans, *a.rbegin() + *b.rbegin());
	int kk = k;
	while(kk--){
		int p = *a.rbegin();
		a.erase(--a.end());
		int pp = *b.begin();
		b.erase(b.begin());
		b.insert(p);
		a.insert(pp);
		ans = min(ans, *a.rbegin() + *b.rbegin());
	}
	while(k--){
		int p = *d.rbegin();
		d.erase(--d.end());
		int pp = *c.begin();
		c.erase(c.begin());
		c.insert(p);
		d.insert(pp);
		ans = min(ans, *c.rbegin() + *d.rbegin());
	}
	cout << ans << '\n';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
    	solve();
	return 0;
}