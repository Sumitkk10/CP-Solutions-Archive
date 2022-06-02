#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
#define pii pair<long long, pair<int, int> >
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	string s = to_string(n);
	int cur = n;
	string ans;
	int mn = INT_MAX;
	while(true){
		string a = to_string(cur);
		reverse(a.begin(), a.end());
		while(!a.empty() and a[a.size() - 1] == '0')
			a.pop_back();
		reverse(a.begin(), a.end());
		if(a.size() != s.size()) break;
		if(cur % 7){
			++cur;
			continue;
		}
		int ct = 0;
		for(int i = 0; i < a.size(); ++i)
			ct += (s[i] != a[i]);
		if(ct < mn){
			mn = ct;
			ans = a;
		}
		++cur;
	}
	cur = n - 1;
	while(cur >= 0){
		string a = to_string(cur);
		reverse(a.begin(), a.end());
		while(!a.empty() and a[a.size() - 1] == '0')
			a.pop_back();
		reverse(a.begin(), a.end());
		if(a.size() != s.size()) break;
		if(cur % 7){
			--cur;
			continue;
		}
		int ct = 0;
		for(int i = 0; i < a.size(); ++i)
			ct += (s[i] != a[i]);
		if(ct < mn){
			mn = ct;
			ans = a;
		}
		--cur;
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
}