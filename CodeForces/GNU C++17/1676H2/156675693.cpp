/*
started at 20:35
*/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;
int fenwick[N], n, a[N];

void update(int node, int val){
    for(int i = node; i <= n; i += (i & -i))
        fenwick[i] += val;
}

long long get(int node){
    long long ans = 0;
    for(int i = node; i >= 1; i -= (i & -i))
        ans += fenwick[i];
    return ans;
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		fenwick[i] = 0;
	}
	fenwick[n] = 0;
	update(a[0], 1);
	long long ans = 0;
	for(int i = 1; i < n; ++i){
		ans += (i - get(a[i] - 1));
		update(a[i], 1);
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}