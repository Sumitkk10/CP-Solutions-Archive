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
	int i = 0;
	while(i < s.size()){
		if(s[i] == 'a' and s[i + 1] == 'b' and s[i + 2] == 'c'){
			s.erase(s.begin() + i, s.begin() + i + 3);
			i = -1;
		}
		++i;
	} 
	cout << s << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
