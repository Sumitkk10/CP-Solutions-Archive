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
	int n = s.size();
	if(n % 2 == 1){
		cout << "-1\n";
		return;
	}
	int cnt = 0, cnt1 = 0;
	for(auto k : s){
		cnt += (k == '0');
		cnt1 += (k == '1');
	}
	if(cnt == 0 or cnt1 == 0){
		cout << "-1\n";
		return;
	}
	n /= 2;
	cout << abs(min(cnt, cnt1) - n) << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}