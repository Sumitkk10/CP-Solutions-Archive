#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;
int n, k, a[N], cnt[N];
pair<int, int> ans;

bool check(int mid){
	for(int i = 1; i <= n - mid; ++i){
		int far = i + mid;
		int x = cnt[far] - cnt[i - 1];
		int left = n - x;
		if(x >= left + k){
			ans.F = i;
			ans.S = i + mid;
			return true;
		}
	}
	return false;
}

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		cnt[i] = 0;
	}
	for(int i = 1; i <= n; ++i)
		cnt[a[i]]++;
	for(int i = 1; i <= n; ++i)
		cnt[i] += cnt[i - 1];
	// max value of max - min can be atmost n - 1;
	int low = 0, high = n - 1;
	while(low <= high){
		int mid = (low + high) / 2;
		if(check(mid))
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << ans.F << ' ' << ans.S << '\n';
	// I need to construct the array from here. how to? 
	vector<int> res;
	res.pb(0);
	int cur = 1, ct = 0;
	while(cur <= n){
		if(res.size() == k) break;
		if(a[cur] >= ans.F and a[cur] <= ans.S) ++ct;
		else --ct;
		if(ct == 1){
			ct = 0;
			res.pb(cur);
		}
		++cur;
	}
	res.pb(n);
	for(int i = 0; i < res.size() - 1; ++i)
		cout << res[i] + 1 << ' ' << res[i + 1] << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}