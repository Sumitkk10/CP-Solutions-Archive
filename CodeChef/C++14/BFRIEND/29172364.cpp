#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		long long int n, a, b, c, ans = 0, min = 100000000000000, sol;
		cin >> n >> a >> b >> c;
		long long int z[n];
		for(int j = 0; j < n; j++)
			cin >> z[j];
		for(int j = 0; j < n; j++)
		{
			ans = b - z[j];
			ans = abs(ans);
			ans += abs(z[j] - a);
			if(ans <= min){
				min = ans;
			}
		}
		cout << min + c << '\n';
	}
	return 0;
}