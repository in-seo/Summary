#include<bits/stdc++.h>
using namespace std;

void swap(int  * a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int arr[10] = { 7,5,9,0,3,1,6,2,4,8 };
	for (int i = 1; i <= 10; i++)
	{
		for (int j = i - 1; j > 0; j--)
		{
			if (arr[j] < arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
			}
			else
				break;
		}
		cout << i << "¹ø¤Š  ";
		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
}