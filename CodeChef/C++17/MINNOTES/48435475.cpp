#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int main() {
	fast;
	int t = 1;
 	cin >> t;
	while(t--){
		long long int n;
		cin >> n;
		long long int a[n + 1], pre[n + 1], suf[n + 1];
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		pre[0] = suf[n + 1] = 0;
		pre[1] = a[1];
		for(int i = 2; i <= n; ++i)
			pre[i] = gcd(pre[i - 1], a[i]);
		suf[n] = a[n];
		for(int i = n - 1; i >= 1; --i)
			suf[i] = gcd(suf[i + 1], a[i]);
		long long max_gcd = 0, idx, res = 0, greatest = 0;
		for(int i = 1; i <= n; ++i){
			long long cur = gcd(pre[i - 1], suf[i + 1]);
			if(cur > max_gcd){
				max_gcd = cur;
				idx = i;
				greatest = a[i];
			}
			else if(cur == max_gcd and a[i] > greatest){
			    idx = i;
			    greatest = a[i];
			}
		}
		for(int i = 1; i <= n; ++i){
			if(i == idx) ++res;
			else res += (a[i] / max_gcd);
		}
		cout << res << '\n';
	}
	return 0;
}    