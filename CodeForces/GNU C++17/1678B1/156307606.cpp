#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;

void solve(){
	int n, ans = 0;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < n;){
		int ct = 0, j = i;
		char x = s[i];
		while(s[j] == x and i < n){
			++j;
			++ct;
		}
		if(ct % 2){
			++ans;
			if(j < n and s[j] == '1')
				s[j] = '0';
			else if(j < n)
				s[j] = '1';
			i = j + 1;
		}
		else
			i = j;
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}