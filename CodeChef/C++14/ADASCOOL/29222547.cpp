#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
	long long int t;
	cin >> t;
	while(t--){
		long long int n, m;
		cin >> n >> m;
		long long int ans = n * m;
		if(ans % 2 == 0)
			cout <<"YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}