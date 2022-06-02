#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 5e5 + 5, MOD = 1e9 + 7;

void solve(){
	string s;
	cin >> s;
	vector<string> ans;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '0') continue;
		string res;
		res.push_back(s[i]);
		for(int j = i + 1; j < s.size(); ++j)
			res.push_back('0');
		ans.push_back(res);
	}
	cout << ans.size() << '\n';
	for(auto k : ans)
		cout << k << ' ';
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