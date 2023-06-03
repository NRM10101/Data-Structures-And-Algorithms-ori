#include <iostream>
#include <vector>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
//To find minimum unvisited node index
int minNodeIndex(vector<int> &nodes,vector<int> &mstSet){
    int minIndex=-1;
    int minValue=INT_MAX;
//    for(int i=0;i<mstSet.size();i++){cout<<nodes[i]<<",";}cout<<endl;
//    for(int i=0;i<mstSet.size();i++){cout<<mstSet[i]<<",";}cout<<endl;
    for(int i=0;i<mstSet.size();i++){
        //if unvisited
        if(!mstSet[i] && nodes[i]<minValue){
            minValue=nodes[i];
            minIndex=i;
        }
    }
    return  minIndex;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
////To print final MST
void printMST(vector<int> &parents,vector<vector<int>> &graph){
    cout<<"| edge   |  weight |"<<endl;
    cout<<"+------------------+"<<endl;
    for(int i=1;i<parents.size();i++){
        printf("| %d - %d  |    %d    |\n",parents[i],i,graph[parents[i]][i]);
    }
    cout<<"+------------------+"<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void prims_MST_Algorithm(vector<vector<int>> &graph,int startNode){
    int noOfNodes=graph[0].size();//no of nodes of the graph

    vector<int> parents(noOfNodes,-1);  //to store MST
    vector<int> mstSet(noOfNodes,false);    //to store each node is visited or not--mstSet
    vector<int> nodes(noOfNodes,INT_MAX);   //[INF,INF,INF,INF,INF,INF]

    //////////////////////////////////////////////////////////////
    mstSet[startNode]=true;
    nodes[startNode]=0;                   //[0,INF,INF,INF,INF,INF]
    vector<int> edgeValuesForCurrentVertex=graph[startNode]; //[0,3,0,0,0,1]
    for(int i=0;i<noOfNodes;i++){
        //1. check whether is there exist an edge between (u,v)=(startNode->i)
        if(edgeValuesForCurrentVertex[i]!=0 && edgeValuesForCurrentVertex[i]<nodes[i]){
            nodes[i]=edgeValuesForCurrentVertex[i];
            parents[i]=startNode;
        }
    }   //[0,3,INF,INF,INF,1]
    //parents[minNodeIndex(nodes,mstSet)]= startNode;
//    cout<<"parents:";
//    for(int i=0;i<parents.size();i++){cout<<parents[i]<<" ";}cout<<endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    for(int i=0;i<(noOfNodes-1);i++){ //until all vertices are true
        int minIndex=minNodeIndex(nodes,mstSet);
        mstSet[minIndex]= true;
        edgeValuesForCurrentVertex=graph[minIndex];
        //for(int i=0;i<mstSet.size();i++){cout<<edgeValuesForCurrentVertex[i]<<",";}cout<<endl;
        for(int j=0;j<noOfNodes;j++) {
            //1. check whether is there exist an edge between (u,v)=(startNode->i)
            //2.(u-v)----check (weight of edge --w(u,v))< weight of v --w(v)
            //3.check whether j is visited or not
            if(edgeValuesForCurrentVertex[j]!=0 && edgeValuesForCurrentVertex[j]<nodes[j] && !mstSet[j]){
                nodes[j]=edgeValuesForCurrentVertex[j];
                parents[j]=minIndex;
            }
        }
        //cout<<"parents:";
        //for(int i=0;i<parents.size();i++){cout<<parents[i]<<" ";}cout<<endl;
    }
    //////////////////////////////////
//    cout<<"nodes >";
//    for(int i=0;i<mstSet.size();i++){cout<<nodes[i]<<" ";}cout<<endl;
//    cout<<"mstSet >";
//    for(int i=0;i<mstSet.size();i++){cout<<mstSet[i]<<" ";}cout<<endl;
    cout<<"Starting vertex : "<<startNode<<endl;
    cout<<"+------------------+"<<endl;
    printMST(parents,graph);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    vector<vector<int>> graph={{0,3,0,0,0,1},
                               {3,0,2,1,10,0},
                               {0,2,0,3,0,5},
                               {0,1,3,0,5,0},
                               {0,10,0,5,0,4},
                               {1,0,5,0,4,0}};

    prims_MST_Algorithm(graph,0);
    return 0;
}
