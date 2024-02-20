//===============================
// inversions.cpp
// Count the total number of inversion using devide and concour method and for loop
// Name: EunHo Lee, Ashwin Krishnamurthy
// Date: 1 Feb 2024
//===============================
#include <ctime>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
//=============================================================
// Funtion Declaration
int InversionMerge(int arr[], int size);
int Merge(int arr[], int p, int q, int r);
int MergeSort(int arr[], int p, int r);
int InversionForLoop(int arr[], int size);
void RunTestCases(int);
void CheckInversion(int arr[], int size, int index, int ans);
void PrintArray(int arr[], int size);
//=============================================================
// struct for test cases with array, size of the array, and the correct answer
typedef struct TestCase
{
    vector<int> arr;
    int size;
    int ans; // expected number of inversion
} TestCase;
// Creating test cases manually just in case of tricky one
vector<TestCase> test_cases = {
    // empty array
    {{}, 0, 0},
    // array with one element
    {{1}, 1, 0},
    // all elements equal
    {{8, 8, 8, 8, 8, 8, 8}, 7, 0},
    // sorted array, no inversions
    {{1, 2, 3, 4, 5}, 5, 0},
    // sorted in reverse order, maximum number of inversions
    {{5, 4, 3, 2, 1}, 5, 10},
    // additional tests
    {{3, 2, 1}, 3, 3},
    {{9, 12, 5, 18, 3, 15, 7, 20, 10}, 9, 15},
    {{22, 23, 4}, 3, 2},

    {{8289, 9588, 137, 1175, 7751, 8550, 1516, 9951, 4013, 3464}, 10, 22},
    {{2, 2, 2, 2, 2}, 5, 0},
    {{7, 3, 5, 1, 4, 2, 6}, 7, 12},
    {{10, 20, 30, 40, 50}, 5, 0},
    {{2, 5, 8, 1, 3, 7, 6, 4}, 8, 12},
};
//==============================================
// main( int argc, char *argv [])
// main function that takes in argument (number of random element in the array)
// as a parameter and execute the inversion counting
// INPUT: int argc, char *argv []
// RETURN: int
//==============================================
int main(int argc, char *argv[])
{
    int n;
    if (argc > 1)
        n = atoi(argv[1]);
    else
    {
        n = 10;
    }
    srand(time(0));
    // exits if invalid number is entered
    if (n < 1 || n > 50000)
    {
        cout << "invalid input size" << endl;
        exit(0);
    }

    // initialize array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % 10000);
    }
    if (n <= 20)
    {
        PrintArray(arr, n);
    }

    InversionForLoop(arr, n);
    try
    {
        InversionMerge(arr, n);
    }
    catch (std::exception &e)
    {
        cout << "error : " << e.what() << endl;
    }
    // RunTestCases(50);
}
//==============================================
// InversionForLoop(int arr[], int size)
// InversionForLoop function that counts the number of inversion in the array
// using nested for loop => O(n^2) time complexity.
// INPUT: int arr[], int size
// RETURN: int
//==============================================
int InversionForLoop(int arr[], int size)
{
    // use given clock()
    std::clock_t start, stop;
    start = std::clock();

    int count_inv_total = 0;

    // goes through
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                count_inv_total += 1;
            }
        }
    }
    stop = std::clock();
    std::cout << "count1:" << std::setw(20) << count_inv_total << std::setw(20) << (stop - start) / (double)(CLOCKS_PER_SEC / 1000)
              << " ms" << std::endl;
    return count_inv_total;
}
//==============================================
// InversionMerge(int arr[], int size)
// InversionMerge function that counts the number of inversion in the array
// using devide and concour method => O(nlog(n)) time complexity.
// INPUT: int arr[], int size
// RETURN: int
//==============================================
int InversionMerge(int arr[], int size)
{
    std::clock_t start, stop;
    start = std::clock();
    int count_inv_total = 0;
    count_inv_total = MergeSort(arr, 0, size - 1);
    stop = std::clock();
    std::cout << "count2:" << std::setw(20) << count_inv_total << std::setw(20) << (stop - start) / (double)(CLOCKS_PER_SEC / 1000)
              << " ms" << std::endl;
    return count_inv_total;
}
//==============================================
// MergeSort(int arr[], int p, int r)
// Perform Merge Sorting and count the inversion
// INPUT: int arr[], int p, int r
// RETURN: int
//==============================================
int MergeSort(int arr[], int p, int r)
{
    if (p >= r)
        return 0;
    int count_inv_total = 0;
    try
    {
        int q = (p + r) / 2;

        // counts inversions with arrays
        count_inv_total += MergeSort(arr, p, q);
        count_inv_total += MergeSort(arr, q + 1, r);
        count_inv_total += Merge(arr, p, q, r);
    }
    catch (std::exception &e)
    {
        cout << "error : " << e.what() << endl;
    }

    return count_inv_total;
}
//==============================================
// Merge(int arr[], int p, int q, int r)
// Perform Merging and count the inversion
// INPUT: int arr[], int p, int q, int r
// RETURN: int
//==============================================
int Merge(int arr[], int p, int q, int r)
{
    int cnt_inversion = 0;
    try
    {

        // define useful variables
        int left_num = q - p + 1;
        int right_num = r - q;
        int prev_count = 0;

        // splits array in half
        int left_array[left_num];
        int right_array[right_num];
        for (int i = 0; i < left_num; i++)
        {
            left_array[i] = arr[p + i];
        }
        for (int i = 0; i < right_num; i++)
        {
            right_array[i] = arr[q + i + 1];
        }
        int i = 0, j = 0, k = p;

        // checks between the two arrays, counts the inversions
        while (i < left_num && j < right_num)
        {
            if (left_array[i] <= right_array[j])
            {
                arr[k] = left_array[i];
                i++;
                cnt_inversion += prev_count;
            }
            else
            {
                arr[k] = right_array[j];
                j++;
                prev_count++;
                cnt_inversion += 1;
            }
            k++;
        }
        // subtact overcounted inversion
        cnt_inversion -= prev_count;
        // checks inversions within own split arrays
        while (i < left_num)
        {
            arr[k] = left_array[i];
            i++;
            k++;
            cnt_inversion += right_num;
        }
        while (j < right_num)
        {
            arr[k] = right_array[j];
            j++;
            k++;
        }
    }
    catch (std::exception &e)
    {
        cout << "error : " << e.what() << endl;
        PrintArray(arr, r - p);
    }

    return cnt_inversion;
}
//==============================================
// RunTestCases(int num_cases)
// Test the InversionForLoop function and InversionMerge function that counts the number of inversion in the array
// INPUT: int arr[], int size
// RETURN: None
//==============================================
void RunTestCases(int num_cases)
{
    cout << endl;
    cout << "---------------------Start Test-------------------------\n"
         << endl;
    for (int i = 0; i < num_cases; i++)
    {
        // generate random array with random size <= 50000 but >0
        int n = rand() % 50001 + 1;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = (rand() % 10000);
        }
        CheckInversion(arr, n, i, -1);
    }

    cout << "---------------------- Custom test -------------------------" << endl;
    for (int i = 0; i < test_cases.size(); i++)
    {
        // get information from the current test case
        int size = test_cases[i].size;
        int ans = test_cases[i].ans;
        int arr[size];
        // copy the vector elements into array
        copy(test_cases[i].arr.begin(), test_cases[i].arr.end(), arr);
        CheckInversion(arr, size, i, ans);
    }
}
//==============================================
// CheckInversion(int arr[], int size, int index, int ans)
// Check the correctness of InversionForLoop function and InversionMerge function
// INPUT: int arr[], int size, int index, int ans
// RETURN: None
//==============================================
void CheckInversion(int arr[], int size, int index, int ans)
{
    cout << "_____________________"
         << "Test " << index << "______________________ " << endl;
    string check = "Fail";
    if (ans > 0)
    {
        if ((InversionForLoop(arr, size) == ans) && (InversionMerge(arr, size) == ans))
        {
            check = "Pass";
        }
    }
    else
    {
        if (InversionForLoop(arr, size) == InversionMerge(arr, size))
        {
            check = "Pass";
        }
    }

    cout << "Status"
         << " = " << check << endl;
    cout << "__________________________________________________" << endl;
    cout << endl;
    if (check == "Fail")
    {

        // if test fail, print the array
        if (size < 20)
        {
            PrintArray(arr, size);
        }
        exit(0);
    }
}
//==============================================
// PrintArray(int arr[], int size)
// Print the array
// INPUT: int arr[], int size
// RETURN: None
//==============================================
void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}