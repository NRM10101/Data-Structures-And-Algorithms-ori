#include <iostream>
#include<list>
using namespace std;

struct Node{
    // A node will 2 entities
    //1. data type int called label
    //2. a int type list called neighbours

};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=5;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){
            nodes[i].label=i;
        }
    }

    void addedge(int u, int v){
        //select node u and push v into u's neighbour

        //select node v and push u into v's neighbour
    }

    void print(){
        //lets iterate through each node and print its neighbours

    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.
    
    //print the graph adjaceny list
    g->print();
}
