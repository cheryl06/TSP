
//2.AND 3. Source code for BRUTE FORCE



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <math.h>
 
using namespace std;

int *distanceArr ;

void tsp(int numCities,  char* nodes) ;

int main() {
 
    int numCities; //declared the number of nodes (cities)
    cout << "Please enter the numbers of nodes: " << endl ;
    cin >> numCities ;
 
	// declaring x-axis and y-axis of graph
 	distanceArr = new int[numCities * numCities];

    char* nodes  = new char[numCities];
 
    // generating random x and y values for each point
    int i, j;
    srand(time(NULL));
    for(i=0; i<numCities; i++) {
        nodes[i] = i;

		for ( j = 0; j < numCities; j++ )
		{
			if (i != j) {
				// map distances between two nodes to a 1-D array
				distanceArr[j+(i*numCities)] = rand()%25 + 1;             //rand function is used to randomly generate the matrix with a limit of 1-25.
				distanceArr[i+(j*numCities)] =  distanceArr[j+(i*numCities)] ;
			}
			else {
				distanceArr[j+(i*numCities)] = 0 ;

			}
				
			
		}

	}
		
		

	cout << "Distance Matrix " << endl << endl ; // printing the distance matrix
    for(i=0; i<numCities; i++) {
		for ( j = 0; j < numCities; j++ ) {
			cout << distanceArr[j+(i*numCities)]  << "\t" ;
		}
		cout << endl ;
	}
 
    tsp(numCities,nodes);
 
	delete []distanceArr ;
    return 0;
} 

void tsp(int numCities, char* nodes) {
    int tmpcost, shortest_path;
    int cheap_path[numCities];
    int i, i1, i2  ;
	
	shortest_path = INT_MAX ;
 
    //PERMUTATIONS
    do {
        tmpcost = 0;
       

			i1 = numCities - 1;
			for ( i2 = 0; i2 < numCities; i2++ )
			{
			  tmpcost = tmpcost + distanceArr[nodes[i1]+(nodes[i2]*numCities)];
			  i1 = i2;
			}
		
		
        if( shortest_path!=0 && shortest_path > tmpcost ) {  // checking for the shortest path
            shortest_path = tmpcost;
            for (i=0; i<numCities; i++) {
                cheap_path[i] = nodes[i];
            }
        }
        
    } while(next_permutation(nodes,nodes+numCities));
 
    //PRINTING THE RESULTS
	cout << endl ;
    printf("RESULTS\n The shortest path is : ");
    for (i=0; i<numCities; i++) {
        cout << cheap_path[i] << "\t";
    }
	cout << cheap_path[0] << endl ;

	
    cout << "Shortest path is " << shortest_path << endl ; // printing the shortest path
	
	
}
 
