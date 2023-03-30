#include <iostream>
#include <vector>

using namespace std;



void sorting(int arr[], int el ,int m){
    int pos = m;
    while(pos > 0 && el < arr[pos-1] ){
        arr[pos] = arr[pos-1];
        pos--;
    }arr[pos] = el;


}


int main(){

    cout << "Enter length: "<< endl;
    int len =1;
    cin >> len;
    int arr[len];
    for(int m = 0 ;m < len ;m++){
        arr[m] =0;
    }

   
    cout << "Enter Elements: "<< endl;
    int el;
    int size_ = 0;
    for(int i = 0 ; i < len ; i++){
        
        cin >> el;
        
            
    sorting(arr, el, size_);
    size_ ++;

    cout << " [ ";    
    for (int l = 0 ;l < size_; l++){
        cout <<arr[l] << " " ;
    }cout <<" ]  Median -";  
    if ((size_ )%2 == 0){
        cout << "  " << (arr[(size_/2 )] + arr[((size_/2 )) -1])/2.0 << endl;
    }else{
        cout << " " << arr[(size_ )/2] << endl;
    }
        


    }

    



}



