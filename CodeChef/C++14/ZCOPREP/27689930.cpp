#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m, s;
		cin >> n >> m >> s;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		int pt = 0, ct = 0, ans = 0;
		for(int i = 0; i < m && pt < n; i++){
			a[pt] -= s;
			ct++;
			if(a[pt] <= 0){
				pt++;
				if(ct <= 2) ans++;
				ct = 0;
			}
		}
		cout << ans << "\n";
	}
 
	return 0;
}