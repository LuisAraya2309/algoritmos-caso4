#include <iostream>
#include<stdlib.h>
#include <time.h>
#include "orderedPair.h"
#include <sstream> 
#include<string>
#include <queue>
#include<vector>
#include <bits/stdc++.h> 

using namespace std;

int divisor(int number){
	int divisores[9] = {10,9,8,7,6,5,4,3,2};
	for(int i = 0;i<9;i++){
		cout<<"Divisores"<<endl;
		if(number%divisores[i]==0){
			return divisores[i];
		}
	}
	return number;
}
void showq(queue<string> gq) { 
    queue<string> g = gq; 
    while (!g.empty()) { 
        cout <<g.front()<<" "; 
        g.pop(); 
    } 
    cout << endl; 
}

string ToString(int number){
	ostringstream str1;
	str1<<number;
	string final = str1.str();
	return final;
}

void generatePattern(int pDimensionX, int pDimensionY ){
	
	srand(time(NULL));
	queue<string> finalLines;
	vector<orderedPair> stack;
	vector<orderedPair> keyPoints;
	cout<<"Despues de declarar"<<endl;
	int qtyAreas = pDimensionX/divisor(pDimensionX);  
	cout<<"Devuelve el divisor"<<endl;
	int qtyPoints = (qtyAreas/2)+1;
	cout<<"1"<<endl;
	orderedPair origin = orderedPair(0,rand()%pDimensionY+1);
	cout<<"2"<<endl;
	keyPoints.push_back(origin);
	cout<<"3"<<endl;               
	int distance = (pDimensionX/qtyAreas)*2;
	int distancePoints = distance;
	cout<<"Antes del primer ciclo"<<endl;           
	for(int i = 1;i<qtyPoints;i++){
		cout<<"xd"<<endl;
		orderedPair keypoint = orderedPair(distance,rand()%pDimensionY+1);   
		keyPoints.push_back(keypoint);
		distance=distance*2;               
	} 
	
	float finish = 0.0;
	int i = 0;
	while(finish!=qtyPoints){
		cout<<"iteracion"<<endl;
		cout<<"i: "<<i<<endl;
		if(i>=qtyPoints){  // i=qtyPoints-2 
			cout<<"if primario"<<endl;
			finish+=0.25;
			i=0;
		}
		else{
			if(i%2==0){
				cout<<"If anidado"<<endl;
				int limiteInferior = (keyPoints.at(i).x)+1;
				int limiteSuperior = ((keyPoints.at(i).x) + distancePoints-1);
				cout<<"Superior: "<<limiteSuperior<<endl;
				orderedPair randomPoint = orderedPair(limiteInferior+ rand() % (limiteSuperior+1 - limiteInferior) ,rand()%pDimensionY ); 
				stack.insert(stack.begin(),randomPoint);
				string recta = "{ ("+ ToString(keyPoints[i].x) + ","+ ToString(keyPoints[i].y) + ")" +",(" + ToString(randomPoint.x) + "," + ToString(randomPoint.y)+") }  ";
				finalLines.push(recta); 
			}
			else{
				cout<<"Else anidado"<<endl;
				string recta = "{ (" + ToString(stack[0].x) + "," + ToString(stack[0].y)+")" + ",(" + ToString(keyPoints[i].x) + "," + ToString(keyPoints[i].y) + ") }  ";
				finalLines.push(recta); 
			}
			i++;
		}
	}
	
	showq(finalLines);
	
	
	
	
	
	
	
	


	
	
	
}

int main(){
	generatePattern(50,50);
	return 0;
}
