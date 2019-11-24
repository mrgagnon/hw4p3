/* Maylee Gagnon
 * CS 2223 HW4P3 Gauss-Jordan
 * 11.23.2019
 */
#include <iostream>
#include <cmath>
using namespace std;

int n = 3;

void printArr (int A[][4]){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			cout << A[i][j] << ", ";
		}
		cout << endl;
	}
}

int betterForwardElimin(int A[][4], int b[3]){
	for (int i = 0; i < n; i++){
		A[i][n] = b[i]; // appends b to A as the last col
	}

	for (int i = 0; i < n-1; i++){
		int pivotrow = i;

		for (int j = i+1; j < n; j++){ //finding max row
			if (abs(A[j][i]) > abs(A[pivotrow][i])){
				pivotrow = j;
			}
		}

		for (int k = i; k < n+1; k++){ // swapping rows
			int tempEntry = A[i][k];
			A[i][k] = A[pivotrow][k];
			A[pivotrow][k] = tempEntry;
		}

		for (int j = i+1; j < n; j++){ //zeroing/updating values
			cout << "in for loop" << endl;
			cout << "j,i " << A[j][i] << " i,i " << A[i][i] << endl;
			float temp = (float)A[j][i] / (float)A[i][i];
			cout << temp << endl;
			for (int k = i; k < n+1; k++){
				A[j][k] = A[j][k] - (A[i][k]*temp);
			}
		}
	}

	return 0;
}


int main() {
	cout << "Hello" << endl;

	/*
	int arr[8][9] = {{1, 1, 1, 1, 1, 1, 1, 1, 0},
					 {1, 2, 1, 1, 1, 1, 2, 1, 0},
					 {1, 1, 3, 1, 1, 3, 1, 1, 0},
					 {1, 1, 1, 4, 4, 1, 1, 1, 0},
					 {11, 1, 1, 1, 1, 1, 1, 1, 0},
					 {1, 1, 1, 1, 1, 1, 1, 1, 0},
					 {1, 2, 3, 4, 5, 6, 7, 8, 0},
					 {1, 1, 1, 1, 1, 1, 1, 1, 0}};
	int b[8] = {0, 0, 0, 0, 20, 34, 51, 6};
	*/
	int arrEx[3][4] = {{1, 1, 3, 0},
					   {2, -1, -1, 0},
					   {-3, 6, 5, 0}};
	int bEx[3] = {6, 11, -22};

	cout << "original array" << endl;
	printArr(arrEx);
	cout << endl;

	betterForwardElimin(arrEx, bEx);

	cout << "array after" << endl;
	printArr(arrEx);
	cout << "Hi" << endl;

	return 0;
}
