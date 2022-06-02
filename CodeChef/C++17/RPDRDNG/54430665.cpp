#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define F first
#define S second
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll n, a[N];

void solve(){
	cin >> n;
	set<int> s;
	map<int, int> mp;
	for(int i = 1; i <= 2 * n; ++i){
		cin >> a[i];
		s.insert(a[i]);
		mp[a[i]]++;
	}
	vector<int> v;
	for(auto k : s)
		v.push_back(k);
	if(s.size() != n){
	    cout << "-1\n";
	    return;
	}
	if(n == 1){
	    cout << a[1] << '\n';
	    return;
	}
	int ok = n/2;
	if(n % 2 == 0) --ok;
	if(mp[v[ok]] != 3 or mp[v[n - 1]] != 1){
		cout << "-1\n";
		return;
	}
	for(int i = 0; i < n - 1; ++i){
		if(i == ok) continue;
		if(mp[v[i]] != 2){
			cout << "-1\n";
			return;
		}
	}
	for(auto k : v)
		cout << k << ' ';
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