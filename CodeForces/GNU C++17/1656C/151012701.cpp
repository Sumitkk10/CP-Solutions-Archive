#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n];
	bool ok = 1;
	set<int> s;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] == 1)
			ok = 0;
		s.insert(a[i]);
	}
	if(ok or s.size() == 1){
		cout << "YES\n";
		return;
	}
	sort(a, a + n);
	for(int i = 1; i < n; ++i){
		if(a[i] == a[i - 1] + 1){
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}