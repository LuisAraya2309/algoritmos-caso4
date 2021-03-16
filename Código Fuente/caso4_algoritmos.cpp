#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void generarMatriz(int altura, int anchura) {
    srand(time(NULL));
    string numbers[altura][anchura];
	
	//Inicializa la matriz
    for(int i=0; i<altura; i++) {
        for(int j=0; j<anchura; j++) {
            numbers[i][j] = " ";
        }
    }
	
	//Genera la curva
    int randomInicio = 1 + rand()% ((anchura-1)-1+1); 
    int random = 0;
    int i=0;
    for (; i < altura; i++) {
        for (int j = 0; j < 1; j++) {
            random = (randomInicio-1) + rand() % ( (randomInicio+1) - (randomInicio-1) + 1);
            randomInicio = random;
            if(random>=0 && random<anchura){
                numbers[i][random] = "C";
            } else {
                i--;
            }
        }
    }
    
    //Genera las rectas
    for(int i=0; i<altura-1; i++) {
	    for(int j=0; j<anchura; j++) {
	        if((numbers[i][j]=="C")&&((i%2)==0)){
	        	if((numbers[i+1][j-1]!="C")&&(i+1<altura)&&(j-1>=0)){
	        		numbers[i+1][j-1]="X";
				}
				else{
					continue;
				}
			}
			else{
				continue;
			}
	    }
    }
    
    

    //Imprime la matriz
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < anchura; ++j) {
            cout << numbers[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    generarMatriz(20, 20);
    return 0;
}
