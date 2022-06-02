#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(s.size() % 2){
			cout << "NO\n";
			continue;
		}
		if(s[0] == ')'){
			cout << "NO\n";
			continue;
		}
		if(s[s.size() - 1] == '('){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
	return 0;
}
// ([([](()))])