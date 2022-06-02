#include <iostream>
using namespace std;

int main() 
{
	int n, k = 0;
	cin >> n;
	while(n > 0)
	{
	    n = n / 10;
	    k++;
	}
	if (k <= 3)
	    cout << k;
	else 
	    cout << "More than 3 digits";
	return 0;
}
