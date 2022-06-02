#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 42373;

void solve(){
	int n;
	cin >> n;
	int a[n + 1], b[n + 1];
	map<int, vector<int> > mp;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		b[i] = a[i];
		mp[a[i]].push_back(i % 2);
	}
	sort(b + 1, b + n + 1);
	map<int, vector<int> > pos;
	for(int i = 1; i <= n; ++i)
	    pos[b[i]].push_back(i % 2);
	for(int i = 1; i <= N; ++i){
		if(!mp[i].size()) continue;
		int ct = 0, ct1 = 0;
		for(auto k : mp[i]){
			ct += (k == 0);
			ct1 += (k == 1);
		}
		for(auto k : pos[i]){
			ct -= (k == 0);
			ct1 -= (k == 1);
		}
		if(ct or ct1){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}