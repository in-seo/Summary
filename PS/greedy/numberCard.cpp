#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, m;
	int val = 0;
	cin >> n >> m;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		int min = 10000;
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			if (temp < min)
				min = temp;
		}
		if (val < min)
			val = min;
	}
	cout << val << endl;

}