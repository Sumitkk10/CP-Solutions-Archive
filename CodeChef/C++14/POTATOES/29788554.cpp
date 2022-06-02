#include <iostream>
using namespace std;

bool isPrime(int num){
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}

int main() {
	long long int t;
	cin >> t;
    while(t--){
        long long int n, m, i, z;
        cin >> n >> m;
        long long int ans = n + m + 1;
        for(i = ans; i <= 2100; i++){
            z = isPrime(i);
            if(z==true){
                cout << i - (ans-1) << '\n';
                break;
            }
        }
    }
	return 0;
}
