#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 2e5 + 5, MOD = 998244353;
long long fact[N];

void solve(){
	int n;
	cin >> n;
	if(n % 2){
		cout << "0\n";
		return;
	}
	cout << (fact[n / 2] * fact[n / 2]) % MOD << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	fact[1] = 1;
	for(int i = 2; i < N; ++i){
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	while(t--)
		solve();
	return 0;
}