#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long int n, k;
	cin >> n >> k;
	long long int sum = 0, j;
	for(j = 1; j; ++j){
		sum += j;
		if(sum >= k)
			break;	
	}
	if(sum == k){
		string ans;
		for(int i = n; i >= 1; --i)
			ans.push_back('a');
		ans[n - j - 1] = 'b';
		ans[n - j] = 'b';
		cout << ans << '\n';
		return;
	}
	string ans;
	for(int i = n; i >= 1; --i)
		ans.push_back('a');
	ans[n - j - 1] = 'b';
	int kk = sum - k;
	ans[n - j - 1 + kk + 1] = 'b';
	cout << ans << '\n'; 
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
