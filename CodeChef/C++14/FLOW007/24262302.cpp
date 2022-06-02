#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k = 0, i, ans;
    cin >> n;
    int a[n];
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
    {
        while(a[i] != 0)
        {
            ans = a[i] % 10;
            k = k * 10 + ans;
            a[i] /= 10;
        }
        cout << k << '\n';
        k = 0;
    }
    return 0;
}

