#include <iostream>
using namespace std;
 
int main() 
{
	int t, n, i, ans = 0, j, p, q;
	cin >> t;
	for(i = 0; i < t; i++)
	{
	    cin >> p >> q; 
	    int a[p];
	    for (j = 0; j < p; j++)
	    {
	        cin >> a[j];
	    }
	    for (j = 0; j < p; j++)
	    {
	        ans += a[j];
	    }
	    if (ans <= q)
	        cout << "Yes" << '\n';
	   else
	        cout << "No" << '\n';
	   ans = 0;
	}
	return 0;
}