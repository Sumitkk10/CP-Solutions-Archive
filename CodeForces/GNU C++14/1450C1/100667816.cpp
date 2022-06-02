#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	string s[n];
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	int cnt = 0, cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < s[i].size(); ++j){
			if((i + j) % 3 == 0 and s[i][j] == 'X')
				++cnt;
			if((i + j) % 3 == 1 and s[i][j] == 'X')
				++cnt1;
			if((i + j) % 3 == 2 and s[i][j] == 'X')
				++cnt2;
		}
	}
	if(cnt <= cnt1 and cnt <= cnt2){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < s[i].size(); ++j)
				if((i + j) % 3 == 0 and s[i][j] == 'X')
					s[i][j] = 'O';
			cout << s[i] << '\n';
		}
		return;
	}
	if(cnt1 <= cnt and cnt1 <= cnt2){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < s[i].size(); ++j)
				if((i + j) % 3 == 1 and s[i][j] == 'X')
					s[i][j] = 'O';
			cout << s[i] << '\n';
		}
		return;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < s[i].size(); ++j)
			if((i + j) % 3 == 2 and s[i][j] == 'X')
				s[i][j] = 'O';
		cout << s[i] << '\n';
	}
	return;
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
