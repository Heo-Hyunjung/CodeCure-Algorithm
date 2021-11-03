#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int lower_binary(int* arr, int data, int n) {
    int start = 0;
    int end = n - 1;
    int mid;

    while (end > start) {
        mid = (start + end) / 2;
        if (arr[mid] >= data)
            end = mid;
        else start = mid + 1;
    }
    return end;
}

int upper_binary(int* arr, int data, int n) {
    int start = 0;
    int end = n - 1;
    int mid;

    while (end > start) {
        mid = (start + end) / 2;
        if (arr[mid] > data)
            end = mid;
        else start = mid + 1;
    }
    return end;
}

int main(void) {
    int n, m, temp, target, lower, upper;

    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    cin >> m;
    int* marr = new int[m];
    int* result = new int[m];
    for (int i = 0; i < m; i++) {
        cin >> marr[i];
        result[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        lower = lower_binary(arr, marr[i], n);
        upper = upper_binary(arr, marr[i], n);
        if (upper == n - 1 && arr[n - 1] == marr[i])
            upper++;
        result[i] = upper - lower;
    }

    for (int i = 0; i < m; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}