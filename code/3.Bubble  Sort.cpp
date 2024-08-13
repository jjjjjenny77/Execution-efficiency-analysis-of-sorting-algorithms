//Caculate the executing time of sorting in Bubble sort method
#include<iostream> // enables program to perform input and output
#include<ctime> // enables program to perform clock()
#include<cstdlib> // enables program to perform rand()
#include<iomanip> // program uses names from the std namespace
using namespace std;

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
	clock_t clicks = clock(); // set the time value into clicks;
	// let the function run 5, 10, 15...100 times
	for(int i = 5; i <= 100; i+=5)
	{
		cout << "n = " << i << endl;
		for(int j = 1; j <= i; j++)
		{
			int a = rand(), b = rand(), c = rand(), d = rand(), e = rand(); // to make the elements in the array be random
			int array[5] = {a, b, c, d, e}; // declare an array
			cout << "Before: ";
			// print the original array
			for(int k = 0; k < 5; k++)
			{
				cout << array[k] << " ";
			}
			cout << "\t";
			BubbleSort(array, 5); // call the function
			cout << " After: ";	
			// print the sorted array
			for(int k = 0; k < 5; k++)
			{
				cout << array[k] << " ";
			}
			cout << endl;
		}
		clicks = clock() - clicks; // the end time minus start time equal to the execution time;
		cout << "The sorting time: " << (float)clicks / CLOCKS_PER_SEC << endl; // output the sorting time in second
		cout << "----------------------------------" << endl;
	}
	return 0;
} // End function main
