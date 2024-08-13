//Caculate the executing time of sorting in Quick sort method with different n
#include<iostream> // enables program to perform input and output
#include<ctime> // enables program to perform clock()
#include<cstdlib> // enables program to perform rand()
#include<iomanip> // enables program to perform setw()
using namespace std; // program uses names from the std namespace

const int num[15] = {5, 8, 10, 12, 15, 18, 20, 22, 25, 28, 30, 35, 40, 45, 50}; // declare a constant integer array to be the executing time

// function swap is main to perform the value exchange between two variable 
void swap(int *a, int *b)
{
    int tmp = *a; // declare a temporary variable to store the value of *a
    *a = *b;
    *b = tmp;
}

// function Partition is main to search the position of pivot 
int Partition(int *arr, int start, int end)
{
	int pivot = arr[end]; // declare arr[end] as the pivot temporarily
	int i = start - 1;
	for(int j = start; j < end; j++)
	{
		if(arr[j] < pivot)
		{
			i++; // if arr[j] is lower than pivot, the location of pivot move one to the right
			swap(&arr[j], &arr[i]);
		}
	}
	i++;
	swap(&arr[end], &arr[i]); // put the pivot to the position of i
	return i; // return the value of i
}

// function QuickSort is main to perform the Quick sort 
void QuickSort(int *arr, int start, int end)
{
	// recurring until start = end
	if(start < end)
	{
		int pivot = Partition(arr, start, end);
		QuickSort(arr, start, (pivot - 1));
		QuickSort(arr, (pivot + 1), end);
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
		QuickSort(array, 0, 4); // call the function
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
