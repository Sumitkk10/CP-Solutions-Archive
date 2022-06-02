#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i, ans, b, c, d, e, f, g, h, z, j;
    cin >> n;
    int a[n];
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
    {
        k = a[i] / 100;
        b = a[i] % 100;
        g = b / 50;
        c = b % 50;
        h = c / 10;
        d = c % 10;
        z = d / 5;
        e = d % 5;
        j = e / 2;
        f = e % 2;
        ans = k + g + h + z + j + f;
        cout << ans << '\n';
    }
    return 0;
}
