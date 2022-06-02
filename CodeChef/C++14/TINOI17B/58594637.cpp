#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e6 + 5;
long long n, s, e[N], v[N], dp[5001][5001];

long long go(int i, int cnt){
	if(i == n)
		return 0;
	if(dp[i][cnt] != -1)
		return dp[i][cnt];
	long long ans = 0;
	ans = max(ans, go(i + 1, cnt + 1));
	ans = max(ans, go(i + 1, cnt) + e[i]*v[cnt]);
	return dp[i][cnt] = ans;
}

void solve(){
	memset(dp, -1, sizeof dp);
	cin >> n >> s;
	for(int i = 0; i < n; ++i)
		cin >> e[i];
	v[0] = s;
	for(int i = 1; i < n; ++i){
		long long x = v[i - 1], sum = 0;
		string cur = to_string(x);
		for(auto k : cur)
			sum += (k - '0');
		v[i] = x + (sum * sum * sum);
	}
	cout << go(0, 0) << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}