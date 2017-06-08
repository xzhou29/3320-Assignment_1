
#include <iostream>
#include <time.h>
#include <algorithm>

#define M 630
using namespace std;
int main() {
	clock_t begin1, stop1, begin2, stop2, begin3, stop3;
	double tdif = 0, tdif2 = 0, tdif3 = 0;
	int *array1[3 * M], *array2[M], i, j;
	double dif, dif2, dif3;

	begin1 = clock();
	cout << " Step 1: Allocating memory for first sequence of 3M arrays of size 800,000 elements each..." << endl;
	for (i = 0; i < 3 * M; i++)
		array1[i] = (int*)malloc(800000 * sizeof(int));
	for (i = 0; i < 3 * M; i++)
	{
		for (j = 0; j < 800000; j++)
			array1[i][j] = j;//allocating 1st arrays
	}
	stop1 = clock();

	begin2 = clock();
	cout << "Step 2: Deallocating all even-numbered arrays of first squences of 3M arrays..." << endl;
	// delete even number array in array1
	for (i = 0; i < 3 * M; i += 2) {
		delete(array1[i]);
	}
	stop2 = clock();

	begin3 = clock();
	cout << " Step 3: Allocaintg a squence of M arrays of size 1,200,000 elements each..." << endl;
	for (i = 0; i < M; i++)
		array2[i] = (int*)malloc(1200000 * sizeof(int));
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < 1200000; j++)
			array2[i][j] = j;
	}
	stop3 = clock();
	dif = (stop1 - begin1);
	dif2 = (stop2 - begin2);
	dif3 = (stop3 - begin3);
	cout << "Step 4: Deallocating all arrays ..." << endl;
	for (int i = 1; i < 3 * M; i += 2) {
		delete(array1[i]);
	}
	for (int i = 1; i < M; i++) {
		delete(array2[i]);
	}
	cout << "Allocating memory for first sequence of 3M arrays needs: " <<dif << " ms" << endl;
	cout << "Deallocating all even-numbered arrays needs: " << dif2 << " ms" << endl;
	cout << "Allocaintg a squence of M arrays needs: " << dif3 << " ms" << endl;
	system("pause");
	return 0;
}
