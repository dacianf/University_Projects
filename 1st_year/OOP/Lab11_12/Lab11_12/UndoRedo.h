#pragma once
#include <vector>
#include "domain/SecurityRecord.h"
#include "repository/Repository.h"
class UndoRedo
{
	friend class Repository;
private:
	Repository& repo;
	std::vector< std::vector< SecurityRecord > > undoRedo;
	int undoRedoIndex;
public:
	UndoRedo(Repository&);
	void addBackup(std::vector< SecurityRecord >);
	bool undo();
	bool redo();
	~UndoRedo();
};

