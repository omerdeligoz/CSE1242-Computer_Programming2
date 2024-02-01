//Omer Deligoz 150120035

#include <stdio.h>
#include <math.h>

#define ROW 32
#define COLUMN 63

void findVertices(int verticesArr[][2], int iteration);

void constructTriangles(int verticesArr[][2], int size, char triangleArr[ROW][COLUMN], int triangleNumber);

void printArray(char triangleArr[ROW][COLUMN]);

int addedVertex = 0;

int main() {
    printf("%s", "Please enter iteration number between 0-4 :");

    //This loop repeatedly asks the user for an iteration number and prints the appropriate shape
    while (1) {
        addedVertex = 0;
        int triangleNumber, iteration, i, j;
        char triangleArr[ROW][COLUMN];
        scanf("%d", &iteration);

        //If the input is between 0 and 4, create and print the shape
        if (0 <= iteration && iteration <= 4) {

            //This loop assigns underscore(_) to all elements in the array
            for (i = 0; i < ROW; ++i) {
                for (j = 0; j < COLUMN; ++j) {
                    triangleArr[i][j] = '_';
                }
            }
            //Calculate and define some necessary variables
            triangleNumber = pow(3, iteration);
            int verticesArr[triangleNumber][2];
            int size = 32 / pow(2, iteration);

            //Call required methods
            findVertices(verticesArr, iteration);
            constructTriangles(verticesArr, size, triangleArr, triangleNumber);
            printArray(triangleArr);

            printf("%s", "\nPlease enter iteration number between 0-4 :");
        }
            //If the input is wrong, prompt user for a new iteration number
        else {
            printf("Please input a number between 0-4! :");
        }
    }
    return 0;
}

//This method prints the array
void printArray(char triangleArr[ROW][COLUMN]) {
    int i, j;
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COLUMN; ++j) {
            printf("%c", triangleArr[i][j]);
        }
        printf("\n");
    }
}

//This method uses the vertices of the triangles to create an appropriate shape with 1s and underscores.
void constructTriangles(int verticesArr[][2], int size, char triangleArr[ROW][COLUMN], int triangleNumber) {
    int i, j, k;
    for (i = 0; i < triangleNumber; ++i) {
        //Define the row and column of the vertex of the triangle to be drawn
        int row = verticesArr[i][0];
        int column = verticesArr[i][1];

        for (j = 0; j < size; ++j) {
            for (k = 0; k < 2 * j + 1; ++k) {
                triangleArr[row + j][column - j + k] = '1';
            }
        }
    }
}


//This method recursively finds the vertices of all triangles based on the given number of iterations.
void findVertices(int verticesArr[][2], int iteration) {

    //Size equals to row number of triangles
    int size = 32 / pow(2, iteration);

    //Base case
    if (iteration == 0) {
        verticesArr[0][0] = 0;
        verticesArr[0][1] = 31;
        addedVertex += 1;
    } else { //Recursive step
        int verticesWillAdd = pow(3, iteration) - pow(3, iteration - 1);

        //Call the method until (iteration - 1) = 0
        findVertices(verticesArr, (iteration - 1));
        int count = addedVertex;

        int i;
        //This loop finds the vertices and keeps them in an array
        for (i = 0; i < addedVertex; i++) {
            verticesArr[count][0] = verticesArr[i][0] + size;
            verticesArr[count][1] = verticesArr[i][1] - size;

            verticesArr[count + 1][0] = verticesArr[i][0] + size;
            verticesArr[count + 1][1] = verticesArr[i][1] + size;
            count += 2;
        }
        addedVertex += verticesWillAdd;
    }
}