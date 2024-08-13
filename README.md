# Execution-efficiency-analysis-of-sorting-algorithms
> This note record and share the final report of Programming course in 【110下】 about analysing some sorting algorithms' efficiency
## Requirements:
Insertion Sort  
Selection Sort  
Bubble Sort  
Quick Sort (Recursion version)  
* Please study these four implementation methods and write one or four or more programs to test the four implementation methods.
* Please compare the execution efficiency(time) according to the test results and write a test report.
  
**1. The source or method of generating the test data.**

**2. The number of test data elements (array size) is represented by n below.**

Taking n==5 as an example, {1, 2, 3, 4, 5} and {5, 4, 3, 2, 1} and {3, 2, 5, 1, 4} are the same because the original test data The arrangement is different, the execution time will be different! Therefore, the test data with the same array size n cannot only test one or two strokes. It is necessary to test the possible (random) original arrangement of many strokes, and then calculate the average execution time of the sorting. For example (just an example, please design it yourself), n = 5, 60 test data are randomly generated; n = 10, 1814,400 test data are randomly generated.

**3. Based on the fairness of the comparison, how to ensure that different methods use the same test data.**

Note: The sorted data cannot be used by other methods or by yourself. (refer to the 
previous point)

E.g:

⋯ // Generate test data array[arraySize]

sortA(array, arraySize); // After execution, the array is sorted, the next method

sortB(array, arraySize); // The test data is regarded as different, this is not acceptable

⋯⋯

**4. Some research reports have shown that the execution time of the above four methods have advantages and disadvantages for different n values. No one is absolutely the best. Please explain it according to the test results (there is no 100% standard answer).**

Suggestions (just suggestions, please design your own) n = 5, 8, 10, 12, 15, 18, 20, 22, 25, 28, 30, 35, 40, 45, 50

Note 1: The following wording is redundant on the subject of this research and wastes time to get the same result. And it doesn't make sense to test n == 1 vs 2.

for(n = 1; n < 51; n++) {}

NOTE 2 The values of n listed above can be generated using the following fragments.

const int num[15] = {5, 8, 10, 12, 15, 18, 20, 22, 25, 28, 30, 35, 40, 45, 50};

⋯⋯

for(int i = 0; i < 15; i++)

{

 n = num[i];
 
⋯⋯

}

**5. How to avoid the situation of positive value + positive value = negative value when the program is executed.**

In order to find the average, it will be accumulated first and then averaged. When accumulating, pay attention to the problem of "positive number + positive number = negative number". Remember the last assignment? 1134903170 + 1836311903 - 1 = -1323752224. If the number of tests is large and the n value is large, the accumulated value may change as follows:

positive, positive,… , negative, negative, ... , positive, positive,...,...The first question, the result is incorrect.
The second question, if the final accumulated value is negative, can the test report tell you that the execution time is negative? Will be a joke.
So, it may be necessary to strike a balance between the accuracy (accumulated value) and the tested time value.
(When the accumulated value becomes negative, break?).

**6. For the same n value, in addition to taking the average execution time of the number of test times, the maximum and minimum values can also be calculated.**

**7. In addition to the execution time, the execution efficiency can also be used to demarcate the execution times of key operations.**

In addition to the execution time, the execution efficiency can also be demarcated the execution times of the key operations. In this research topic, the key operations can be demarcated as the ratio of two numbers ">" or "<". The test program can count the number of "compares" performed.

**8. Following 6 and 7, if there are enough test times, the maximum, average and minimum 
execution times of the "comparison" of the four methods will be related to 𝑛<sup>2</sup>, 𝑛 𝑙𝑜𝑔 𝑛**
## Outcomes
You can see the program for four sorting methods in the folder name code, and don't forget to download my test report to see the analyze result!
