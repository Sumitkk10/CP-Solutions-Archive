#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ok[s.size()] = {0};
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '1') continue;
		if(s[i - 1] == '1' and s[i + 1] == '1') continue;
		if(s[i - 1] == '1' or s[i + 1] == '1'){
			ok[i] = true;
			continue;
		}
		int cur = -1, cur1 = -1;
		for(int j = i - 1; j >= 0; --j){
			if(s[j] == '1'){
				cur = j;
				break;
			}
		}
		for(int j = i + 1; j < s.size(); ++j){
			if(s[j] == '1'){
				cur1 = j;
				break;
			}
		}
		if(cur != -1 and cur1 != -1){
			if(min(i - cur, cur1 - i) <= k){
				if(i - cur == cur1 - i) continue;
				ok[i] = true;
				continue;
			}
		}
		else if(cur != -1){
			if(i - cur <= k){
				ok[i] = true;
				continue;
			}
		}
		else if(cur1 != -1){
			if(cur1 - i <= k){
				ok[i] = true;
				continue;
			}
		}
	}
	for(int i = 0; i < s.size(); ++i){
		if(ok[i]){
			s[i] = '1';
		}
	}
	cout << s << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve(); 
	return 0;
}