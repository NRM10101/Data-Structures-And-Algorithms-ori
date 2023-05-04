#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////Recursive merge method/////////
vector<int> Merge(vector<int> A,int p,int q,int r){
    //for(int i=0;i<A.size();i++){cout<<A[i]<<" ";}
    //cout<<endl;
    int n1=q-p+1;
    int n2=r-q;
    //create array L and R
    vector <int> L(n1) ,R(n2);
    ////////create left array and print ///////////////
    for(int i=0;i<=n1-1;i++){
        L[i]=A[p+i];
    }
    //cout<<"Left Array    :";for(int i=0;i<n1;i++){cout<<L[i]<<" ";}cout<<" ";
    ////////create right array and print//////////////
    for(int j=0;j<=n2-1;j++){
        R[j]=A[(q+1)+j];
    }
    //cout<<"Right Array   :";for(int i=0;i<n2;i++){cout<<R[i]<<" ";}cout<<endl;
    ////////merging///////////////////////////////////
    int i=0,j=0;int outer_k;
    for(int k=p;k<=r;k++){
        if(L[i]<=R[j]){
            //cout<<L[i]<<" "<<R[j]<<endl;
            A[k]=L[i];
            i++;
        }else {
            A[k]=R[j];
            j++;
        }
        //for(int i=0;i<A.size();i++){cout<<A[i]<<" ";};cout<<"     "<<"i: "<<i<<" j: "<<j<<" k: "<<k<<endl;
        if(i==n1 || j==n2){outer_k=k+1;break;}//dev
    }
    //cout<<"final"<<" "<<j<<" "<<outer_k<<endl;
    //cout<<"Left Array    :";for(int i=0;i<n1;i++){cout<<L[i]<<" ";}cout<<" ";
    //cout<<"Right Array   :";for(int i=0;i<n2;i++){cout<<R[i]<<" ";}cout<<endl;
    while(i<n1){
        A[outer_k]=L[i];
        outer_k++;i++;
    }
    while(j<n2){
        A[outer_k]=R[j];
        outer_k++;j++;
    }
    //for(int i=0;i<A.size();i++){cout<<A[i]<<" ";}cout<<endl;
    return A;
}
void MergeSort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        A=Merge(A, p, q, r);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
///////////iterative merge method/////////
vector<int> merge(vector<int> A,int L1,int R1,int L2,int R2){
    vector<int> temp(A.size());
    int index=0;
    while(L1<=R1 && L2<=R2){
        if( A[L1]<A[L2]){
            temp[index]=A[L1];
            index++;L1++;
        }else{
            temp[index]=A[L2];
            index++;L2++;
        }
    }
    while(L1<=R1){
        temp[index]=A[L1];
        L1++;index++;
    }
    while(L2<=R2){
        temp[index]=A[L2];
        L2++;index++;
    }
    return temp;
}
///////////iterative merge method//////
vector<int> mergeSort(vector<int> A){

    int n=A.size();
    int len=1;
    while(len<n){
        int i=0;
        while(i<n){
            //for(int i=0;i<A.size();i++){cout<<A[i]<<" ";}cout<<endl;
            int L1=i,R1=i+len-1;
            int L2=i+len,R2=i+2*len-1;
            if(L2>=n){break;}
            if(R2>=n){R2=n-1;}
            vector<int> temp=merge(A,L1,R1,L2,R2);
            //for(int i=0;i<A.size();i++){cout<<A[i]<<" ";}cout<<endl;
            for(int j=0;j<R2-L1+1;j++){
                A[i+j]=temp[j];
            }
            i=i+2*len;
        }
        len=2*len;

    }
    return A;
}
//////////////////////////////////////////////////////////////////////////////////////////
int main(){
    //vector<int> A={2,11,1,12,7,8,9,3};
    vector <int> A;
    int length =25000;
    for(int j=0;j<length;j++){
        A.push_back(rand()%100);
    }
    ///////////Recursive mergesort//////
    //auto start = chrono::steady_clock::now();
    auto begin1 =chrono::high_resolution_clock::now();
    cout<<"Recursive mergesort"<<endl;

    //for(int i=0;i<A.size();i++){cout<<A[i]<<" ";}cout<<endl;

    int p,q,r;
    p=0;r=A.size()-1;q=(p+r)/2;

    MergeSort(A,p,r);
    //auto end = chrono::steady_clock::now();
    auto end1 =chrono::high_resolution_clock::now();
    //for(int i=0;i<A.size();i++){cout<<A[i]<<" ";}cout<<endl;
    //cout<<"Time taken to recursive mergeSort : "<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<< " milliseconds" << endl;
    auto elapsed =chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
    printf("Time taken is: %.6f seconds.\n", elapsed.count() * 1e-9);
    cout<<"length:"<<length<<endl;
    cout<<endl;
    ///////////iterative mergesort/////
    //A={1,2,11,12,7,8,9,3};
    auto begin2 =chrono::high_resolution_clock::now();
    vector<int> arr;
    //length =1000;
    for(int j=0;j<length;j++){
        arr.push_back(rand()%100);
    }
    A=arr;
    cout<<"Iterative mergesort"<<endl;
    //for(int i=0;i<A.size();i++){cout<<A[i]<<" ";}cout<<endl;

    vector<int> sorted_A=mergeSort(A);

    //for (int i = 0; i < sorted_A.size(); i++)cout << sorted_A[i] << " ";cout<<endl;
    //auto end2 = chrono::steady_clock::now();

    //cout<<chrono::duration_cast<chrono::nanoseconds>(end2-end).count()<<" nanoseconds"<<endl;
   //cout<<"Time taken to iterative merge sort : "<<chrono::duration_cast<chrono::microseconds>(end2-end).count()<< " microseconds" << endl;
    //cout<<chrono::duration_cast<chrono::milliseconds>(end2-end).count()<<" milliseconds"<<endl;
    //cout<<"Time taken to iterative merge sort : "<<chrono::duration_cast<chrono::seconds>(end2-end).count()<< " seconds";

    auto end2 =chrono::high_resolution_clock::now();
    auto elapsed_2 =chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    printf("Time taken is: %.6f seconds.\n", elapsed_2.count() * 1e-9);
    cout<<"length:"<<length;

    return 0;
}
