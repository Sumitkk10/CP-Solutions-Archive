#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 5e5 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int mp[8001] = {0};
	for(int l = 1; l <= n; ++l){
		int sum = a[l];
		for(int r = l + 1; r <= n; ++r){
			sum += a[r];
			if(sum > 8000) break;
			mp[sum] = true;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += (mp[a[i]] == true);
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