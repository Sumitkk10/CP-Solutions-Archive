#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e5 + 3;
int n, a[N];

bool check(int mid){
	for(int i = 1; i <= mid ; ++i)
		if(a[i] - a[i - 1] < a[mid]) return false;
	return true;
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	int low = 0, high = n - 1, ans = 1;
	while(low <= high){
		int mid = (low + high) / 2;
		if(check(mid)){
			ans = mid + 1;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--) solve();
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}