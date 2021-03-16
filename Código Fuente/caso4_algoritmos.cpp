#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void generarMatriz(int altura, int anchura) {
    srand(time(NULL));
    string numbers[altura][anchura];

    for(int i=0; i<altura; i++) {
        for(int j=0; j<anchura; j++) {
            numbers[i][j] = " ";
        }
    }

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
                cout << "else" << endl;
                i--;
            }
        }
    }

    //  Printing array elements
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
