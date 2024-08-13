//Caculate the executing time of sorting in Selection sort method
#include<iostream> // enables program to perform input and output
#include<ctime> // enables program to perform clock()
#include<cstdlib> // enables program to perform rand()
using namespace std; // program uses names from the std namespace

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
			SelectionSort(array, 5); // call the function
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
