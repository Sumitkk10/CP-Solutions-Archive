#include <iostream>
using namespace std;

void solve(){
    long long x;
    cin >> x;
    long long low = 0, ok, high = 1e6;
    while(low <= high){
        long long mid = (high + low) / 2;
        long long ans = (mid * (mid + 1) * (2*mid + 1)) / 6;
        if(ans <= x){
            ok = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ok << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
	return 0;
}
