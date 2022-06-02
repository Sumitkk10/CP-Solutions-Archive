#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;

void solve(){
	long long n, q;
	cin >> n >> q;
	long long a[n], sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	long long pre[n] = {0}, prev, recent = -1;
	for(int i = 0; i < q; ++i){
		int t;
		cin >> t;
		if(t == 1){
			long long ind, x;
			cin >> ind >> x;
			if(pre[ind - 1] > recent)
				sum -= a[ind - 1];
			else
				sum -= prev;
			sum += x;
			a[ind - 1] = x;
			pre[ind - 1] = i;
		}
		else{
			long long x;
			cin >> x;
			prev = x;
			recent = i;
			sum = n*x;

		}
		cout << sum << '\n';
	}
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}