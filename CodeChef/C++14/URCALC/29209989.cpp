#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n, m;
	cin >> m >> n;
	char c;
	cin >> c;
	if(c == '+')
		cout << m + n;
	else if(c == '-')
		cout << m -n;
	else if(c == '*')
		cout << m * n;
	else if(c == '/')
		cout <<fixed<< setprecision(6) << m / n ;
	return 0;
}