#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum = 0, i, firstdigit, lastdigit;
    cin >> n;
    int a[n];
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
    {
        lastdigit = a[i] % 10;
        firstdigit = a[i];
        while(a[i] >= 10)
        {
            a[i] = a[i] / 10;
        }
        firstdigit = a[i];
        sum = firstdigit + lastdigit;
        cout << sum << '\n';
    }
    return 0;
}
