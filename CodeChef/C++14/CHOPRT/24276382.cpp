#include <iostream>
using namespace std;

int main() 
{
    long long int n, i, k;
    cin >> n;
    long long int a[n], b[n];
    for(i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for(i = 0; i < n; i++)
    {
        if(a[i] > b[i])
            cout << ">" << '\n';
        else if(a[i] < b[i])
            cout << "<" << '\n';
        else if(a[i] == b[i])
            cout << "=" << '\n';
    }
	return 0;
}
