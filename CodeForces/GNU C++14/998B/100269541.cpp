#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, k, a[N];

void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int cnt = 0, cnt1 = 0;
	vector<int> v;
	for(int i = 0; i < n - 1; ++i){
		cnt += (a[i] % 2 == 0);
		cnt1 += (a[i] % 2 == 1);
		if(cnt == cnt1)
			v.push_back(abs(a[i] - a[i + 1]));
	}
	sort(v.begin(), v.end());
	int ans = 0, sum = 0;
	for(int i = 0; i < v.size(); ++i){
		sum += v[i];
		++ans;
		if(sum > k){
			--ans;
			break;
		}
		if(sum == k)
			break;
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
