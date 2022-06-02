#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 200001;
long long n, a[N], bits[N], fenwick[N];

void upd(int node, int val){
	for(int i = node; i <= n; i += (i & -i))
		fenwick[i] += val;
}

int find(int node){
	int sum = 0;
	for(int i = node; i >= 1; i -= (i & -i))
		sum += fenwick[i];
	return sum;
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		upd(i, 1);
	}
	int q = n;
	while(q--){
		int pos;
		cin >> pos;
		int low = 1, high = n, ans;
		while(low <= high){
			int mid = (low + high) / 2;
			int ok = find(mid);
			if(ok >= pos){
				ans = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		upd(ans, -1);
		cout << a[ans] << ' ';
	}
}
 
int main() {
	fast;
	int t = 1;
 	// cin >> t;
	while(t--)
		solve();
	return 0;
}