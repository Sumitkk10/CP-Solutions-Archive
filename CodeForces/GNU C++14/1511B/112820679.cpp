#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	string s;
	for(int i = 1; i <= c; ++i)
		s.push_back('1');
	long long ok = stoll(s), okk = ok;
	while(true){
		string s = to_string(ok);
		if(s.size() == a){
			cout << s << ' ';
			break;
		}
		ok *= 11;
	}
	while(true){
		string s = to_string(okk);
		if(s.size() == b){
			cout << s << ' ';
			break;
		}
		okk *= 13;
	}
	cout << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
