#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	map<int, int> mp;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		mp[x]++;
	}
	for(auto k : mp){
		if(k.second % 2 == 1){
			cout << k.first << '\n';
			return;
		}
	}
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
