#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i;
    cin >> n;
    int a[3];
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < 3; i++)
        {
            cin >> a[i];
        }
        sort (a + 0, a + 3);
        cout << a[1] << '\n';
    }
    return 0;
}

