#include <iostream>
#include<stdlib.h>
#include <time.h>
#include "point.h"

#include <queue>

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
void showq(queue<string> gq) { 
    queue<string> g = gq; 
    while (!g.empty()) { 
        cout <<g.front()<<"-"; 
        g.pop(); 
    } 
    cout << endl; 
}

void generatePattern(int pDimensionX, int pDimensionY ){
	
	srand(time(NULL));
	struct Point stack[1];
	queue<string> finalLines;

	int qtyAreas = pDimensionX/divisor(pDimensionX);  
	int qtyPoints = (qtyAreas/2)+1;
	Point origin = Point(0,rand()%pDimensionY+1);
	Point keyPoints[qtyPoints];
	keyPoints[0] = origin;               
	int distance = (pDimensionX/qtyAreas)*2;           
	for(int i = 1;i<qtyPoints;i++){
		Point keypoint = Point(distance,rand()%pDimensionY+1);   
		keyPoints[i] = keypoint;
		distance=distance*2;               
	} 
	
	float finish = 0.0;
	int i = 0;
	int temp = 0;
	while(finish!=qtyPoints){
		if(i>1+qtyPoints){
			finish+=0.50;
			i=0;
		}
		else{
			if(temp%2==0){
				Point randomPoint = Point(randomLimitado,randomLimitado); //*
				stack[0] = randomPoint;
				string recta = "{ ("+keyPoints[i].x+","+keyPoints[i].y+")"+randomPoint.x+","+randomPoint.y+") }  ";
				finalLines.push(recta); 
				i++;
				temp++;
			}
			else{
				string recta = "{ ("+stack[0].x+","+stack[0].y+")"+keyPoints[i].x+","+keyPoints[i].y+") }  ";
				finalLines.push(recta); 
				i++;
				temp++: 
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	/*
	int qtyLines = 5+rand()%(15+1-5);
	for(int i=0; i<qtyLines; i++) { 
		Point addingPoint = Point(rand()%pDimensionX+1, rand()%pDimensionY+1);
		//cout<<"X: "<<addingPoint.x<<"Y: "<<addingPoint.y<<endl;
		stack.push(addingPoint);	
	}
	*/

	
	
	
}

int main(){
	generatePattern(50,50);
	return 0;
}
