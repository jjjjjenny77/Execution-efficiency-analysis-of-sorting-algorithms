//Caculate the total and average executing time of sorting in Insertion sort method with fixed n
#include<iostream> // enables program to perform input and output
#include<algorithm> // enables program to perform random_shuffle
#include<ctime> // enables program to perform clock()
using namespace std;

// function InsertionSort is main to perform the Insertion sort 
void InsertionSort(int *arr, int size)
{
	for(int i = 1; i < size; i++)
	{
		int tmp = arr[i]; // declare a temporary variable to store the value of arr[i]
		int j = i - 1;
		//compare if the key element is lower than the former one
		while(tmp < arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp; // swap
	}
}

// function main begins program execution 
int main(){
	int array[5] = {1, 2, 3, 4, 5}; // declare an array
	int rec[60][5]; // record: record all the arrays that we have produced
	for(int i = 0; i < 60; i++){
		// while loop for producing an absolutely new array
		while(1)
		{ 
			bool alr = 0; // bool value to check if the array is already exist
			random_shuffle(array, array + 5); // shuffle until a new array is produced
			for(int j = 0; j < i; j++)
			{
				int samenum=0;
				for(int k = 0; k < 5; k++)
				{
					// comparing
					if(rec[j][k] == array[k])
					{ 
						samenum++;
					}
				}
				// if samenum==5, then the two array is totally same, so shuffle again
				if(samenum == 5)
				{
					alr = 1;
					break;
				}
			}
			 // if alr == 0, it means that we get an absolutely new array, so put it into rec
			if(!alr)
			{
				for(int j = 0; j < 5; j++)
				{
					rec[i][j] = array[j];
				}
				break;
			}
		}
	}
	
	cout << "Before" << "\t" << "After" << endl;
	clock_t clicks = clock(); // set the time value into clicks;
	// let the function run 60 times
	for(int i = 0; i < 60; i++)
	{
		// print the original array
		for (int j = 0; j < 5; j++)
  		{
  			array[j]=rec[i][j];
		  	cout << array[j];
		}
		cout << "\t";
		InsertionSort(array, 5); // call the function
		// print the sorted array
		for (int j = 0; j < 5; j++)
  		{
		  	cout << array[j];
		}
		cout << endl;
	}
	clicks = clock() - clicks; // the end time minus start time equal to the execution time;
	cout << "The total sorting time: " << (float)clicks / CLOCKS_PER_SEC << endl;// output the total sorting time in second
	cout << "The average sorting time: " << ((float)clicks / CLOCKS_PER_SEC) / 60 << endl;// output the average sorting time in second
	return 0;
} // End function main
