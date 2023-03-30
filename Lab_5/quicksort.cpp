
#include <iostream>
using namespace std;
#include <string>
#include <climits>
#include <cstdlib>
#include <sys/time.h>
//recursive quicksort
void quicksort(int A[] , int f , int l) {

    int i = f-1;
    int j = f;
    int pivot = l;

    if (f>=l){
        return; //if the length of the array is 1.its already sorted
    }
    while (j <= pivot){
        if(A[j] <= A[pivot]){
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        j++;
    }
    //divide and conquer
    quicksort(A ,f , i-1); 
    quicksort(A, i+1, l);
    
}





//iterative quicksort
void quicksort_it(int arr[], int f , int l) {
    int len = l- f+1; 
    int track[len];

    int top = -1;

    //building a stack
    track[++top] = 0;   
    track[++top] = len - 1;

    
    while (top >= 0) {
        
        int end = track[top--];
        int start = track[top--];
        //we take pivot to be the last element
        int pivot = arr[end];
        int i = start - 1;
        int j =start;
        int tmp;
        for (int j = start; j <end ; j++){
        
            if (arr[j] < pivot) {
                tmp = arr[++i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            
        }// swapping the pivot and the ith element
        tmp = arr[++i];
        arr[i] = pivot;
        arr[end] = tmp;

        

        if (i - 1 > start) {
            track[++top] = start;
            track[++top] = i - 1;
        }

        if (i + 1 < end) {
            track[++top] = i + 1;
            track[++top] = end;
        }

    }

}




 int main(){
        

        int size = 10000; //setting the length of the array
    
    

    
        cout << "         "<<size << endl;
        int arr1[size]; // this array is for a revearsly sorted array for the worst case
            
        for(int i = 0; i < size;i++){
            arr1[i] = size - i;
        }




        int arr_ran [size]; // array with random values for the avarage case
        for( int i = 0; i < size; i++ ){
            arr_ran[i] = rand();
        }

        
        int arr_c[size];  // this array is a copy array of the worst case array.

        for (int copy = 0 ;copy < size;copy++ ){
            arr_c[copy] = arr1[copy];
        }

        
        cout << "recursive - " << endl;
        struct timeval start,end;
        gettimeofday(&start,NULL);
        ios_base::sync_with_stdio(false);

        quicksort(arr1, 0,size-1);    // calling recursive algorithm
        

        gettimeofday(&end,NULL);
        cout << "Time to run is - " << (end.tv_sec-start.tv_sec)*1000000  + (end.tv_usec-start.tv_usec) << endl;
        cout << endl;
        cout << "iterative"<< endl;

        gettimeofday(&start,NULL);
        ios_base::sync_with_stdio(false);

        quicksort_it(arr_c,0,size-1);  // calling the iterative algorithm

        gettimeofday(&end,NULL);
        cout << "Time to run is - " << (end.tv_sec-start.tv_sec)*1000000  + (end.tv_usec-start.tv_usec) << endl;  

        // for(int i : a){
        //     cout << i ;
        // }cout << endl;
        cout << endl;
        
    


 }

