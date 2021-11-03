#include <iostream>
using namespace std;

bool findNum(int arr[], int n, int data) {
	int start = 0;
	int end = n - 1;
	int mid;

	while (end-start>=0) {
		mid = (start + end) / 2;

		if (arr[mid] == data)
			return true;
		else if (arr[mid] > data)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return false;
}

int swap(const void *a, const void*b) {
	return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main() {
	int n, m, arr[100000], num;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	qsort(arr, n, sizeof(int), swap);

	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> num;
		cout<<findNum(arr, n, num)<<endl;
	}

	return 0;
}