#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	multiset<int> s;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		s.insert(x);
	}
	int cur = k, ans = 1;
	while(!s.empty()){
		if(s.upper_bound(cur) != s.begin()){
			int ok = cur;
			// cout <<  *(--(upper_bound(s.begin(), s.end(), cur))) << " ";
			cur = cur - *(--(s.upper_bound(cur)));
			s.erase(--(s.upper_bound(ok)));
		}
		else{
			++ans;
			cur = k;
		}
	}
	cout << ans << "\n";
}

int main(){
    fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}