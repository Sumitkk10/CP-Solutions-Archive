#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 402;
ll cnt = 0;

void merge(int a[], int st, int mid, int en){
    //lft = st, mid
    //right = mid + 1, en
    int aa[en - st + 1];
    int i = st, j = mid + 1, k = 0;
    while(i <= mid && j <= en){
        if(a[i] <= a[j]){
            aa[k] = a[i];
            ++i;
        }
        else{
            aa[k] = a[j];
            ++j;
            cnt += mid-i+1;
        }
        ++k;
    }
    while(i <= mid){
        aa[k] = a[i];
        ++i;
        ++k;
    }
    while(j <= en){
        aa[k] = a[j];
        ++j;
        ++k;
    }
    k = 0;
    for(int i = st; i <= en; i++){
        a[i] = aa[k];
        ++k;
    }
    //cout << st << ' ' << en << ' ' << cnt << endl;
}

void mergeSort(int a[], int st, int en){
    if(st >= en) return;
    int mid = (st + en) / 2;
    mergeSort(a, st, mid);
    mergeSort(a, mid + 1, en);
    merge(a, st, mid, en);
}

int main(){
    fast;
    ll n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
    }
    mergeSort(a, 0, n - 1);
    cout << cnt;
    return 0;
}