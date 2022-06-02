#include<iostream>
using namespace std;

int main()
{
    long long int n, k, i, ans = 0;
    cin >> n >> k;
    long long int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] % k == 0)
            ans++;
    }
    cout << ans;
    return 0;
}
