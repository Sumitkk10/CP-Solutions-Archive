#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
#define pii pair<long long, pair<int, int> >
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
long long hc, dc, hm, dm, k, w, a;

void solve(){
	cin >> hc >> dc;
	cin >> hm >> dm;
	cin >> k >> w >> a;
	for(int i = 0; i <= k; ++i){
		// you give i strength to character and (k - i) armour to him;
		long long _dc = dc + i*w;
		long long _hc = hc + (k - i)*a;
		long long steps = (hm + _dc - 1) / _dc;
		long long steps_mon = (_hc + dm - 1) / dm;
		if(steps <= steps_mon){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
}