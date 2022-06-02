#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	int ans = 0, pre = -2;
	if(s[0] == '0')
		pre = 0;
	for(int i = 1; i < n; ++i){
		if(s[i] == '0'){
			if(pre == i - 1) ans += 2;
			else if(pre == i - 2) ans++;
			pre = i;
		}
	}
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