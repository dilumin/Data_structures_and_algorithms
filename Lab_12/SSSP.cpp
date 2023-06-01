#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//to get the minimum distanced vertex from starting node from Q
int extract_min(vector <int> Q ,int d[6]){
    int min = INT_MAX;
    int min_ind_Q;
    for (int i =0 ; i < (int) Q.size() ;i++ ){
        if (d[Q[i]] < min ){
            min = d[Q[i]];
            min_ind_Q = i;

        }

    }
    return min_ind_Q ;
}
//relaxation of uv edge
int relax(int u , int v , int l ,int d[]){
    if ( d[v] > d[u] + l ){
        d[v] = d[u] + l;

    }

}

void dijkstra (int G[6][6] , int s , int d[6]  ){
    vector <int> Q ={0,1,2,3,4,5};
    vector <int> S ;
    d[s] = 0;

    while ( (int) Q.size() != 0 ){
        int min_ind = extract_min(Q , d);
        int u = Q[min_ind];
        Q.erase(Q.begin() + min_ind);
        S.push_back(u);
        int ind = 0;
        for (int l :G[u]){
            if (l != 0){
                relax(u , ind , l , d);
            }
            ind ++;

        }


    }
    cout << "Starting node " << s << endl;
    for (int l = 0 ; l < 6 ; l++){
        cout << "Distance to vertex " << l << " =  " << d[l] << endl;
    }

}




int main(){
    int G[6][6]= {{0,10,0,0,15,5},{10,0,10,30,0,0},{0,10,0,12,5,0},{0,30,12,0,0,20},{15,0,5,0,0,0},{5,0,0,20,0,0}
    };
    //distance of each vertex from starting is set to maximum value at intialization
    int distance [6] = {INT_MAX ,INT_MAX ,INT_MAX , INT_MAX, INT_MAX,INT_MAX};
    //to select the starting node
    int start = 2;
    dijkstra(G, start, distance);
    int sum = 0;
    for (int a: distance){
        sum+= a;

    }
    double avg_d = sum /5.0;


    cout << "The average is " << avg_d <<endl;
    cout << endl;


}