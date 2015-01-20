// The Nearest Neighbor Algorithm

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;



int numCities ;
int **cityDistances ;
int *cityPathTaken ;
double totalDistance  ;

double FindShortestPath_NN()  
{  
  clock_t start, end;  
 
 
  // recording the  start time of algorithm
 start = clock();  
 cout << " " << endl << endl ;
 bool *seen = new bool[numCities + 1] ;

 // Will start from first city by default  
 int cityVisited = 1;  
   
 int minDistance = INT_MAX;  
 
 int curr = 1;  
 int j;  
 int minDistanceCity = 0;  
 
 // Traversing through all the cities to find shortest path approximation
 while(cityVisited <= numCities)  
 {  
   
  // Iterate through all cites near minDistanceCity city   
  for(j=1; j<=numCities;j++)  
  {  
   // Checking if the distance from cityPathTakenent city to neighbour is lower then the minDistance   
   if(cityDistances[curr][j] < minDistance)  
   {  
    // if this city is not already visited
    if(!seen[j])  
    {  
     // recording the new minDistance  
     minDistance = cityDistances[curr][j];  
     minDistanceCity = j;  
    }  
   }  
  }  

   totalDistance += minDistance ;
  cityPathTaken[cityVisited] = minDistanceCity;   

 
  // set the cityPathTakenent city as already seen  
   seen[minDistanceCity] = true;  
  
  // set minDistanceCity as next base city for shortest path calculation
  curr = minDistanceCity;  
  
  // reset minDistance to INT_MAX for the next round  
  minDistance = INT_MAX;  


  // increment cityVisited counter  
  cityVisited++;  
 }  


 // Add retour to the first city  
 cityPathTaken[cityVisited] = cityPathTaken[1];  
 
 //add the distance of the last minDistanceCity back to the first city
 totalDistance += cityDistances[minDistanceCity][1] ;
  
 delete []seen ;
 

 // record end time of algorithm

 end = clock();  
 
//calculate time required in milliSeconds 
 double ct =((end-start)/ ((double)CLOCKS_PER_SEC)) * 1000.0;  
 
 return ct;  

}  

int main()
{
	

	double timeTaken ;

	std::cout << " Enter number of cities " << endl ;
	std::cin >> numCities ;

	cityPathTaken = new int[numCities +1];	
	cityDistances = new int*[numCities+1];

 	// allocating memory to the city Distance matrix
	for(int i = 0; i <= numCities; ++i)
    	cityDistances [i] = new int[numCities+1];

	
 	for (int s=0; s<=numCities; s++) {
	    for (int r=0; r<=numCities; r++) {
			if (s != r) {
				
				cityDistances[s][r]= rand()%25+1; //random function is used to generate the distance matrix from 1-25.
				cityDistances[r][s]= cityDistances[s][r];				
			
			}
			else
				cityDistances[s][r] = 0 ;
		}
	}
	

	cout << "Distance matrix" << endl ;
 	for (int s=1; s<=numCities; s++)  {
	    for (int r=1; r<=numCities; r++)  {
			
			cout << cityDistances[s][r] << "\t" ;			 
		}
		cout << endl ;
	}

	timeTaken = FindShortestPath_NN() ;

	cout << "Total distance traversed " << totalDistance << endl << endl ; // printing the total distance traversed
	cout << "Shortest Path Approximation " << endl ; //printing the shortest path
	for(int i = 1; i <= numCities+1; ++i)
		cout << cityPathTaken[i] << "  " ;
	
	cout << endl ;




	for(int i = 0; i <= numCities; ++i)
    	delete cityDistances [i] ;

	delete[] cityDistances;

	//delete[] cityPathTaken ;
	
	return 0 ;
	
}