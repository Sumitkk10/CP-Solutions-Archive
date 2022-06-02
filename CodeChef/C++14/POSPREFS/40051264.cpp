#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> ans(n, 0);
	int neg = n - k;
	for(int i = 1; i <= n; ++i)
		ans[i - 1] = i;
	for(int i = 1; i < n; i += 2){
		if(neg > 0){
			ans[i] = -(i + 1);
			--neg;
		}
	}
	if(neg){
		for(int i = n - 1; i >= 0; --i){
			if(ans[i] > 0 and neg > 0){
				--neg;
				ans[i] = -ans[i];
			}
		}
	}
	for(auto k : ans)
		cout << k << ' ';
	cout << '\n';
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
