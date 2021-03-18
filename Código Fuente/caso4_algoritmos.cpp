#include <iostream>
#include<stdlib.h>
#include <time.h>
#include "stack.h"
#include "point.h"

using namespace std;

int divisor(int number){
	int divisores[9] = {10,9,8,7,6,5,4,3,2};
	for(int i = 0;i<9;i++){
		if(number%divisores[i]==0){
			return divisores[i];
		}
	}
	return number;
}

void generatePattern(int pDimensionX, int pDimensionY ){
	
	srand(time(NULL));
	Stack<Point> stack;
	List<Point> keyPoints;

	int qtyAreas = pDimensionX/divisor(pDimensionX);  
	int qtyPoints = (qtyAreas/2)+1;
	Point origin = Point(0,rand()%pDimensionY+1);
	keyPoints.addToEnd(origin);               
	int distance = (pDimensionX/qtyAreas)*2;           
	for(int i = 1;i<qtyPoints;i++){
		Point keypoint = Point(distance,rand()%pDimensionY+1);    
		keyPoints.addToEnd(keypoint);
		distance=distance*2;               
	} 

	int qtyLines = 5+rand()%(15+1-5);
	for(int i=0; i<qtyLines; i++) { 
		Point addingPoint = Point(rand()%pDimensionX+1, rand()%pDimensionY+1);
		stack.push(addingPoint);
	}
	
	
}

int main(){
	generatePattern(50,50);
	return 0;
}
