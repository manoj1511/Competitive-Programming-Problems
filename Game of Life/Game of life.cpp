//============================================================================
// Name        : Game.cpp
// Author      : Manoj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <unistd.h>
#include <ctime>
#include <string>

using namespace std;

const int gridSize = 30;
void printGrid(bool gridOne[gridSize+1][gridSize+1]);
void determineState(bool gridOne[gridSize+1][gridSize+1]);
void ClearScreen();

int main(){
	srand(time(NULL));
    bool gridOne[gridSize+1][gridSize+1] = {};
    char start;
    for (int i = 0; i<=gridSize; i++)
    		for(int j = 0;j<=gridSize; j++)
    		{
    			int temp = rand() % 10;
    			if (temp%2 == 0)	gridOne[i][j] = true ;
    			else	gridOne[i][j] = false;
    		}
    printGrid(gridOne);
    cout << "Enter y to start"<<endl;
    cin >> start;

    if(start == 'y' || 'Y')
    {
        while (true)
        {
            printGrid(gridOne);
            determineState(gridOne);
            usleep(500000);
            ClearScreen();


        }
    }
    else
    {
        return 0;
    }

}
void ClearScreen()
{
	cout << string( 100, '\n' );
}

void printGrid(bool gridOne[gridSize+1][gridSize+1]){
    for(int a = 1; a < gridSize; a++)
        {
        for(int b = 1; b < gridSize; b++)
        {
            if(gridOne[a][b] == true)
            {
                cout <<" * ";
            }
            else
            {
                cout <<"  ";
            }
            if(b == gridSize-1)
            {
                cout << endl;
            }
        }
    }
}

void compareGrid (bool gridOne[gridSize+1][gridSize+1], bool gridTwo[gridSize+1][gridSize+1]){
    for(int a =0; a < gridSize; a++)
    {
        for(int b = 0; b < gridSize; b++)
        {
                gridTwo[a][b] = gridOne[a][b];
        }
    }
}

void determineState(bool gridOne[gridSize+1][gridSize+1]){
    bool gridTwo[gridSize+1][gridSize+1] = {};
    compareGrid(gridOne, gridTwo);

    for(int a = 1; a < gridSize; a++)
    {
        for(int b = 1; b < gridSize; b++)
        {
            int alive = 0;
            for(int c = -1; c < 2; c++)
            {
                for(int d = -1; d < 2; d++)
                {
                    if(!(c == 0 && d == 0))
                    {
                        if(gridTwo[a+c][b+d])
                        {
                        	++alive;
                        }
                    }
                }
            }
            if(alive < 2)
            {
                gridOne[a][b] = false;
            }
            else if(alive == 3)
            {
                gridOne[a][b] = true;
            }
            else if(alive > 3)
            {
                gridOne[a][b] = false;
            }
        }
    }
}



