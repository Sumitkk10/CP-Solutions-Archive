#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	string s;
	cin >> s;
	long long int ans = 0;
	int ct = 0, ct1 = 0;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '(') ++ct;
		else if(s[i] == '[') ++ct1;
		if(s[i] == ')' && ct){
			--ct;
			++ans;
		}
		else if(s[i] == ']' && ct1){
			--ct1;
			++ans;
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
