#include <iostream>
using namespace std;

int main() 
{
	int n, i;
	cin >> n;
	int a[n], k[n];
	for(i = 0; i < n; i++)
	    cin >> a[i] >> k[i];
	for(i = 0; i < n; i++)
	{
	    if(a[i] > k[i])
	        cout << a[i] << ' ';
	    else if(a[i] <= k[i])
	        cout << k[i] << ' ';
	    cout << a[i] + k[i] << ' ';
	}
	return 0;
}
