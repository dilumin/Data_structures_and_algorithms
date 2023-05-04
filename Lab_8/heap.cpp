#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   //indexes of the left and right children of a node 
    int l = 2* root;
    int r = 2 * root + 1;

   
   // checking if childen nodes' values are bigger than roots' value. If so we switch and get the bigger value to the root
    int largest = root; 
    if (l <= n && arr[l-1] > arr[root-1] ){
        largest = l;
    }else{
        largest = root;
    }
    if (r <= n && arr[r-1] > arr[largest-1] ){
        largest = r;
    }

    if ( largest != root){
        int k = arr[root-1];
        arr[root-1] = arr[largest-1 ];
        arr[largest-1 ] = k;
        heapify(arr , n , largest); // then we recursively do the same thing this time pointing to switched childs node 

    }  

   // build heapify
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   
   // build heap
   // To build a max heap we heapify all nodes that have at least one child from bottom to top
   for (int i = n/2 ; i > 0 ; i-- ){
        heapify(arr , n,i );
    }
   
  
   // extracting elements from heap one by one
   
   for (int i = n; i > 1; i--  ){
        int k = arr[0];  // we switch the top roots value and last elements value of the array .then that element has come to its sorted place . 
        arr[0] = arr[i-1];
        arr[i-1] = k;
        //we remove last array element from the heap
        n --; 
        heapify(arr , n ,1) ; // then we heapify the new element in the top root to get the next biggest value of the heap
    }//we do this in a loop until all elements are sorted

   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()

{  cout << "Enter the size of the array: "<< endl;
   int size;
   cin >> size;
   cout <<"Input array"<<endl;
   int num;
   int heap_arr[size]{0};

   //Making the heap input array
   for (int k = 0 ; k <size ; k++){
      cin >> num;
      heap_arr[k] = num;
   }
   
  
   heapSort(heap_arr, size);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, size);
}