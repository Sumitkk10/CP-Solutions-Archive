#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, k, cnt = 0, i;
    cin >> n;
    long long int a[n];
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
    {
        while(a[i] > 0)
        {
            k = a[i] % 10;
            if(k == 4)
                cnt++;
            a[i] = a[i] / 10;
        }
        
        cout << cnt << '\n';
        cnt = 0;
    }
    return 0;
}
