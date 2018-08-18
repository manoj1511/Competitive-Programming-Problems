#include <iostream>
using namespace std;

bool check0(int grid[9][9], int &row, int &col){
	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++)
			if (grid[row][col] == 0)
				return true;
	return false;
}

bool checkRow(int grid[9][9], int row, int num){
	for (int col = 0; col < 9; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}

bool checkCol(int grid[9][9], int col, int num){
	for (int row = 0; row < 9; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}

bool checkBox(int grid[9][9], int startR, int startC, int num){
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + startR][col + startC] == num)
				return true;
	return false;
}

bool Sudoku(int grid[9][9]){
	int row, col;
	if (!check0(grid, row, col)){
		return true;
	}
	for (int num = 1; num <= 9; num++){
		if (!checkRow(grid, row, num) && !checkCol(grid, col, num) && !checkBox(grid, row - row % 3, col - col % 3, num)){
			grid[row][col] = num;
			if (Sudoku(grid))
				return true;
			grid[row][col] = 0;
		}
	}
	return false;
}

void print(int grid[9][9])
{
	cout << "----------------------------------" << endl;
	for (int row = 0; row < 9; row++)
	{
		cout << "| ";
		for (int col = 0; col < 9; col++)
		{
			cout << grid[row][col] << "  ";
			if (col == 2 || col == 5) cout << "| ";
		}
		cout << "|";
		cout << endl;
		if (row == 2 || row == 5) cout << "----------------------------------" << endl;
	}
	cout << "----------------------------------" << endl;

}

int main(){
	int grid[9][9] = { 
	{ 0, 5, 4, 0, 0, 0, 0, 8, 0 },
	{ 0, 0, 0, 8, 4, 0, 0, 2, 6 },
	{ 0, 8, 0, 0, 0, 0, 4, 0, 0 },
	{ 0, 0, 6, 3, 0, 0, 5, 0, 0 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 0, 0, 8, 0, 0, 2, 9, 0, 0 },
	{ 0, 0, 3, 0, 0, 0, 0, 1, 0 },
	{ 8, 2, 0, 0, 7, 1, 0, 0, 0 },
	{ 0, 4, 0, 0, 0, 0, 6, 5, 0 } };

	cout << "The Entered Sudoku puzzle is:" << endl;
	
	print(grid);

	Sudoku(grid);

	cout << "\n\nThe Solved Sudoku is:" << endl;

	print(grid);

	return 0;
}
