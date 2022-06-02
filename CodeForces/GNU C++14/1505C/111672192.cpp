#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

void solve(){
	string s;
	cin >> s;
	if(s.size() <= 2){
		cout << "YES\n";
		return;
	}
	for(int i = 2; i < s.size(); ++i){
		int pre1 = s[i - 2] - 'A';
		int pre = s[i - 1] - 'A';
		if(s[i] - 'A' != (pre + pre1) % 26){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
    fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}