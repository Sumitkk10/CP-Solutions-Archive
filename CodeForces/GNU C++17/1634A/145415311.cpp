#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define F first
#define S second
#define pb push_back
const int N = 1e6 + 5, MOD = 1e9 + 7;

bool is_palindrome(string s, int n){
	int i = 0, j = n - 1;
	while(i <= j){
		if(s[i] != s[j])
			return false;
		++i;
		--j;
	}
	return true;
}

void solve(){
	int n, k;
	string s;
	cin >> n >> k >> s;
	if(k == 0){
	     cout << "1\n";
	     return;
	}
	if(is_palindrome(s, n)) cout << "1\n";
	else cout << "2\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}