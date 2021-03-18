
#include <iostream>
#include<stdlib.h>
#include <time.h>

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
	
	int qtyAreas = divisor(pDimensionX);
	int origin[2] = {0,rand()%pDimensionY+1};
	int qtyPoints = (qtyAreas/2)+1;
	int matrixPoints[qtyPoints][2];
	matrixPoints[0][0] = origin[0];
	matrixPoints[0][1] = origin[1];
	int distance = pDimensionX/qtyAreas;
	for(int i = 1;i<qtyPoints;i++){
		matrixPoints[i][0] = distance;
		matrixPoints[i][1] = 0;
		distance+=distance*2;
	} 

	
}

int main(){
	generatePattern(20,20);
	
	return 0;
}
