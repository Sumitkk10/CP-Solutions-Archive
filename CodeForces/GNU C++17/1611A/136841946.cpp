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
	bool ok = 0;
	for(auto k : s)
		if((k - '0') % 2 == 0)
			ok = 1;
	if(!ok){
		cout << "-1\n";
		return;
	}
	if((s[s.size() - 1] - '0') % 2 == 0){
		cout << "0\n";
		return;
	}
	if((s[0] - '0') % 2 == 0){
		cout << "1\n";
		return;
	}
	cout << "2\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}