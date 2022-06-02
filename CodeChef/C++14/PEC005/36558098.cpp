#include<bits/stdc++.h>
using namespace std;

int lis(int arr[], int n){
    int lis[n];
    lis[0] = 1;
    for (int i=1; i<n; i++){
        lis[i] = 1;
        for (int j=0;j<i; j++){
            if (arr[i] >= arr[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] +1;
            }
        }
    }
    int mx = 1;
  	for(auto i : lis) mx = max(mx, i);
    return mx;
}

int main(){
    int T; cin >> T;
    for (int i=0; i<T; i++){
        int N; cin >> N;
        int A[N];
        for (int i=0; i<N; i++){
            cin >> A[i] ;
        }
        cout << lis(A,N) << "\n";
    }
    return 0;
}
