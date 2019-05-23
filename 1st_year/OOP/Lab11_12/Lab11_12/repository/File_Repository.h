#pragma once
#include "Repository.h"
#include <fstream>
#include <algorithm>

class File_Repository :
	public Repository
{
protected:
	std::string fileLocation;
	std::string fileExtension;
	std::ifstream fin;
	std::ofstream fout;
public:
	File_Repository() {};
	File_Repository(const File_Repository& copyOfRepository) {
		this->fileLocation = copyOfRepository.fileLocation;
		this->fileExtension = copyOfRepository.fileExtension;
		this->listOfSecurityRecords = copyOfRepository.listOfSecurityRecords;
	};
	File_Repository(std::string fileLocation) : Repository() {
		this->fileLocation = fileLocation;
		for (int i = fileLocation.size() - 1; i >= 0; i--) {
			if (fileLocation[i] == '.')
				break;
			this->fileExtension.push_back(fileLocation[i]);
		}
		reverse(this->fileExtension.begin(), this->fileExtension.end());
		this->loadRepository();
	};
	bool loadRepository() override{
		this->fin.open(this->fileLocation, std::fstream::in | std::fstream::out);
		auto readRecord = SecurityRecord();
		if(fin)
			while (this->fin >> readRecord)
				this->addRecord(readRecord);
		this->fin.close();
		return true;
	}
	void setPath(const std::string path) override {
		this->fileLocation = path;
		for (int i = fileLocation.size() - 1; i >= 0; i--) {
			if (fileLocation[i] == '.')break;
			this->fileExtension.push_back(fileLocation[i]);
		}
	}
	bool saveRepository() override{
		if (this->fileLocation != "") {
			this->fout.open(this->fileLocation, std::fstream::out);
			if (this->fileExtension == "txt" || this->fileExtension == "csv")
				for (int i = 0; i < this->listOfSecurityRecords.size(); i++)
					fout << this->listOfSecurityRecords[i] << "\n";
			else if (this->fileExtension == "html") {
				 fout << "<!DOCTYPE html>\n"
					 "<html>\n"
					 "<head>\n"
					 "\t<title>Security Records</title>\n"
					 "</head>\n"
					 "<body>\n"
					 "\t<table border=\"1\">\n"
					 "\t\t<tr>\n"
					 "\t\t\t<td>Title</td>\n"
					 "\t\t\t<td>Location</td>\n"
					 "\t\t\t<td>Time of creation</td>\n"
					 "\t\t\t<td>Number of accessings</td>\n"
					 "\t\t\t<td>Footage preview</td>\n"
					 "\t\t</tr>\n";
				for (auto record:this->listOfSecurityRecords)
					fout << "\t\t<tr>\n"
					"\t\t\t<td>"
					<< record.getTitle() << "</td>\n\t\t\t<td>" << record.getLocation()
					<< "</td>\n\t\t\t<td>" << record.getTimeOfCreation() << "</td>\n\t\t\t<td>"
					<< record.getNumberOfAccessing() << "</td>\n\t\t\t<td><a = href=\""
					<< record.getFootagePreview() << "\">Link</a></td>\n\t\t</tr>\n";
				fout << "\t</table>\n</body>\n</html>\n";
			}
			else { return false; }
			this->fout.close();
			return true;
		}
		return false;
	}
	File_Repository operator =(File_Repository assignedRepository) {
		this->fileLocation = assignedRepository.fileLocation;
		this->listOfSecurityRecords = assignedRepository.listOfSecurityRecords;
		return *this;
	}
	~File_Repository() { this->saveRepository(); };
};

