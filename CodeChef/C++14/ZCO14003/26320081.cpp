#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, i, j, sum = 0, count;
    cin >> n;
    int a[n];
    for(i = 0; i < n; i++)
        cin >> a[i];
    sort(a+0,a+n);
    for(i = 0; i < n; i++)
        {
            count = a[i] * (n - i);
            if (sum < count)
                sum = count;
        }
    cout << sum;
    return 0;
}