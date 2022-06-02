#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define pii pair<long long, pair<int, int> >
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5;
int n, m, k;
long long a[N];

void solve(){
	cin >> n >> m >> k;
	for(int i = 0; i <= m; ++i)
		cin >> a[i];
	string check;
	long long x = a[m];
	while(x){
		if(x % 2) check.pb('1');
		else check.pb('0');
		x /= 2;
	}
	int ans = 0;
	for(int i = 0; i < m; ++i){
		string temp;
		long long x = a[i];
		while(x){
			if(x % 2) temp.pb('1');
			else temp.pb('0');
			x /= 2;
		}
		while(temp.size() < check.size())
			temp.pb('0');
		reverse(temp.begin(), temp.end());
		string cur = check;
		while(cur.size() < temp.size())
			cur.pb('0');
		reverse(cur.begin(), cur.end());
		int ok = 0;
		for(int i = 0; i < cur.size(); ++i)
			ok += (cur[i] != temp[i]);
		ans += (ok <= k);
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}