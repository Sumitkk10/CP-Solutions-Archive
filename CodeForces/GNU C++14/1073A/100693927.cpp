#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < s.size() - 1; ++i){
		if(s[i] != s[i + 1]){
			cout << "YES\n";
			cout << s[i] << s[i + 1] << '\n';
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}