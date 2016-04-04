#include <iostream>
class Sudoku{
	public:
	Sudoku();
	void solve();					//solve Sudoku
	bool solver(int row,int col);	//solve Sudoku row by row
	void readIn();					//readIn Sudoku board
	void printmap();				//printout Sudoku board
	bool check();					//check if Sudoku valid
	bool checkRow();
	bool checkCol();
	bool checkCell();
	bool checkmul();
	void changeNum(int a,int b);	//change two single number in the board
    void changeRow(int a,int b);	//change row0->row3 row1->row4 row2->row5(as you type"changeNum(0,1)")
	void changeCol(int a,int b);	//same as changeRow but change in column
	void rotate(int n);				//rotate the board clockwise with the angle (90*n)degrees;
	void flip(int n);				//flip the board vertically if n=0.Otherwise,flip it horizontally.
	void transform();//use fcn above to change the board
	void giveQuestion();//give a Sudoku question
	static const int sudokuSize = 81;
	private:
	int map[sudokuSize];
	int num[9];
};
