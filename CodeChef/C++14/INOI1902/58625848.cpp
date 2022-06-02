#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
#define S second
#define F first
using namespace std;
const int N = 1e6 + 2;
int n, l, a[N];
vector<pair<int, int> > v;

bool check(int x){
	int dp[n];
	dp[0] = 1;
	for(int i = 1; i < n; ++i){
		int mx = 0;
		for(int j = i - 1; j >= 0; --j){
			if(abs(v[j].S - v[i].S) >= x)
				mx = max(mx, dp[j]);
		}
		dp[i] = mx + 1;
	}
	if(*max_element(dp, dp + n) >= l)
		return true;
	return false;
}

bool cmp(pair<int, int> x, pair<int, int> y){
	if(x.F == y.F)
		return x.S < y.S;
	return x.F > y.F;
}

void solve(){
	cin >> n >> l;
	v.clear();
	map<int, vector<int> > pos;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		v.pb({a[i], i});
		pos[a[i]].pb(i);
	}
	sort(v.rbegin(), v.rend(), cmp);
	int ans = 0;
	for(auto k : pos){
		ans = max(ans, abs(k.S[0] - k.S[k.S.size() - 1]));
	}
	if(l > n){
		cout << ans << '\n';
		return;
	}
	int low = 0, high = 1e9, res;
	while(low <= high){
		int mid = (low + (high - low) / 2);
		if(check(mid)){
			res = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << max(res, ans) << '\n';
}

int32_t main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}