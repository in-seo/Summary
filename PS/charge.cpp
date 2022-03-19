#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N,M,K,sum=0;
    int cnt = 0;
    cin >> N >> M >> K;
    int *arr = new int[N];

    for (int i = 0; i < N; i++)
    {
        int l;
        cin >> l;
        arr[i] = l;
    }
    sort(arr, arr+N);
    int a = arr[N - 1];
    int b = arr[N - 2];
    // 8번 더하는데  최대 3번까지 가능.
    
    cnt = M / (K + 1); //몫 2 나머지 3

    sum = (a * K + b) * cnt + (M % (K + 1))*a;

    
       
    cout << sum << endl;
    
    
}

