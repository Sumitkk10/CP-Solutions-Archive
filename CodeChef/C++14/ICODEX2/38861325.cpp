#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	ll ans = 0;
	ll n, ct = 0;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < n; ++i){
		if(s[i] == 'D') --ct;
		else ++ct;
		if(ct == 0 && s[i] == 'U') ++ans;
	}
	cout << ans;
	return 0;
}
