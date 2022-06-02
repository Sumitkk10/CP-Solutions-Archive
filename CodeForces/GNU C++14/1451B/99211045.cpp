#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	map<char, vector<int> > pos;
	for(int i = 0; i < s.size(); ++i)
		pos[s[i]].push_back(i);
	while(q--){
		int l, r;
		cin >> l >> r;
		--l, --r;
		if(pos[s[l]][0] == l and pos[s[r]][pos[s[r]].size() - 1] == r)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
