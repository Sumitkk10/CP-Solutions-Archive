#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
long long n, len, a[N];

void solve(){
	cin >> n >> len;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int res[len] = {0};
	for(int i = 0; i < n; ++i){
		long long cur = a[i];
		for(int j = len - 1; j >= 0; --j){
			res[j] += (cur % 2);
			cur /= 2;
		}
	}
	long long ans = 0, cur = 0;
	for(int i = len - 1; i >= 0; --i){
		if(res[i]*2 >= n)
			ans += (1 << cur);
		++cur;
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