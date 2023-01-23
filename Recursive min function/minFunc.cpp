#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
	//base case
	if (arrSize == 0) { return &arr[0]; }

	//Recursive case
	else {
		const int *leftMin = min(arr, arrSize - 1);										//Make call to min on lower indices
		return &(*leftMin < arr[arrSize - 1] ? *leftMin : arr[arrSize - 1]);			//Conditional operator used to return smallest values of current end indice
	}																					//or indicie of smallest value in lower indices.
}