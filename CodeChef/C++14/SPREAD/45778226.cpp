#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
long long int n, c, fenwick[N];

void update(int node, int upd){
	for(int i = node; i <= n; i += (i & -i))
		fenwick[i] += upd;
}

long long get(int node){
	long long ans = 0;
	for(int i = node; i >= 1; i -= (i & -i))
		ans += fenwick[i];
	return ans;
}

int main() {
	fast;
	int q;
	cin >> n >> q >> c;
	while(q--){
		char a;
		cin >> a;
		if(a == 'S'){
			int u, v, k;
			cin >> u >> v >> k;
			update(u, k);
			update(v + 1, -k);
		}
		else{
			int p;
			cin >> p;
			cout << get(p) + c << '\n';
		}
	}
}