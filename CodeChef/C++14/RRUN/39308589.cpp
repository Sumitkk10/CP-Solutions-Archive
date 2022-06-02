#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll fact[N];

ll power(ll x, ll y){
    x %= MOD;
    ll ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % MOD;
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ans;
}

ll nCr(long long int n, long long int r){
	return (fact[n] * power(fact[n - r] * fact[r], MOD - 2)) %MOD;
}

void solve(){
	int n;
	cin >> n;
	long long int a[n + 1], b[n + 1];
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; ++i){
		int low = 1, high = n, ans = 0; 
		while(low <= high){
			int mid = (low + high) / 2;
			if(b[mid] <= a[i]){
				ans = mid;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}
		int back = n - ans;
		long long int ans1 = 1;
		if(back >= 1)
			ans1 = (ans1 + nCr(back, 1)) % MOD;
		if(back >= 2)
			ans1 = (ans1 + nCr(back, 2)) % MOD;
		cout << (ans1 * power(2, ans - 1) - 1) % MOD << ' ';
	}
	cout << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	fact[0] = fact[1] = 1;
	for(int i = 2; i < N; ++i)
		fact[i] = (fact[i - 1] * i) % MOD;
	while(t--)
		solve();
	return 0;
}
 