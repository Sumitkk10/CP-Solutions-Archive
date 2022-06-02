#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
	long long int t, k, a, ans = 0;
	cin >> t >> k;
	while(t--){
		cin >> a;
		if(a%k == 0)
			ans++;
	}
	cout << ans;
	return 0;
}