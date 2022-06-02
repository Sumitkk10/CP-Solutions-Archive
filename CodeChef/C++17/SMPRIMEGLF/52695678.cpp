#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n){
    for(long long i = 2; i*i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}
int main() {
    int n;
    cin >> n;
    while(true){
	++n;
        if(is_prime(n)){
            cout << n << '\n';
            exit(0);
        }
    }
    return 0;
}