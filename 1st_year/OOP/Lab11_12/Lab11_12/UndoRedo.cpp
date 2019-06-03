#include "UndoRedo.h"


UndoRedo::UndoRedo(Repository& repository) : repo(repository)
{
	this->undoRedo.push_back(repo.listOfSecurityRecords);
	this->undoRedoIndex = 0;
}

void UndoRedo::addBackup(std::vector<SecurityRecord> save)
{
	if (this->undoRedoIndex < this->undoRedo.size() - 1)
		this->undoRedo.erase(undoRedo.begin() + undoRedoIndex + 1, undoRedo.end());
	this->undoRedo.push_back(save);
	this->undoRedoIndex++;
}

bool UndoRedo::undo()
{
	if (this->undoRedoIndex > 0) {
		this->repo.listOfSecurityRecords = this->undoRedo[--this->undoRedoIndex];
		return true;
	}
	return false;
}

bool UndoRedo::redo()
{
	if (this->undoRedoIndex < this->undoRedo.size() - 1) {
		this->repo.listOfSecurityRecords = this->undoRedo[++this->undoRedoIndex];
		return true;
	}
	return false;
}


UndoRedo::~UndoRedo()
{
}
