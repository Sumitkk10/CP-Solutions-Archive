#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 42373;
int n, m;

void solve(){
	cin >> n >> m;
	string s[2*n];
	for(int i = 1; i < 2*n; ++i)
		cin >> s[i];
	map<pair<int, char>, int> mp, another;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < s[i].size(); ++j)
			mp[{j, s[i][j]}]++;
	}
	for(int i = n + 1; i <2*n; ++i){
		for(int j = 0; j < s[i].size(); ++j)
			another[{j, s[i][j]}]++;
	}
	for(int i = 1; i <= n; ++i){
		bool ok = 1;
		for(int j = 0; j < s[i].size(); ++j){
			if(mp[{j, s[i][j]}] - 1 != another[{j, s[i][j]}])
				ok = 0;
		}
		if(ok){
			cout << s[i] << endl;
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