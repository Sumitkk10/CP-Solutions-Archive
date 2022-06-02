#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int t = 1;
	while(t--){
		long long int n, q;
		cin >> n >> q;
		long long int a[n], ans[52];
		memset(ans, -1, sizeof ans);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			if(ans[a[i]] == -1)
				ans[a[i]] = i + 1;
		}
		while(q--){
			int x;
			cin >> x;
			cout << ans[x] << ' ';
			for(int i = 1; i <= 50; ++i)
				if(ans[i] != -1 and ans[i] < ans[x])
					ans[i]++;
			ans[x] = 1;
		}
	}
	return 0;
}
