#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	string a[n - 2];
	for(int i = 0; i < n - 2; ++i)
		cin >> a[i];
	string ans;
	ans.push_back(a[0][0]);
	ans.push_back(a[0][1]);
	for(int i = 1; i < n - 2; ++i){
		if(a[i][0] == a[i - 1][1])
			ans.push_back(a[i][1]);
		else{
			ans.push_back(a[i][0]);
			ans.push_back(a[i][1]);
		}
	}
	if(ans.size() != n)
	     ans = 'a' + ans;
	cout << ans << '\n';
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
