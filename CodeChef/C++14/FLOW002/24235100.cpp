#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n;
    int a[n];
    int b[n];
    for(i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for(i = 0; i < n; i++)
    {
        cout << a[i] % b[i] << '\n';
    }
    return 0;
}
