#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		long long int n, max = 0;
		cin >> n;
		long long int s, p, v, ans = 0;
		for(int j = 0; j < n; j++)
		{
			cin >> s >> p >> v;
			ans = (p/(s+1)) * v;
			if(ans >= max)
				max = ans;
		}
		cout << max <<'\n';
	}
	return 0;
}