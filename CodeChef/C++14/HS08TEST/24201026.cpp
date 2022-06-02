#include<bits/stdc++.h>
using namespace std;

int main()
{
    double k, ans;
    int n;
    cin >> n >> k;
    ans = k - (n + 0.5);
    if (k < n + 0.5)
        cout << fixed << setprecision(2) << k;
    else if (n % 5 != 0)
        cout << fixed << setprecision(2) << k;
    else
        cout << fixed << setprecision(2) << ans;
   return 0;
}
