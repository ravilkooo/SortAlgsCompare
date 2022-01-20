#include "Sort.h"

void bubbleSort(int* arr, int len)
{
	int inv = 1;
	for (int i = 0; (i < len - 1) && inv; i++) {
		inv = 0;
		for (int j = i; j < len - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int m = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = m;
				inv++;
			}
		}
	}
}

void merge(int* arr, int left, int right)
{
	int* tmp = (int*) malloc(sizeof(int) * (right - left));
	int mid = (left + right) / 2, h1 = left, h2 = mid;
	for (int i = 0; i < right - left; i++) {
		tmp[i] = arr[i + left];
	}
	while (h1 < mid || h2 < right) {
		if ((h2 == right) || ((h1 < mid) && (tmp[h1 - left] < tmp[h2 - left]))) {
			arr[h1 + h2 - mid] = tmp[h1 - left];
			h1++;
		}
		else {
			arr[h1 + h2 - mid] = tmp[h2 - left];
			h2++;
		}
	}
	free(tmp);
}

void mergeSort(int* arr, int left, int right) {
	if (right - left < 2) {
		return;
	}
	int mid = (left + right) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid, right);
	merge(arr, left, right);
}

int binSearch(int* arr, int len, int num) {
	int ind;
	int b = 0, e = len - 1;
	int m = (b + e) / 2;
	while (b != e) {
		if (num <= arr[m]) {
			e = m;
		}
		else {
			b = m + 1;
		}
		m = (b + e) / 2;
	}
	if (num == arr[b]) {
		ind = b;
	}
	else {
		ind = -b;
	}
	return ind;
}

void binsertSort(int* arr, int len)
{
	int num;
	for (int i = 1; i < len; i++) {
		num = arr[i];
		int pl = binSearch(arr, i + 1, num);
		pl = pl > 0 ? pl : -pl;
		for (int j = i; j > pl; j--) {
			arr[j] = arr[j - 1];
		}
		arr[pl] = num;
	}
}

void shellSort(int* arr, int len)
{
	int step = len / 2, j;
	int s;
	while (step > 0) {
		for (int i = 0; i < len - step; i++) {
			j = i;
			while (j >= 0 && arr[j] > arr[j + step]) {
				s = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = s;
				j--;
			}

		}
		step = step / 2;
	}
}

int cmpInt(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}