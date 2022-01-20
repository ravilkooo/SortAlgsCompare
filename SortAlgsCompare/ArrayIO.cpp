#include "ArrayIO.h"

int* randArray(int len, int min, int max) {
	int* arr = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % (max - min + 1) + min;
	}
	return arr;
}

int* orderedArray(int len) {
	int* arr = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; i++) {
		arr[i] = i + 1;
	}
	return arr;
}

int* revOrderedArray(int len) {
	int* arr = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; i++) {
		arr[i] = len - i;
	}
	return arr;
}

void printArray(const int* a, int len) {
	std::cout << a[0] << ", " << a[1] << ", " << a[2] << ", ... , " << a[len - 2] << ", " << a[len - 1] << std::endl;
}
