#include<iostream>
class Subnet {
public:
	void sorting(int arr[], int lenght);
	void ÝsSubnet(int arr1[], int arr2[], int x, int y);
}Sub;

void Subnet::sorting(int arr[], int lenght) {   // sorting algorthm
	int i, j;
	for (i = 0; i < lenght - 1; i++) {
		for (j = 0; j < lenght - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

		}
	}
}

void Subnet::ÝsSubnet(int arr1[], int arr2[], int x, int y) {  // the funciton for checking sub-array
	int counter = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (arr2[j] == arr1[i])
				counter++;
		}
	}
	if (counter == y)                           // If the number of matched letters are equal to the size of the sub-array then 
		std::cout << "array2 is the sub-array of array1" << std::endl; // array 2 is a subset array of array 1
	else
		std::cout << "array 2 is not an sub-array" << std::endl;
}



int main() {
	int size, size2;
	
	std::cout << "enter the size of the first array" << std::endl;
	std::cin >> size;
	std::cout << "enter the size of the second array" << std::endl;
	std::cin >> size2;

	int* arr1 = new int[size];  // we allocate a space for the arrays
	int* arr2 = new int[size2];

	std::cout << "enter values of the first array" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cin >> arr1[i];
	}
	std::cout << "enter values of the second array" << std::endl;
	for (int j = 0; j < size2; j++) {
		std::cin >> arr2[j];
	}

	if (size < size2) {  // we have check array sizes
		std::cout << "the second array has more elements than the first array" << std::endl;
		return 0;
	}
	else {   
		Sub.sorting(arr1, size);
		for (int k = 0; k < size; k++) {
			std::cout << arr1[k] << " ";
		}
		std::cout << std::endl;
		Sub.sorting(arr2, size2);
		for (int m = 0; m < size2; m++) {
			std::cout << arr2[m] << " ";
		}
		std::cout << std::endl;
		Sub.ÝsSubnet(arr1, arr2, size, size2);
	}
	return 0;
}