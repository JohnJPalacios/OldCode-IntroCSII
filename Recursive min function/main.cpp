#include <iostream>

using namespace std;

#include "minFunc.h"

int main() {
	const int arrSize = 5;
	//cin >> arrSize;
	int arr[arrSize];
	for (int i = 0; i < arrSize; ++i) {
		cin >> arr[i];
	}
	const int *minLoc = min(arr, arrSize);
	cout << *minLoc << endl;

	return 0;
}