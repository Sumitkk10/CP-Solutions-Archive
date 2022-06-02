#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
	long long int t;
	cin >> t;
	while(t--){
		long long int n, k, ans = 0, a;
		cin >> n >> k;
		while(n--){
			cin >> a;
			a = a + k;
			if (a % 7 == 0)
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}