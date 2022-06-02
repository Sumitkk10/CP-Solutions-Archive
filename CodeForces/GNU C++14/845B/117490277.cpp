#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
string s, cur;

bool check(string ok){
	int ss = 0, ss1 = 0;
	for(int i = 0; i < 3; ++i) ss += (ok[i] - '0');
	for(int i = 3; i < 6; ++i) ss1 += (ok[i] - '0');
	return (ss == ss1);
}

long long go(int i){
	if(i == 6){
		if(!check(cur)) return INT_MAX;
		int res = 0;
		for(int i = 0; i < cur.size(); ++i){
			if((s[i] - '0') != (cur[i] - '0'))
				++res;
		}
		return res;
	}
	long long ans = INT_MAX;
	for(int j = 0; j <= 9; ++j){
		cur.push_back(j + '0');
		ans = min(ans, go(i + 1));
		cur.pop_back();
	}
	return ans;
}

void solve(){
	cin >> s;
	cout << go(0) << '\n';
}

int main() {
	fast;
	int t = 1;
    // cin >> t;
	while(t--)
		solve();
}