#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, k, cnt = 0;
	cin >> n >> k;

	while (n > 1) {
		if (n % k == 0)
			n /= k;
		else
			n -= 1;
		
		cnt++;
	}
	cout << cnt << endl;


	


	

}