#include <iostream>
#include<list>
using namespace std;

struct Node{
    // A node will 2 entities
    //1. data type int called label
    int label;
    //2. a int type list called neighbours
    list <int> neighbours;

};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=10;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){
            nodes[i].label=i;
        }
    }

    void addedge(int u, int v){
        //select node u and push v into u's neighbour
            nodes[u].neighbours.push_back(v);
        //select node v and push u into v's neighbour
            nodes[v].neighbours.push_back(u);            
        }
    

    void print(){
        //lets iterate through each node and print its neighbours
        for (int i = 0 ; i < n;i++){
            cout << i << " --> ";
            for(int k :nodes[i].neighbours){
                cout << k << " ";
            }cout << endl;
        }

    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.
    g->addedge(1,2);
    g->addedge(2,3);
    g->addedge(1,3);
    g->addedge(1,4);
    g->addedge(1,5);
    g->addedge(4,6);
    g->addedge(5,6);
    g->addedge(7,5);
    g->addedge(4,7);
    g->addedge(5,8);
    g->addedge(4,8);
    g->addedge(2,6);
    //print the graph adjaceny list
    g->print();
}
