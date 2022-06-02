#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define F first
#define ll long long
#define S second
#define pb push_back
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i; j < n; ++j){
			multiset<int> s;
			for(int k = i; k <= j; ++k)
				s.insert(a[k]);
			while(!s.empty()){
				int x = 0;
				while(!s.empty()){
					auto left = s.lower_bound(x);
					if(left == s.end()) break;
					if((*left) != x) break;
					s.erase(left);
					++x;
				}
				if(x == 0) break;
				ans += x + 1;
			}
			ans += s.size();
		}
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