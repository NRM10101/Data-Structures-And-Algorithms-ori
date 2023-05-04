#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}
int partition (vector<int> &A, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r- 1; j++)
    {
        if (A[j] <= x){
            i++;
            swap (&A[i], &A[j]);
        }
    }
    swap (&A[i + 1], &A[r]);
    return (i + 1);
}
///////////////////////Recursive quick sort////////////////////////
void quickSort(vector<int> &A, int p, int r)
{
    if (p < r){
        int q = partition(A, p,r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}
/////////////////////Iterative quick sort////////////////////////
/* A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index */
void quickSortIterative(vector<int> &arr, int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

int main() {
    /////////////recursive quicksort//////////////
    //int a[] = {2, 6, 5, 1, 3, 4};
    vector <int> a;
    int length =25000;
    cout<<"Length of array :"<<length<<endl;
    for(int j=0;j<length;j++){
        a.push_back(rand()%100);
    }
//    for (int i = 0; i < length; i++)
//        cout << a[i] << " ";
//    cout<<endl;
    cout<<"Recursive quicksort"<<endl;
    auto begin1 =chrono::high_resolution_clock::now();
    quickSort(a, 0, length - 1);
    auto end1 =chrono::high_resolution_clock::now();
    auto elapsed =chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
    elapsed=elapsed*1000;
    printf("Time taken is: %.6f milliseconds.\n", elapsed.count() * 1e-9);
//  cout<<"Time taken to recursive mergeSort : "<<chrono::duration_cast<chrono::milliseconds>(end1-begin1).count()<< " milliseconds" << endl;
//    for (int i = 0; i < length; i++)
//        cout << a[i] << " ";
    cout<<endl<<endl;
    ////////////non recursive quicksort//////////
    //int b[] = {2, 66, 5, 1, 3, 4};
    vector <int> b;
    cout<<"Length of array :"<<length<<endl;
    for(int j=0;j<length;j++){
        b.push_back(rand()%100);
    }
//    for (int i = 0; i < length; i++)
//        cout << b[i] << " ";
//    cout<<endl;
    cout<<"Non Recursive quick sort"<<endl;
    auto begin2 =chrono::high_resolution_clock::now();
    quickSortIterative(b,0,length-1);
    auto end2 =chrono::high_resolution_clock::now();
    elapsed =chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    elapsed=elapsed*1000;
    printf("Time taken is: %.6f milliseconds.\n", elapsed.count() * 1e-9);
//    for (int i = 0; i < length; i++)
//        cout << b[i] << " ";
    return 0;
}
