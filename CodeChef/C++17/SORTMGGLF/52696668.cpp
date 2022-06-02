#include <bits/stdc++.h>
#define _f(n) for(int i = 0; i < n; ++i)
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    _f(n) cin >> a[i];
    _f(n) cin >> b[i];
    _f(n) c[b[i] - 1] = a[i];
    _f(n) cout << c[i] << ' ';
    cout << "\n";
    return 0;
}