#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int test = 0;test < t; test++){
		long long int n, k;
		cin >> n >> k;
		int cnt = 0, ans = 0, sum = 0;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			if(a[i] >= k){
				cnt++;
				sum += a[i] - k;
			}
			else {
				if((a[i] + sum) >= k){
					cnt++;
					sum = a[i] + sum - k;
				}
				else{
					ans = i + 1;
					break;
				}
			}
		}
		if(cnt == n)
			cout << "YES" << '\n';
		else
			cout << "NO" << ' ' << ans << '\n';
	}
	return 0;
}