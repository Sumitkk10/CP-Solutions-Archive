#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const long long int N = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int u[n], s[n];
	long long res[n + 1];
	memset(res, 0, sizeof res);
	vector<int> v[n + 1];
	for(int i = 0; i < n; ++i) 
		cin >> u[i];
	long long sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> s[i];
		sum += s[i];
		v[u[i]].push_back(s[i]);
		res[u[i]] += s[i];
	}
	for(int i = 1; i <= n; ++i)
		if(v[i].size())
			sort(v[i].begin(), v[i].end());
	vector<pair<int, int> > ok;
	int mx = 0;
	vector<long long int> pre[n + 1];
	for(int i = 1; i <= n; ++i){
		mx = max(mx, (int) v[i].size());
		if(v[i].size())
			ok.push_back({v[i].size(), i});
		for(auto k : v[i]){
			if(pre[i].size() == 0) pre[i].push_back(k);
			else pre[i].push_back(pre[i][pre[i].size() - 1] + k);
		}
	}
	sort(ok.begin(), ok.end());
	for(int i = 1; i <= mx; ++i){
		if(i == 1)
			cout << sum << ' ';
		else{
			long long sum1 = 0;
			int low = 0, high = ok.size() - 1, idx = 0;
			while(low <= high){
				int mid = (low + high) / 2;
				if(ok[mid].first >= i){
					idx = mid;
					high = mid - 1;
				}
				else
					low = mid + 1;
			}
			for(int j = idx; j <= ok.size() - 1; ++j){
				if(ok[j].first % i == 0)
					sum1 += res[ok[j].second];
				else{
					int rem = v[ok[j].second].size() % i;
					sum1 += res[ok[j].second] - pre[ok[j].second][rem - 1];
				}
			}
			cout << sum1 << ' ';
		}
	}
	for(int j = mx + 1; j <= n; ++j)
		cout << "0 ";
	cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}