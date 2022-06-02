#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 20;
const int MOD = 1e9 + 7;
int n, m, k, a[N];

bool check(){
	for(int i = 0; i <= n - k; ++i){
		int mx = 0, cnt = 0;
		for(int j = i; j < i + k; ++j){
			if(a[j] > mx){
				mx = a[j];
				cnt = 1;
			}
			else if(a[j] == mx)
				++cnt;
		}
		if(cnt >= m)
			return false;
	}
	return true;
}

void solve(){
	cin >> n >> k >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = INT_MAX;
	for(int i = 0; i < (1 << n); ++i){
		for(int j = 0; j < n; ++j)
			if(i & (1 << j))
				a[j]++;
		if(check())
			ans = min(ans, __builtin_popcount(i));
		for(int j = 0; j < n; ++j)
			if(i & (1 << j))
				a[j]--;
	}
	cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}