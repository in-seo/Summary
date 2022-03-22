#include<bits/stdc++.h>
using namespace std;
int arr[10] = { 5,7,9,0,3,1,6,2,4,8 };


void quicksort(int * arr, int start, int end) {
	if (start >= end) return;
	int pivot = start;
	int left = start + 1;
	int right = end;
	while (left <= right) {

		while (left <= end && (arr[left] <= arr[pivot])) {
			left++;
		}
		while (right > start && (arr[right] >= arr[pivot])) {
			right--;
		}
		cout << arr[left] << " " << arr[right] <<'\n';
		if (left < right) swap(arr[left], arr[right]);
		else swap(arr[pivot], arr[right]);
	}
	/*if (left >= right) {
		swap(arr[pivot], arr[right]);
	}*/
	quicksort(arr,start, right-1);
	quicksort(arr,right+1, end);
}



int main() {
	quicksort(arr,0, 9);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
}