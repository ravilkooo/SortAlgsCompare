#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "ArrayIO.h"
#include "Sort.h"

int main111()
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(10);

	int n, m, S;
	int* barr;
	double c = 0;
	std::cin >> n >> m;
	std::ofstream Foap;
	Foap.open("Sort.txt", 'w');
	for (S = 1000; S <= 10000; S += 1000) {
		clock_t start;
		clock_t end;
		for (int i = 0; i < 10; i++) {
			barr = randArray(S, n, m);		
			printArray(barr, S);
			start = clock();
			//qsort(barr, S, sizeof(int), cmpInt);
			bubbleSort(barr, S);
			end = clock();
			printArray(barr, S);
			c = c + (double) (end - start);
		}
		Foap << c << ' ' << '\n';
		std::cout << c / CLOCKS_PER_SEC / 10 << ' ' << std::endl;
	}
	Foap.close();
	return 0;
}

int main() {
	std::cout.setf(std::ios::fixed);
	std::cout.precision(10);

	int min, max, len;
	double k = 1.5;
	int* arr;

	// bubb, bins, shell, merge, qsort / 1000, ... , 1000 * 1,5^9
	double rand_time[5][10]; 
	double ord_time[5][10];
	double rev_ord_time[5][10];

	std::cout << "Enter the range: ";
	std::cin >> min >> max;

	for (int alg = 0; alg < 5; alg++) {
		//	rand time
		switch (alg) {
			case 0: std::cout << "bubble_______" << std::endl; break;
			case 1: std::cout << "shell________" << std::endl; break;
			case 2: std::cout << "binsert______" << std::endl; break;
			case 3: std::cout << "merge________" << std::endl; break;
			case 4: std::cout << "qsort________" << std::endl; break;
		}
		len = 1000;
		std::cout << "_________rand" << std::endl;
		for (int i = 0; i < 10; i++) {
			clock_t start;
			clock_t end;
			rand_time[alg][i] = 0;
			for (int j = 0; j < 10; j++) {
				arr = randArray(len, min, max);
				//printArray(arr, len);
				switch (alg) {
					case 0: start = clock(); bubbleSort(arr, len); end = clock(); break;
					case 1: start = clock(); shellSort(arr, len); end = clock(); break;
					case 2: start = clock(); binsertSort(arr, len); end = clock(); break;
					case 3: start = clock(); mergeSort(arr, 0, len); end = clock(); break;
					case 4: start = clock(); qsort(arr, len, sizeof(int), cmpInt); end = clock(); break;
				}
				//printArray(arr, len);
				rand_time[alg][i] += (double)(end - start);
			}
			rand_time[alg][i] = rand_time[alg][i]  / CLOCKS_PER_SEC / 10;
			len *= 1.5;
		}
		//	ord time
		len = 1000;
		std::cout << "__________ord" << std::endl;
		for (int i = 0; i < 10; i++) {
			clock_t start;
			clock_t end;
			ord_time[alg][i] = 0;
			for (int j = 0; j < 10; j++) {
				arr = orderedArray(len);
				//printArray(arr, len);
				switch (alg) {
					case 0: start = clock(); bubbleSort(arr, len); end = clock(); break;
					case 1: start = clock(); shellSort(arr, len); end = clock(); break;
					case 2: start = clock(); binsertSort(arr, len); end = clock(); break;
					case 3: start = clock(); mergeSort(arr, 0, len); end = clock(); break;
					case 4: start = clock(); qsort(arr, len, sizeof(int), cmpInt); end = clock(); break;
				}
				//printArray(arr, len);
				ord_time[alg][i] += (double)(end - start);
			}
			ord_time[alg][i] = ord_time[alg][i] / CLOCKS_PER_SEC / 10;
			len *= 1.5;
		}
		//	rev_ord_time
		std::cout << "______rev_ord" << std::endl;
		len = 1000;
		for (int i = 0; i < 10; i++) {
			clock_t start;
			clock_t end;
			rev_ord_time[alg][i] = 0;
			for (int j = 0; j < 10; j++) {
				arr = revOrderedArray(len);
				//printArray(arr, len);
				switch (alg) {
					case 0: start = clock(); bubbleSort(arr, len); end = clock(); break;
					case 1: start = clock(); shellSort(arr, len); end = clock(); break;
					case 2: start = clock(); binsertSort(arr, len); end = clock(); break;
					case 3: start = clock(); mergeSort(arr, 0, len); end = clock(); break;
					case 4: start = clock(); qsort(arr, len, sizeof(int), cmpInt); end = clock(); break;
				}
				//printArray(arr, len);
				rev_ord_time[alg][i] += (double)(end - start);
			}
			rev_ord_time[alg][i] = rev_ord_time[alg][i] / CLOCKS_PER_SEC / 10;
			len *= 1.5;
		}
	}

	for (int alg = 0; alg < 5; alg++) {
		std::cout << "rand_time\tord_time\trev_ord_time" << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << rand_time[alg][i] << "\t" << ord_time[alg][i] << "\t" << rev_ord_time[alg][i] << std::endl;
		}
	}

	std::ofstream fout;
	fout.open("sort.csv", 'w');
	for (int alg = 0; alg < 5; alg++) {
		switch (alg) {
			case 0: fout << "bubbleSort\n"; break;
			case 1: fout << "shellSort\n"; break;
			case 2: fout << "binsertSort\n"; break;
			case 3: fout << "mergeSort\n"; break;
			case 4: fout << "qsort\n"; break;
		}
		fout << "len;random array;ordered array;reversed ordered array\n";
		len = 1000;
		for (int i = 0; i < 10; i++) {
			fout << len << ';' << rand_time[alg][i] << ';' << ord_time[alg][i] << ';' << rev_ord_time[alg][i] << "\n";
			len *= 1.5;
		}
	}
	fout.close();
}