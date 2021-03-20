/*
Instituto Tecnológico de Costa Rica
Escuela de Computación
Análisis de Algortimos
Profesor: Rodrigo Núñez Núñez
Estudiantes: 
Luis Carlos Araya Mata Carné: 2020205005
Kendall Cascante Mesen Carne: 2019039628
------
Grupo: 1
I Semestre
2021
Martes 19 de marzo de 2021
19/03/2021


CASO 4
*/


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
	
	srand(time(NULL)); //    4
	queue<string> finalLines; 
	vector<orderedPair> stack;
	vector<orderedPair> keyPoints;
	int qtyAreas = pDimensionX/divisor(pDimensionX); //  4 
	int qtyPoints = (qtyAreas/2)+1; //  3
	orderedPair origin = orderedPair(0,rand()%pDimensionY+1); //  7   
	keyPoints.push_back(origin); //  2               
	int distance = (pDimensionX/qtyAreas)*2; //  3
	int distancePoints = distance; // 1
	for(int i = 1;i<qtyPoints;i++){ //  1 + (  3             ->   1+(3+11)  =   1 + 14n esto corresponde al for
		orderedPair keypoint = orderedPair(distance,rand()%pDimensionY+1); //  7
		keyPoints.push_back(keypoint);  // 2  
		distance=distance*2;            //2   
	} 
	float finish = 0.0; // 1
	int i = 0;          // 1
	while(finish!=qtyPoints){  // 1 
		if(i>=qtyPoints){ // 1
			finish+=0.25; //2
			i=0;      // 1
		}
		else{
			if(i%2==0){ //2
				if((keyPoints.at(i).x)+distancePoints<pDimensionX){ //  5 
 					int limiteInferior = (keyPoints.at(i).x)+1; //  5 
					int limiteSuperior = ((keyPoints.at(i).x) + distancePoints-1);  // 6
					orderedPair randomPoint = orderedPair(limiteInferior+ rand() % (limiteSuperior+1 - limiteInferior) ,rand()%pDimensionY ); // 11
					stack.insert(stack.begin(),randomPoint); //4
					string recta = "{ ("+ ToString(keyPoints[i].x) + ","+ ToString(keyPoints[i].y) + ")" +",(" + ToString(randomPoint.x) + "," + ToString(randomPoint.y)+") }  ";// 24
					finalLines.push(recta); // 2
				}	 
			}
			else{
				string recta = "{ (" + ToString(stack[0].x) + "," + ToString(stack[0].y)+")" + ",(" + ToString(keyPoints[i].x) + "," + ToString(keyPoints[i].y) + ") }  "; //26
				finalLines.push(recta); //2
			}
			i++; //2
		}
	}
	
	showq(finalLines); //2	
}

//f(n) = 27 + 74n
// O(n) 


int main(){
	/*
	Para generar el patron solamente llame a la funcion generatePattern con sus dimensiones respectivamente. 
	*/
	generatePattern(50,50);
	generatePattern(100,100);
	
	
	return 0;
}
