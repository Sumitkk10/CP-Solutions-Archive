#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N];

bool check(int x){
	int i = x, lst = n;
	while(i > 0){
		int req = 2*a[i];
		int low = x + 1, high = lst, ans = -1;
		while(low <= high){
			int mid = (low + high) / 2;
			if(a[mid] >= req){
				ans = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		if(ans == -1) return false;
		i -= (lst - ans + 1);
		lst = ans - 1;
	}
	return true;
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int low = 0, high = n / 2, ans;
	while(low <= high){
		int mid = (low + high) / 2;
		if(check(mid)){
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans + (n - 2*ans) << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}