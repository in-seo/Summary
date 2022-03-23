#include<bits/stdc++.h>
using namespace std;

int arr[20] = { 7,5,9,0,3,1,6,2,4,8 ,10, 12, 14, 15, 13, 11, 19, 16, 18, 17 };


void quicksort(int *arr, int start, int end) {
	if (start >= end) return;
	int pivot = start;
	int l = start + 1;
	int r = end;
	while (l <= r) {
		while (arr[l] < arr[pivot]) { l++; }
		while (arr[r] > arr[pivot]) { r--; }
		if (l < r) swap(arr[l], arr[r]);
		else { swap(arr[pivot], arr[r]); }
	}
	quicksort(arr, start, r-1);
	quicksort(arr, r + 1, end);
}


int main() {
	quicksort(arr,0, 19);
	for (int i = 0; i < 19; i++)
	{
		cout << arr[i] << " ";
	}
}