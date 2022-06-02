#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int l, area, perimeter, b;
	cin >> l >> b;
	area = l * b;
	perimeter = 2 * (l + b);
	if (area > perimeter)
	{
	    cout << "Area" << '\n';
	    cout << area << '\n';
	}
	else if (area < perimeter)
	{
	    cout << "Peri" << '\n';
	    cout << perimeter << '\n';
	}
	else if (area == perimeter)
	{
	    cout << "Eq" << '\n';
	    cout << area << '\n';
	}
	return 0;
}
