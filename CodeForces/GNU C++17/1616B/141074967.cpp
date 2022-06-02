#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 3e5 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans;
	if(n == 1){
		cout << s[0] << s[0] << '\n';
		return;
	}
	if(s[1] == s[0]){
		cout << s[0] << s[0] << '\n';
		return;
	}
	ans.push_back(s[0]);
	for(int i = 1; i < s.size(); ++i){
		if(s[i] > s[i - 1]) break;
		if(s[i] < s[i - 1]){
		     ans.push_back(s[i]);
		     continue;
		}
		char x = s[i];
		int ct = 0;
		while(s[i] == x and i < n){
			++i;
			++ct;
		}
		if(i < n and s[i] < x){
			while(ct--)
				ans.push_back(x);
			ans.push_back(s[i]);
		}
		else{
		    while(ct--)
				ans.push_back(x);
			break;
		}
	}
	cout << ans;
	for(int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i];
	cout << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}