#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e7 + 5;
const int MOD = 1e9 + 7;
int next_greater[N];

void compute(int a[], int n){
	stack<int> stk;
	for(int i = 0; i < n; ++i){
		while(!stk.empty() && a[stk.top()] < a[i]){
			next_greater[stk.top()] = i;
			stk.pop();
		}
		stk.push(i);
	}
}

void solve(){
	memset(next_greater, -1, sizeof(next_greater));
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	compute(a, n);
	int q;
	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		--a, --b;
		if(next_greater[a] < b && next_greater[a] != -1)
			cout << "NO\n";
		else
			cout << "YES\n";
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
