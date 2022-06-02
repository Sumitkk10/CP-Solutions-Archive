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
	string s;
	cin >> s;
	int cnt = 0, cnt1 = 0;
	for(auto k : s){
		cnt += (k == 'A');
		cnt1 += (k == 'D');
	}
	if(cnt == cnt1){
		cout << "Friendship\n";
		return;
	}
	cout << (cnt > cnt1 ? "Anton\n" : "Danik\n");
}

int main(){
	fast;
	int t = 1;
	// cin >> t; 
	while(t--)
		solve();
	return 0;
}
