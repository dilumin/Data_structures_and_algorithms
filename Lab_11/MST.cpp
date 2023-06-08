#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// returns the minimum element in Q
int extract_min(vector <int> &Q ,int d[] ){
    int min = INT_MAX;
    int min_ind;
    int extracting_ind;
    for (int i = 0 ; i < (int) Q.size() ; i++){
        if(min > d[Q[i]]){
            min = d[Q[i]];
            min_ind = Q[i];
            extracting_ind = i;

        }
    }
    Q.erase(Q.begin() + extracting_ind);
    return min_ind;

}
// checks if a is in Q
bool check_key (vector <int> Q , int  a){
    for (int y : Q){
        if (y== a){
            return true;
        }

    }
    return false;
}




void mst(int adj_matrix [6][6] ,int start ){
    int parent[6];
    int d[6]{0};
    // initializing d and parent
    for (int i= 0 ; i < 6 ; i++){
        d[i] = INT_MAX;
        parent[i] = -1;
    }
    // setting the start node
    d[start] =0;
    parent[start] = -1;
    
    vector <int> Q = {0,1,2,3,4,5};
    
    while (!Q.empty()) {
        int u = extract_min(Q, d);
        for (int v = 0; v < 6; v++) {
            if (adj_matrix[u][v] != 0) {

                if (check_key(Q, v) && adj_matrix[u][v] < d[v]) {
                    parent[v] = u;
                    d[v] = adj_matrix[u][v];
                }

            }
        }


    }
    // printing the mst
    for (int o = 1 ; o < 6 ; o ++){
        cout << parent[o] << " - " << o << " : " << d[o] << endl;
    }




}


int main() {

    int adj_matrix [6][6] = {
             {0,3,0,0,0,1},{3,0,2,1,10,0} , {0,2,0,3,0,5},{0,1,3,0,5,0}
            ,{0,10,0,5,0,4} , {1,0,5,0,4,0}
    };
    mst(adj_matrix,0);
    return 0;
}

