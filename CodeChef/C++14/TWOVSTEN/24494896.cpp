#include <iostream>
using namespace std;

int main() 
{
	int n, k, i;
	cin >> n;
	int a[n];
	for(i = 0; i < n; i++)
	    cin >> a[i];
	for(i = 0; i < n; i++)
	{
	    if(a[i] % 10 == 0)
	        cout << 0 << '\n';
        else if(a[i] % 5 == 0 && a[i] % 10 != 0)
            cout << 1 << '\n';
        else 
            cout << -1 << '\n';
	}
	return 0;
}
