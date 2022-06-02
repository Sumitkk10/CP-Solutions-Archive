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
	string s;
	cin >> s;
	string ans;
	int cnt = 0;
	for(auto k : s){
		if(k == 't'){
			cnt++;
			continue;
		}
		ans.push_back(k);
	}
	while(cnt--)
		ans.push_back('t');
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
