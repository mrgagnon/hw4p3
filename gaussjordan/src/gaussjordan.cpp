/* Maylee Gagnon
 * CS 2223 HW4P3 Gauss-Jordan
 * 11.23.2019
 */
#include <iostream>
#include <cmath>
using namespace std;

#define n 3

/*Prints the given array
 */
void printArr (int A[][n+1]){
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= n; j++){
			cout << A[i][j] << ", ";
		}
		cout << endl;
	}
}

/* Uses the betterFowardElimination algorithm from the textbook so solve the system of equations
 * @param A
 * @param b
 * @return

 */
/*
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
			float temp = (float)A[j][i] / (float)A[i][i];
			cout << temp << endl;
			for (int k = i; k < n+1; k++){
				A[j][k] = A[j][k] - (A[i][k]*temp);
			}
		}
	}

	return 0;
}*/

/* Modifies the betterforward algorithm to follow the gaussJordan algorithm
 * @param A
 * @param b
 * @return
 */
int gaussJordanAlg(int A[][n+1], int b[n]){
	for (int i = 0; i < n; i++){
		A[i][n] = b[i]; // appends b to A as the last col
	}

	for (int i = 0; i < n; i++){ //TODO n-1?
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

		printArr(A);
		cout << endl;

		// GJ modification, each pivot row is divided by leading entry prior to use as pivot row, producing an identity matrix
		float leadingEntry = A[i][i];
		for (int x = i; x < n+1; x++) {
			A[i][x] = A[i][x] / leadingEntry;
		}

		for (int j = 0; j < n; j++){ //zeroing/updating values
			if (i!=j){
				float temp = (float)A[j][i] / (float)A[i][i];
				for (int k = 0; k < n+1; k++){
					A[j][k] = A[j][k] - (A[i][k]*temp);
				}
			}
		}
		printArr(A);
		cout << endl;
	}
	return 0;
}


int main() {


	int arrHW[8][9] = {{1, 1, 1, 1, 1, 1, 1, 1, 0},
					  {1, 2, 1, 1, 1, 1, 2, 1, 0},
					  {1, 1, 3, 1, 1, 3, 1, 1, 0},
					  {1, 1, 1, 4, 4, 1, 1, 1, 0},
					  {11, 1, 1, 1, 1, 1, 1, 1, 0},
					  {1, 1, 1, 1, -1, -1, -1, -1, 0},
					  {1, 2, 3, 4, 5, 6, 7, 8, 0},
					  {1, -1, 1, -1, 1, -1, 1, -1, 0}};
	int bHW[8] = {0, 0, 0, 0, 20, 34, -51, -6};
	cout << "gaussJordan. Original array" << endl;
	printArr(arrHW);
	cout << endl;

	gaussJordanAlg(arrHW, bHW);

	cout << "array after" << endl;
	printArr(arrHW);
	cout << endl;


	/*
	int arrEx[3][4] = {{2, -1, 1, 0},
			{4, 1, -1, 0},
			{1, 1, 1, 0}};
	int bEx[3] = {1, 5, 0};

	cout << "original array" << endl;
	printArr(arrEx);
	cout << endl;

	betterForwardElimin(arrEx, bEx);

	cout << "array after" << endl;
	printArr(arrEx);
	 */

/*
	int arrExGJ[3][4] = {{2, -1, 1, 0},
			{4, 1, -1, 0},
			{1, 1, 1, 0}};
	int bExGJ[3] = {1, 5, 0};
	cout << "gaussJordan. Original array" << endl;
	printArr(arrExGJ);
	cout << endl;

	gaussJordanAlg(arrExGJ, bExGJ);

	cout << "array after" << endl;
	printArr(arrExGJ);
	cout << endl;
*/
	return 0;
}
