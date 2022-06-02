#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define pii pair<long long, pair<int, int> >
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5;
long long n, w, a[N];

bool check(ll x){
	for(int i = 0; i < n; ++i){
		x += a[i];
		if(x < 0)
			return 0;
	}
	return 1;
}

bool checkk(ll x){
	for(int i = 0; i < n; ++i){
		x += a[i];
		if(x > w)
			return 0;
	}
	return 1;
}

void solve(){
	cin >> n >> w;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	long long low = 0, high = w, ok = -1;
	while(low <= high){
		long long mid = (low + (high - low) / 2);
		if(check(mid)){
			ok = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	low = 0, high = w;
	ll okk = -1;
	while(low <= high){
		long long mid = (low + (high - low) / 2);
		if(checkk(mid)){
			okk = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	if(!checkk(ok) or !check(okk)){
		cout << "0\n";
		return;
	}
	cout << okk - ok + 1 << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}