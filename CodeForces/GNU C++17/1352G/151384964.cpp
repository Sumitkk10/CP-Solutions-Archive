/*
I have 0 idea how to solve this :weary:
*/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 2e5 + 5, MOD = 998244353;

void solve(){
	int n;
	cin >> n;
	if(n < 4){
		cout << "-1\n";
		return;
	}
	vector<int> ans;
	int str = n;
	if(n % 2 == 0)
		--str;
	while(str >= 1){
		ans.pb(str);
		str -= 2;
	}
	ans.pb(4);
	ans.pb(2);
	for(int i = 6; i <= n; i += 2)
		ans.pb(i);
	for(auto k : ans)
		cout << k << ' ';
	cout << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}