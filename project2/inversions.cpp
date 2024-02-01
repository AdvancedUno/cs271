//===============================
// inversions.cpp
// Count the total number of inversion using devide and concour method and for loop
// Name: EunHo Lee  
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
int InversionForLoop(int arr[], int size);
void RunTestCases(int);
void CheckInversion(int arr[], int size, int index, int ans);
void PrintArray(int arr[], int size);
//=============================================================

// struct for test cases with array, size of the array, and the correct answer
typedef struct TestCase{
    vector<int> arr;
    int size;
    int ans; // expected number of inversion
}TestCase;



// Creating test cases manually just in case of tricky one
vector<TestCase> test_cases = {
    {{1,2,3}, 3,0},
    {{22,23,4},3,0},
}; 


//==============================================
// main( int argc, char *argv [])
// main function that takes in argument (number of random element in the array) 
// as a parameter and execute the inversion counting 
// INPUT: int argc, char *argv []
// RETURN: int 
//==============================================
int main ( int argc, char *argv [])
{

    int n;
    if ( argc > 1 )
        n = atoi(argv[1]);
    else
        n = 10;
    
    // initialize array
    int arr[n];
    for(int i = 0; i < n; i ++){
        arr[i] =  (rand() % 10000);
    }


    InversionForLoop(arr, n);
    InversionMerge(arr, n);

    RunTestCases(10);

}


//==============================================
// InversionForLoop(int arr[], int size)
// InversionForLoop function that counts the number of inversion in the array
// using nested for loop => O(n^2) time complexity.
// INPUT: int arr[], int size
// RETURN: int
//==============================================
int InversionForLoop(int arr[], int size){
    std::clock_t start, stop;
    start = std::clock();
    
    int count_inv_total = 0;


    for(int i = 0; i < size; i ++){
        for(int j = i+1; j <size; j ++){
            if(arr[i] > arr[j]){
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
int InversionMerge(int arr[], int size){
    std::clock_t start, stop;
    start = std::clock();
    int count_inv_total = 0;






    stop = std::clock();
    std::cout << "count2:" << std::setw(20) << count_inv_total <<  std::setw(20) << (stop - start) / (double)(CLOCKS_PER_SEC / 1000)
    << " ms" << std::endl;
    return 0;
}

void Merge(int arr[], int size, int p, int q, int r){

    int left_num = q-p+1;
    int right_num = r-q;

    int left_array[left_num];
    int right_array[right_num];

    for(int i = 0; i < left_num; i ++){
        left_array[i] == arr[p+i];
    }

    for(int i = 0; i < right_num; i ++){
        right_array[i] == arr[q+i+1];
    }

    



}





//==============================================
// RunTestCases(int num_cases)
// Test the InversionForLoop function and InversionMerge function that counts the number of inversion in the array
// INPUT: int arr[], int size
// RETURN: None
//==============================================
void RunTestCases(int num_cases){
    for(int i = 0; i < num_cases; i ++){
        // generate random array with random size <= 50000 but >0
        int n = rand() % 50001 + 1;
        int arr[n];
        for(int i = 0; i < n; i ++){
            arr[i] =  (rand() % 10000);
        }
        CheckInversion(arr,n,i, -1);
    }

    for(int i = 0; i < test_cases.size(); i ++){
        // get information from the current test case
        int size = test_cases[i].size;
        int ans = test_cases[i].ans;
        int arr[size]; 

        // copy the vector elements into array
        copy(test_cases[i].arr.begin(),test_cases[i].arr.end(),arr); 

        CheckInversion(arr,size,i,ans);
    }
}


//==============================================
// CheckInversion(int arr[], int size, int index, int ans)
// Check the correctness of InversionForLoop function and InversionMerge function
// INPUT: int arr[], int size, int index, int ans
// RETURN: None
//==============================================
void CheckInversion(int arr[], int size, int index, int ans){

        cout << "_____________________" << "Test " << index << " ______________________ " << endl;
        string check = "Fail";
        if(ans> 0){
            if(InversionForLoop(arr, size)  == ans && InversionMerge(arr, size) == ans ){
                check = "Pass";
            }
        }else{
            if(InversionForLoop(arr, size) == InversionMerge(arr, size)){
                check = "Pass";
            }
        }
        
        cout << "Status" << " = " << check << endl;
        cout << "__________________________________________________" << endl;
        cout << endl;

        if(check == "Fail"){
            // if test fail, print the array
            if(size< 20){
                PrintArray(arr, size);
            }
        }
}


void PrintArray(int arr[], int size){

    for(int i = 0; i < size; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;

}


