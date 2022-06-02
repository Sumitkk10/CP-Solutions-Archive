#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 3e5 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n];
	map<int, int> mp;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] == 0){
		    if(!mp[a[i]]) ++ans;
		}
		else if(mp[abs(a[i])] <= 1) ++ans;
		mp[abs(a[i])]++;
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