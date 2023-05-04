#include <iostream>
using namespace std;
// function to heapify the tree
void heapify(int arr[], int n, int root_index)  //root=root index | n=length of the array
{
    // build heapify
    int left_child_index=root_index*2+1; //left child
    int right_child_index=root_index*2+2; //right child
    int largest_index;
    if(left_child_index<n && arr[left_child_index]>arr[root_index]){
        largest_index=left_child_index;
    }else{
        largest_index=root_index;
    }
    if(right_child_index<n && arr[right_child_index]>arr[largest_index]){
        largest_index=right_child_index;
    }
    if(root_index!=largest_index){
        int temp=arr[largest_index];
        arr[largest_index]=arr[root_index];
        arr[root_index]=temp;
        heapify(arr,n,largest_index);   //array,length of the array,root
    }
}
// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    //build max heap
    for(int i=n/2-1;i>=0;i--) {
        heapify(arr, n, i);
    }
    // extracting elements from heap one by one
    for(int leaf=n-1;leaf>0;leaf--){
        int max_val=arr[0];
        arr[0]=arr[leaf];
        arr[leaf]=max_val;
        heapify(arr,leaf,0);
    }
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
{
    int size;
    cout<<"Enter the size of the array :";
    cin>>size;
    int heap_arr[size];
    for(int j=0;j<size;j++){
        int random=rand()%100;
        heap_arr[j]=random;
    }
    //int heap_arr[] = {4,17,3,12,9,6};
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}