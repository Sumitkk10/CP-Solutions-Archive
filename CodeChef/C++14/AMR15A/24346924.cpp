#include <iostream>
using namespace std;

int main() 
{
	int n, k = 0, i, b = 0;
	cin >> n;
	int a[n];
	for(i = 0; i < n; i++)
	    cin >> a[i];
	for(i = 0; i < n; i++)
	{
	    if(a[i] % 2 == 0)
	        k++;
	   else
	        b++;
	}
	if(k > b)
	cout << "READY FOR BATTLE";
	else
	cout << "NOT READY";
	return 0;
}
