#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n; cin >> n;
		string s;
		cin >> s;
		ll x = 0, y = 0;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == 'U') ++y;
			else if(s[i] == 'D') --y;
			else if(s[i] == 'R') ++x;
			else if(s[i] == 'L') --x;
		}
		cout << s.size() - (abs(x) + abs(y)) << "\n";
	}
	return 0;
}
