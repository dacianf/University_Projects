#pragma once
#define TElem int

#define NULL_TELEM 0

class Matrix {
private:
	/*representation of the matrix*/
	int nLines, nCols;
	struct Node {
		int v = NULL_TELEM;
		int l = NULL_TELEM;
		int c = NULL_TELEM;
		Node* next = nullptr;
	};
	Node** T;
	int m;
	int lf;
public:

	//constructor
	//throws exception if nrLines or nrCols is negative or zero
	Matrix(int nrLines, int nrColumns);
	~Matrix();

	//theta(1)
	//returns the number of lines
	int nrLines() const { return this->nLines; };

	//theta(1)
	//returns the number of columns
	int nrColumns() const { return this->nCols; };

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);
	void print();
private:
	int TFunction(int l, int c) const;
	void resize();
};
