#include <iostream>
#include <vector>

using namespace  std;
int minimumTime(vector<int> &times,vector<int> &visited){
    int min_index=-1;
    int min_value=INT_MAX;
//    for(int i=0;i<6;i++){cout<<times[i]<<" ";}cout<<endl;
//    for(int i=0;i<6;i++){cout<<visited[i]<<" ";}cout<<endl;
    for(int i=0;i<6;i++){
        if(!visited[i] && times[i]<min_value){
            min_index=i;
            min_value=times[i];
        }
    }
    //cout<<min_index<<"++++";
    return min_index;
}

void dijkstra(vector<vector<int>> &graph,int soursVertex){
    vector<int> times(6,INT_MAX); //time taken to each vertex
    vector<int> visited(6, false);

    /////////////////////////////////////////////////
    times[soursVertex]=0;
    visited[soursVertex]= true;
    for(int j=0;j<6;j++){
        if(graph[soursVertex][j]!=0 && soursVertex!=j)
            times[j]=times[soursVertex]+graph[soursVertex][j];
    }
    //for(int i=0;i<6;i++){cout<<times[i]<<" ";}cout<<endl;
    ////////////////////////////////////////////////
    for(int i=0;i<5;i++){
        int minimumIndex= minimumTime(times,visited); //find the minimum time index of non visited edges

        //cout<<"minimum index:"<<minimumIndex<<"  "<<endl;

        visited[minimumIndex]=true;

        for(int j=0;j<6;j++){
            if(!visited[j] && graph[minimumIndex][j]!=0 && times[minimumIndex]+graph[minimumIndex][j]<times[j]){
                times[j]=times[minimumIndex]+graph[minimumIndex][j];
            }
        }
        //for(int i=0;i<6;i++){cout<<times[i]<<" ";}cout<<endl;
    }

    ///printing the final result
    cout<<"source vertex : "<<soursVertex<<endl;
    int totalTime=0;
    for(int i=0;i<=5;i++){
        cout<<"Minimum time taken From "<<soursVertex<<" to " <<i<<" is "<<times[i]<<endl;
        totalTime+=times[i];
    }
    float averageTime=(float)totalTime/5;
    printf("Average Time Taken : %.2f",averageTime);
}
int main() {
    vector<vector<int>> graph={{0,10,0,0,15,5},
                               {10,0,10,30,0,0},
                               {0,10,0,12,5,0},
                               {0,30,12,0,0,20},
                               {15,0,5,0,0,0},
                               {5,0,0,20,0,0}};
    dijkstra(graph,5);
    return 0;
}
