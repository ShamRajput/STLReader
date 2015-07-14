#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <array>

class Traingulation;
class File
{
public:
	enum class STLFileType
	{
		BINARY_STL,
		ASCII_STL
	};

public:
	File(std::string inFileName);
	~File();
public:
	int fileLength();
	int lineCount();

public:
	Traingulation& read(File::STLFileType inSTLFileType, Traingulation& inTraingulation) ;

protected:
	void printAllData(std::vector<std::string>& x, std::array<char, 1> delimiter);

private:
	void processSTLBlock(std::vector<std::string>& inBlock, Traingulation& inTraingulation);
private:
	std::string mFileName;
	std::fstream mFile;
};

