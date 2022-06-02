#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n], xorr = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		xorr = (xorr ^ a[i]);
	}
	if(n % 2 == 0 && xorr){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	int ans[N][3], cnt = 0;
	if(!(n % 2)) --n;
	for(int i = 0; i < n - 2; i += 2){
		ans[cnt][0] = i + 1;
		ans[cnt][1] = i + 2;
		ans[cnt][2] = i + 3;
		++cnt;
	}
	for(int i = n - 2; i > 2; i -= 2){
		ans[cnt][0] = i;
		ans[cnt][1] = i - 1;
		ans[cnt][2] = i - 2;
		++cnt;
	}
	cout << cnt << '\n';
	for(int i = 0; i < cnt; ++i) 
		cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
