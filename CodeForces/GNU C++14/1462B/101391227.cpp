#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool check(string s){
	int n = s.size();
	if(s[0] == '2' and s[1] == '0' and s[2] == '2' and s[3] == '0')
		return true;
	if(s[n - 4] == '2' and s[n - 3] == '0' and s[n - 2] == '2' and s[n - 1] == '0')
		return true;
	if(s[0] == '2' and s[n - 3] == '0' and s[n - 2] == '2' and s[n - 1] == '0')
		return true;
	if(s[0] == '2' and s[1] == '0' and s[n - 2] == '2' and s[n - 1] == '0')
		return true;
	if(s[0] == '2' and s[1] == '0' and s[2] == '2' and s[n - 1] == '0')
		return true;
	return false;
}

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	cout << (check(s) ? "YES\n" : "NO\n");
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
