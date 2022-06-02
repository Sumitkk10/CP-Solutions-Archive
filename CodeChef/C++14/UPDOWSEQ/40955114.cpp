#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int pre_dp[N], pre_dp1[N], mx = 1, suf_dp[N], suf_dp1[N], n, a[N];

void calc_pre(){
	for(int i = 1; i < n; ++i){
		if(a[i] > a[i - 1]){
			pre_dp[i] = pre_dp1[i - 1] + 1;
			pre_dp1[i] = 1;
		}
		else if(a[i] < a[i - 1]){
			pre_dp1[i] = pre_dp[i - 1] + 1;
			pre_dp[i] = 0;
		}
		else{
			pre_dp[i] = pre_dp1[i - 1] + 1;
			pre_dp1[i] = pre_dp[i - 1] + 1;
		}
		mx = max(mx, pre_dp[i]);
		mx = max(mx, pre_dp1[i]);
	}
}

void calc_suf(){
	for(int i = n - 2; i >= 0; --i){
		if(a[i] > a[i + 1]){
			suf_dp[i] = suf_dp1[i + 1] + 1;
			suf_dp1[i] = 1;
		}
		else if(a[i] < a[i + 1]){
			suf_dp1[i] = suf_dp[i + 1] + 1;
			suf_dp[i] = 1;
		}
		else{
			suf_dp[i] = suf_dp1[i + 1] + 1;
			suf_dp1[i] = suf_dp[i + 1] + 1;
		}
	}
}

int inserting_one_num(){
	int mxx = 0;
	for(int i = 0; i < n - 1; ++i){
		mxx = max(mxx, pre_dp[i] + suf_dp[i + 1] + 1);
		mxx = max(mxx, pre_dp1[i] + suf_dp1[i + 1] + 1);
	}
	return mxx;
}

void solve(){
	mx = 1;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	pre_dp[0] = 0;
	pre_dp1[0] = 1;
	// pre_dp is the max length when nth element is up and we always take the nth element.
	// pre_dp1 is the max length when nth element is down and we always take the nth element.
	calc_pre();
	suf_dp[n - 1] = 1;
	suf_dp1[n - 1] = 1;
	// suf_dp is the max length when nth element is up and we always take the nth element.
	// suf_dp1 is the max length when nth element is down and we always take the nth element.
	calc_suf();
	// now the answer will be max(mx, inserting_one_num());
	cout << max(mx + 1, inserting_one_num()) << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
