#include <bits/stdc++.h>
#include <chrono>
using namespace std;
// A function to implement bubble sort
void bubbleSort(vector <int> arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    /*
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    */
}

// An optimized version of Bubble Sort
void opbubbleSort(vector<int> arr, int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(arr[j], arr[j+1]);
           swapped = true;
        }
     }
 
     // IF no two elements were swapped
     // by inner loop, then break
     if (swapped == false)
        break;
   }
   /*
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    */
}
//selection sort
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(vector <int> arr, int n)
{
    int i, j, min_idx;
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
          if (arr[j] < arr[min_idx])
              min_idx = j;
        }
        // Swap the found minimum element
        // with the first element
        if (min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
    /*
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    */
}
 
void insertionSort1(vector<int> arr,int n) {
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i;
        while(j>0){
            if(temp<arr[j-1]){
                arr[j]=arr[j-1];
            }else{
                break;
            }
            j--;
        }
        arr[j]=temp;
    }
    /*
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    */
}
int main(){
/*
    vector <int> arr1={3,2,1};
    vector <int> arr2={5,4,3,2,1};
    vector <int> arr3={10,9,8,7,6,5,4,3,2,1};
    vector <int> arr4={15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    vector <int> arr5={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
*/
    vector <int> arr;
    int length =20000;
    for(int j=0;j<length;j++){
        arr.push_back(rand()%100);
    }
    int n=arr.size();
    //vector <int> arr=arr2;
    //vector <int> arr=arr3;
    //vector <int> arr=arr4;
    //vector <int> arr=arr5;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     // Start measuring time
    auto begin =chrono::high_resolution_clock::now();
    //insertionSort1(arr,n);
    //bubbleSort(arr,n);
    //opbubbleSort(arr,n);
    selectionSort(arr,n);
    cout<<"Total elements in the array :"<<n<<endl;
    // Stop measuring time and calculate the elapsed time
    auto end =chrono::high_resolution_clock::now();
    auto elapsed =chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time taken is: %.6f seconds.\n", elapsed.count() * 1e-9);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   /* for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;*/
  

    return 0;
}