#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 2;

void solve(){
	long long n;
	cin >> n;
	long long sum = 0, ans = 0, cur = 1;
	while(sum < n){
		sum += cur;
		if(sum <= n)
			ans += cur*cur;
		else{
			sum -= cur;
			long long left = n - sum;
			ans += cur*left;
			break;
		}
		++cur;
	}
	cout << ans << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}