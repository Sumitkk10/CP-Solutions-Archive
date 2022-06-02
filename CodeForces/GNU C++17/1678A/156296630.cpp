#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;


void solve(){
	int n, ok = 0;
	cin >> n;
	set<int> s;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		s.insert(x);
		if(x == 0){
			ok++;
		}
	}
	if(ok){
		cout << n - ok << '\n';
		return;
	}
	if(s.size() == n)
		cout << n + 1 << '\n';
	else
		cout << n << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}