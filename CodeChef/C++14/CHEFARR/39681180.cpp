#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e7 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if(accumulate(a, a + n, 0) % 3){
		cout << "0\n";
		return;
	}
	long long int tar = accumulate(a, a + n, 0) / 3;
	long long int pre_sum[n], suff_sum[n];
	vector<int> ok, okk;
	pre_sum[0] = a[0];
	if(pre_sum[0] == tar)
		ok.push_back(0);
	suff_sum[n - 1] = a[n - 1];
	if(suff_sum[n - 1] == tar)
		okk.push_back(n - 1);
	for(int i = 1; i < n; ++i){
		pre_sum[i] = pre_sum[i - 1] + a[i];
		if(pre_sum[i] == tar)
			ok.push_back(i);
	}
	for(int i = n - 2; i >= 0; --i){
		suff_sum[i] = suff_sum[i + 1] + a[i];
		if(suff_sum[i] == tar)
			okk.push_back(i);
	}
	// cout << okk.size() << ' ';
	if(ok.empty() || okk.empty()){
		cout << "0\n";
		return;
	}
	sort(okk.begin(), okk.end());
	long long int result = 0;
	for(int i = 0; i < ok.size(); ++i){
		int low = 0, high = okk.size() - 1, ans = -1;
		while(low <= high){
			int mid = (low + high) / 2;
			if(okk[mid] > ok[i] + 1){
				ans = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		if(ans == -1) continue;
		// cout << ok[i] << ' ' << okk[ans] << ' ';
		result += (okk.size() - ans);
	}
	cout << result << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
