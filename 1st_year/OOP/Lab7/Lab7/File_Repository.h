#pragma once
#include "Repository.h"
#include <fstream>

class File_Repository :
	public Repository
{
private:
	std::string fileLocation;
	std::ifstream fin;
	std::ofstream fout;
public:
	File_Repository() {};
	File_Repository(const File_Repository& copyOfRepository) {
		this->fileLocation = copyOfRepository.fileLocation;
		this->listOfSecurityRecords = copyOfRepository.listOfSecurityRecords;
	};
	File_Repository(std::string fileLocation) : Repository() {
		this->fileLocation = fileLocation; 
		this->loadFromFile(this->fileLocation);
	};
	void loadFromFile(std::string fileLocation) {
		this->fin.open(fileLocation, std::fstream::out);
		auto readRecord = SecurityRecord();
		while (this->fin >> readRecord)
			this->addRecord(readRecord);
		this->fin.close();
	}

	void saveInFile() {
		this->fout.open(this->fileLocation, std::fstream::out);
		for (int i = 0; i < this->listOfSecurityRecords.size(); i++)
			fout << this->listOfSecurityRecords[i] << "\n";
		this->fout.close();
	}
	File_Repository operator =(File_Repository assignedRepository) {
		this->fileLocation = assignedRepository.fileLocation;
		this->listOfSecurityRecords = assignedRepository.listOfSecurityRecords;
		return *this;
	}
	~File_Repository() {};
};

