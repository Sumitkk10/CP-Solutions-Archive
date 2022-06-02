#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

bool is_palindrome(ll x){
	string s = to_string(x);
	ll j = s.size() - 1;
	for(int i = 0; i < s.size() / 2; ++i){
		if(s[i] != s[j])
			return false;
		--j;
	}
	return true;
}

int main(){
	fast;
	ll x;
	cin >> x;
	ll a = x;
	while(!is_palindrome(x))
		--x;
	cout << x << " " << a - x << "\n";
	return 0;
}
