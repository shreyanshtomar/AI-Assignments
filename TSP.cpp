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
            
            while (i < numCities)
            {
                scanf("%s,%d,%d",node,&points[i][0],&points[i][1]);
                i++;
            }
        }
            int calculateDistance(int x1, int x2, int y1, int y2){
                return int(sqrt(pow(x1-x2,2)+pow(y1-y2,2)) + 0.5); //*****
            }

            void createOriginalDistanceGraph(){
                for (int i = 0; i < numCities; i++)
                {
                    originalGraph[i][i] = 0;
                    adjacencymat[i][i] = 0;
                    for (int j = i+1; j < numCities; j++)
                    {
                        /*Symmetric Tsp*/
                        originalGraph[i][j] = calculateDistance(points[i][0],points[j][0],points[i][1],points[j][1]);
                        originalGraph[j][i] = originalGraph[i][j];
                        adjacencymat[i][j]=0;
                        adjacencymat[j][i]=0;
                        minimumSpanningTree[i][j]=INT_MAX;
                        minimumSpanningTree[j][i]=INT_MAX;

                    }
                    
                }
                
            }

};

int distance(int city1, int city2){
    return originalGraph[city1][city2];
}

int buildMinimumSpanningTree(vector<int> vertices,vector<char> nodesLeft)
{
    /*This function returns the length of the minimumSpanningTree for the
    remaining unvisited Cities.
    */
    int size=vertices.size();
    if(size==1)
    {
        return 0;
    }
    
    int pcity[40],pdist[40],minDistance=INT_MAX;
    vector<int>::iterator it1;
    vector<char>::iterator it2;
    int i=0;
    string cities;
    sort(nodesLeft.begin(),nodesLeft.end());
    for(it1=vertices.begin(),it2=nodesLeft.begin();it1!=vertices.end(),it2!=nodesLeft.end();it1++,it2++)
    {
        pcity[i]=*it1; //parent city 
        pdist[i]=INT_MAX; //parent distance;
        i++;
        cities+=*it2;
    }
    
    unordered_map<string,int>:: iterator mit;//iterator for the hash map for the MST
    //So that we don't have to calculate the MST length again and again for each path.
    mit=mstMap.find(cities);
    if(mit!=mstMap.end())
    {
        return mit->second;
    }
    
    int newCity=pcity[size-1];//i.e we are making the last city as the newCity for finding the MST
    int thisDistance;
    int length=0,minIndex;
    for(int m=size-1;m>0;m--)
    {
        minDistance=INT_MAX;
        for(int j=0;j<m;j++)
        {
            thisDistance=distance(pcity[j],newCity);
            
            if(thisDistance < pdist[j]) pdist[j]=thisDistance;
            if(pdist[j]<minDistance) minDistance=pdist[j],minIndex=j;
        }
        newCity=pcity[minIndex];
        length+=minDistance;
        pcity[minIndex]=pcity[m-1];
        pdist[minIndex]=pdist[m-1];   
    }
    mstMap[cities]=length;
    return length;
    
}


int main(){
    
}