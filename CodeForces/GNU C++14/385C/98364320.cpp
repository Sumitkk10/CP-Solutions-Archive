#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e7;
const int MOD = 1e9 + 7;
bool p[N + 1];
vector<int> prime;
long long int mp[N + 5], pre[N + 5], a[N + 5];

void sieve(){
	for(int i = 2; i <= N; ++i){
		if(!p[i]){
			prime.push_back(i);
			for(int j = i + i; j <= N; j += i)
				p[j] = 1;
		}
	}
}

void solve(){
	sieve();
	int n, q, l, r;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		mp[a[i]]++;
	}
	for(int k : prime){
		for(int i = k; i <= 1e7; i += k)
			if(mp[i])
				pre[k] += mp[i]; 
	}
	for(int i = 1; i <= 1e7; ++i)
		pre[i] += pre[i - 1];
	cin >> q;
	while(q--){
		cin >> l >> r;
		if(l > N){
			cout << "0\n";
			continue;
		}
		if(r > N) r = N;
		cout << pre[r] - pre[l - 1] << '\n';
	}
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
