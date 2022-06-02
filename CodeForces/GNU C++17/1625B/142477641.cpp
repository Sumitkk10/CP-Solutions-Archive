#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n];
	map<int, vector<int> > pos;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		pos[a[i]].push_back(i + 1);
	}
	int ans = -1;
	for(auto k : pos){
		if(k.S.size() < 2) continue;
		for(int j = 1; j < k.S.size(); ++j){
			if(ans == -1 or (k.S[j - 1] + (n - k.S[j])) > ans)
				ans = (k.S[j - 1] + (n - k.S[j]));
		}
	}
	cout << ans << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}