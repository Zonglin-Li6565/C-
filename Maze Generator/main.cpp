#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

void randomPathGenerator(int* p_table, int startX, int startY, int endX, int endY, int cols);

void noiseGenerator(int* p_table, int rows, int cols);

void stepthrougthTable(int* p_table, int* p_steps, int startX, int startY, int numofSteps, int cols, int xStep, int yStep);

int main()
{
    int row, col;
    while(true){
        cout << "Enter the number of rows" << endl;
        cin >> row;
        cout << "Enter the number of columns" << endl;
        cin >> col;
        int two_D_array[row][col];
        int* p_twoD_array = &two_D_array[0][0];
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                two_D_array[i][j] = 1;
            }
        }
        randomPathGenerator(p_twoD_array, col - 1, row - 1, 0, 0, col);
        int numberofNoise = row * col * 2;
        for(int i = 0; i < numberofNoise; i++){
            noiseGenerator(p_twoD_array, row - 1, col - 1);
        }
        for(int i = 0; i < row; i++){
            cout << "\t|";
            for(int j = 0; j < col; j++){
                if(two_D_array[i][j] == 1){
                    cout << "0";
                }else if(two_D_array[i][j] == 0){
                    cout << " ";
                }
            }
            cout << "|" << endl;
        }
        delete[] p_twoD_array;
        p_twoD_array = NULL;
    }
    return 0;
}

void randomPathGenerator(int* p_table, int startX, int startY, int endX, int endY, int cols)
{
    int lengthX = startX > endX? startX - endX : endX - startX;
    int xStep = startX > endX? 1 : -1;
    int lengthY = startY > endY? startY - endY : endY - startY;
    int yStep = startY > endY? 1 : -1;
    if(lengthX < 3 || lengthY < 3){
        cerr << "denominator is zero" << endl;
        return;
    }
    srand( time( NULL ) );
    int random = rand();
    int xy_d = random % ((lengthX < lengthY? lengthX : lengthY)/3); //stepID = 0;
    int x_d = lengthX - xy_d; //stepID = 1;
    int y_d = lengthY - xy_d; //stepID = 2;
    int numofSteps = xy_d + x_d + y_d;
    int steps[numofSteps];
    int* p_steps = steps;
    for(int i = 0; i < numofSteps; i++){
        if(0 <= i && i < xy_d){
            steps[i] = 0; //xt direction
        }else if(xy_d <= i && i < xy_d + x_d){
            steps[i] = 1; //x direction
        }else {
            steps[i] = 2; //y direction
        }
    }
    for(int i = 0; i < numofSteps; i++){
        int randomIndex = rand() % numofSteps;
        int temp = steps[i];
        steps[i] = steps[randomIndex];
        steps[randomIndex] = temp;
    }
    stepthrougthTable(p_table, p_steps, startX, startY, numofSteps, cols, xStep, yStep);
    delete[] p_steps;
    delete[] p_table;
    p_steps = NULL;
    p_table = NULL;
}

void stepthrougthTable(int* p_table, int* p_steps, int startX, int startY, int numofSteps, int cols, int xStep, int yStep)
{
    int x = startX;
    int y = startY;
    for(int i = 0; i < numofSteps; i++){
        *(p_table + x + y * cols) = 0;
        if(*(p_steps + i) == 0){
            x = x - xStep;
            y = y - yStep;
        }else if(*(p_steps + i) == 1){
            x = x - xStep;
        }else if(*(p_steps + i) == 2){
            y = y - yStep;
        }
    }
    *(p_table + x + y * cols) = 0;
    delete[] p_steps;
    delete[] p_table;
    p_steps = NULL;
    p_table = NULL;
}

void noiseGenerator(int* p_table, int rows, int cols)
{
    int lengthX = 2;
    int lengthY = 2;
    int startX;
    int startY;
    int endX;
    int endY;
    while(lengthX < 3 || lengthY < 3){
        startX = rand() % cols;
        startY = rand() % rows;
        endX = rand() % cols;
        endY = rand() % rows;
        lengthX = startX > endX? startX - endX : endX - startX;
        lengthY = startY > endY? startY - endY : endY - startY;
    }
    randomPathGenerator(p_table, startX, startY, endX, endY, cols);
    for(int i = 1; i < 5; i++){
        rand();
    }
    delete[] p_table;
    p_table = NULL;
}
