#include<math.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i;
    cin >> n;
    int a[n];
    // sqrt()
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i< n; i++)
    {
        k = sqrt(a[i]);
        cout << k << '\n';
        k = 0;
    }
    return 0;
}
