#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans;
	if(n % 2){
		ans.push_back(s[n/2]);
		string temp;
		for(int i = 0; i < n; ++i){
			if(i != n / 2)
				temp.push_back(s[i]);
		}
		s = temp;
		--n;
	}
	int i = n / 2 - 1;
	int j = n / 2, ct = 0;
	while(i >= 0 and j < n){
		if(ct % 2 == 0){
			ans.push_back(s[i]);
			--i;
		}
		else{
			ans.push_back(s[j]);
			++j;
		}
		++ct;
	}
	while(i >= 0){
		ans.push_back(s[i]);
		--i;
	}
	while(j < n){
		ans.push_back(s[j]);
		++j;
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