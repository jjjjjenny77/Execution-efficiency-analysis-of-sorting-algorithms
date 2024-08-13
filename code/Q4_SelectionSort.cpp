//Caculate the executing time of sorting in Selection sort method with different n
#include<iostream> // enables program to perform input and output
#include<ctime> // enables program to perform clock()
#include<cstdlib> // enables program to perform rand()
#include<iomanip> // enables program to perform setw()
using namespace std; // program uses names from the std namespace

const int num[15] = {5, 8, 10, 12, 15, 18, 20, 22, 25, 28, 30, 35, 40, 45, 50}; // declare a constant integer array to be the executing time

// function SelectionSort is main to perform the Selection sort 
void SelectionSort(int *arr, int size)
{
	for(int i = 0; i < (size - 1); i++)
	{
		int min = i;
		// search the minimum value in array
		for(int j = i + 1; j < size; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		int tmp = arr[min]; // declare a temporary variable to store the value of arr[min]
		arr[min] = arr[i]; // put the minimum value to the array[i]
		arr[i] = tmp; // swap
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
		SelectionSort(array, n); // call the function
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
