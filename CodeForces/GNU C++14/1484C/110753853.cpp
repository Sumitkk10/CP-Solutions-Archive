#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a[m], ans(m);
	vector<pair<int, int> > v;
	for(int i = 0; i < m; ++i){
		int k;
		cin >> k;
		v.push_back({k, i});
		for(int j = 0; j < k; ++j){
			int x;
			cin >> x;
			--x;
			a[i].push_back(x);
		}
	}
	int cnt[n + 1] = {0};
	sort(v.begin(), v.end());
	for(int i = 0; i < m; ++i){
      	bool ok = 0;
		for(auto k : a[v[i].second]){
			if(cnt[k] < (m + 1)/2){
				cnt[k]++;
				ans[v[i].second] = k;
				ok = 1;
              	break;
			}
		}
		if(!ok){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for(auto k : ans)
		cout << k + 1 << ' ';
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}