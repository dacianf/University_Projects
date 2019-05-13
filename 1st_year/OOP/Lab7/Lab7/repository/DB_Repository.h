#pragma once
#include "../repository/File_Repository.h"
#include <sqlite3.h>

class DB_Repository :
	public File_Repository
{
private:
	
	sqlite3* database{};
	bool loadRepository() override;
	bool saveRepository() override;
public:
	explicit DB_Repository(const std::string& path);
	~DB_Repository();
};

