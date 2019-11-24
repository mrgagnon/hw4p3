/* Maylee Gagnon
 * CS 2223 HW4P3 Gauss-Jordan
 * 11.23.2019
 */
#include <iostream>
#include <cmath>
using namespace std;

#define n 8

/*Prints the given array
 * @param A the array to be printed
 */
void printArr (double A[][n+1]){
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= n; j++){
			cout << A[i][j] << ", ";
		}
		cout << endl;
	}
}

/* Uses the betterFowardElimination algorithm from the textbook so solve the system of equations
 * @param A The square matrix of made up of co-efficients with an additional column on the end
 * @param b An array with the results of the equations, will be augmented to array A
 */
void betterForwardElimin(int A[][4], int b[3]){
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
}

/* Modifies the betterforward algorithm to follow the gaussJordan algorithm
 * @param A The square matrix of made up of co-efficients with an additional column on the end
 * @param b An array with the results of the equations, will be augmented to array A
 */
void gaussJordanAlg(double A[][n+1], double b[n]){
	for (int i = 0; i < n; i++){
		A[i][n] = b[i]; // appends b to A as the last col
	}

	for (int i = 0; i < n; i++){
		int pivotrow = i;

		for (int j = i+1; j < n; j++){ //finding max row
			if (abs(A[j][i]) > abs(A[pivotrow][i])){
				pivotrow = j;
			}
		}

		for (int k = i; k < n+1; k++){ // swapping rows
			double tempEntry = A[i][k];
			A[i][k] = A[pivotrow][k];
			A[pivotrow][k] = tempEntry;
		}

		double leadingEntry = A[i][i]; //GJ modification, pivot row/leading entry prior to use -> identity matrix
		for (int x = i; x < n+1; x++) {
			A[i][x] = A[i][x] / leadingEntry;
		}

		for (int j = 0; j < n; j++){ //zeroing/updating values, GJ upper & lower
			if (i!=j){
				double temp = (double)A[j][i] / (double)A[i][i];
				for (int k = 0; k < n+1; k++){
					A[j][k] = A[j][k] - (A[i][k]*temp);
				}
			}
		}
	}
}

/* Sets up arrays and call gaussJordan method
 */
int main() {
	double arrHW[8][9] = {{1, 1, 1, 1, 1, 1, 1, 1, 0},
					  {1, 2, 1, 1, 1, 1, 2, 1, 0},
					  {1, 1, 3, 1, 1, 3, 1, 1, 0},
					  {1, 1, 1, 4, 4, 1, 1, 1, 0},
					  {11, 1, 1, 1, 1, 1, 1, 1, 0},
					  {1, 1, 1, 1, -1, -1, -1, -1, 0},
					  {1, 2, 3, 4, 5, 6, 7, 8, 0},
					  {1, -1, 1, -1, 1, -1, 1, -1, 0}};
	double bHW[8] = {0, 0, 0, 0, 20, 34, -51, -6};
	cout << "Gauss-Jordan. Original array" << endl;
	printArr(arrHW);
	cout << endl;

	gaussJordanAlg(arrHW, bHW);

	cout << "Resulting array" << endl;
	printArr(arrHW);


	//Arrays used for testing
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
	double arrExGJ[3][4] = {{2, -1, 1, 0},
			{4, 1, -1, 0},
			{1, 1, 1, 0}};
	double bExGJ[3] = {1, 5, 0};
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
