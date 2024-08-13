//Caculate the executing time of sorting in Bubble sort method with different n
#include<iostream> // enables program to perform input and output
#include<ctime> // enables program to perform clock()
#include<cstdlib> // enables program to perform rand()
#include<iomanip> // enables program to perform setw()
using namespace std; // program uses names from the std namespace

const int num[15] = {5, 8, 10, 12, 15, 18, 20, 22, 25, 28, 30, 35, 40, 45, 50}; // declare a constant integer array to be the executing time

// function BubbleSort is main to perform the Bubble sort 
void BubbleSort(int *arr, int size)
{
	for(int i = 0; i < (size - 1); i++)
	{
		for(int j = i; j < (size - i - 1); j++)
		{
			// compare if the arr[j] is bigger than the latter one
			if(arr[j] > arr[j + 1])
			{
				int tmp = arr[j + 1]; // declare a temporary variable to store the value of arr[j + 1]
				arr[j + 1] = arr[j];
				arr[j] = tmp; // swap
			} 
		}
	}
}

// function main begins program execution 
int main()
{	
	srand(7); // set a fixed value as random number seed
	int array[50] = {}; // declare an array
	// to make the elements in the array be random
	for(int i = 0; i < 50; i++)
	{
		array[i] = rand();
	}
	// let the function run num[0], numm[1]...num[14] times
	for(int i = 0; i < 15; i++)
	{
		int n = num[i];
		clock_t clicks = clock(); // set the time value into clicks;
		cout << "n = " << n << endl << "Before: ";
		// print the original array
		for(int j = 0; j < n; j++)
		{
			cout << array[j] << " ";
		}
		cout << endl;
		BubbleSort(array, n); // call the function
		cout << "After: ";
		// print the sorted array
		for(int j = 0; j < n; j++)
		{
			cout << array[j] << " ";	
		}
		cout << endl;
		clicks = clock() - clicks; // the end time minus start time equal to the execution time;
		cout << "The sorting time: " << (float)clicks / CLOCKS_PER_SEC << endl; // output the sorting time in second
		cout << "----------------------------------" << endl;
	}
	return 0;
} // End function main
