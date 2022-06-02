#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;
long long fact[N];

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
ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}
ll divi(ll a, ll b){
    return(mul(a, power(b, MOD - 2)) % MOD);
}

long long nCr(long long n, long long r){
	if(r > n)
		return 0;
	return divi(fact[n], mul(fact[n - r], fact[r])); 
}

void solve(){
	string s;
	cin >> s;
	map<int, int> mp;
	for(auto k : s)
		mp[k - 'a']++;
	long long ans = 0;
	for(int i = 0; i < 26; ++i){
		vector<int> cur(26, 0);
		for(int len = 1; len <= mp[i]; ++len){
			long long pro = 1;
			for(int j = 0; j < 26; ++j){
				if(j == i) continue;
				cur[j] = (cur[j] + nCr(mp[j], len - 1)) % MOD;
				pro = mul(pro, cur[j]);
			}
			pro = (pro * nCr(mp[i], len));
			ans = (ans + pro) % MOD;
		}
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	fact[1] = fact[0] = 1;
	for(int i = 2; i < N; ++i)
		fact[i] = mul(fact[i - 1], i);
	while(t--)
		solve();
	return 0;
}