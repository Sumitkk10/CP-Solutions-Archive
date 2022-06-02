#include <iostream>
using namespace std;

int main() 
{
	int n, i, ans = 0, k, x, y, t, p, r;
	cin >> t;
	for(i = 0; i < t; i++)
	{
	    cin >> x >> y >> k >> n;
	    int p[n];
	    int r[n];
	    int pages = x - y;
	    for(int j = 0; j < n; j++)
	    {
	        cin >> p[j] >> r[j];
	    }
	    for(int j = 0; j < n; j++)
	    {
	        if (p[j] >= pages && r[j] <= k) ans++;
	    }
	    if(ans >= 1)
	        cout << "LuckyChef" << '\n';
	    else
	        cout << "UnluckyChef" << '\n';
	    ans = 0;
	}
	return 0;
}
