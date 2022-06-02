#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int N = 1e6 + 5;
int n;

void solve(){
	cin >> n;
	vector<pair<int, int> > a;
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		a.push_back({x, i - 1});
	}
	sort(a.begin(), a.end());
	vector<int> ans(n);
	int ct = 0;
	for(int i = 0; i < a.size(); ++i){
		if(ct >= a[i].first){
			ans[a[i].second] = a[i].first - 1;
			continue;
		}
		ans[a[i].second] = ct;
		++ct;
	}
	for(auto k : ans)
		cout << k << ' ';
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
