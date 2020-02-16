#include<bits/stdc++.h>
#define vector<int> vi;
using namespace std;

int originalGraph[40][40], minimumSpanningTree[40][40], adjacencymat[40][40]; //Adjaency Matrix For MST
bool visited[10];

int parentMST[40], verticesMST[40];
unordered_map<string, int> mstMap; //Path and cost for the particular MST

unordered_map<string,int> closedList; /*Closed List kept to keep 
track of nodes that have been extended, and can be used to prune away the paths.*/

class Node{
    /*I'll define the states of Problem. Also, cities will be stored in Priority Queue*/
    int cityName, citiesNotVisited, hcost, actualCost, totalCost;
    string state, pathSoFar;
    vi citiesLeft;
    char name;

    bool operator <(Node  other) const
    {
        return  this->totalCost > other.totalCost;
    }
    Node(){};
    Node(int citynum,string pathSoFar,int citiesNotVisited,char name,int hCost,int actualCost,int totalCost,string state,vi citiesLeft):citynum(citynum),pathSoFar(pathSoFar),citiesNotVisited(citiesNotVisited),name(name),hCost(hCost),actualCost(actualCost),totalCost(totalCost),state(state),citiesLeft(citiesLeft){}
}City[10000];

int nodeTrack = 0;

priority_queue<Node> astar;

class TSP{
    public:

        char node[3];
        int points[40][2],numCities;
        
        void inputData(){
            int i = 0;
            scanf("%d",&numCities);
            getc_unlocked(stdin); // '\n' eaten
            


        }
}

int main(){
    
}