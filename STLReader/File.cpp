
#include "File.h"
#include "Traingulation.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <omp.h>

template <typename E, typename C>

size_t split(std::basic_string<E> const& s,
	C &container,
	E const delimiter,
	bool keepBlankFields = true)
{
	size_t n = 0;
	std::basic_string<E>::const_iterator it = s.begin(), end = s.end(), first;
	for (first = it; it != end; ++it)
	{
		// Examine each character and if it matches the delimiter
		if (delimiter == *it)
		{
			if (keepBlankFields || first != it)
			{
				// extract the current field from the string and
				// append the current field to the given container
				container.push_back(std::basic_string<E>(first, it));
				++n;

				// skip the delimiter
				first = it + 1;
			}
			else
			{
				++first;
			}
		}
	}
	if (keepBlankFields || first != it)
	{
		// extract the last field from the string and
		// append the last field to the given container
		container.push_back(std::basic_string<E>(first, it));
		++n;
	}
	return n;
}



File::File(std::string inFileName) :mFileName(inFileName)
{
	if (!mFile.is_open())
		mFile.open(mFileName.c_str(), std::ios_base::in);
}


File::~File()
{

}


Traingulation&  File::read(File::STLFileType /*inSTLFileType*/ ,Traingulation& inTraingulation) 
{
	std::string data;
	//Seeking File Pointer to get file length
	int length = fileLength();
	data.resize(length);
	
	//Whole file Reading operation 
	mFile.read(const_cast<char*>(data.c_str()), length);
	
	
	std::array<char, 1> delimiter = {'\n'};
	std::vector<std::string> x;
	//Split String as per delimiter
	split(data, x, delimiter[0], true);

	printAllData(x, delimiter);
	int bc = x.size() / 10;

	for (auto i = 0; i <bc; ++i)
		processSTLBlock(x, inTraingulation);
	return inTraingulation;
}



int File::fileLength()
{
	int length = 0;
	mFile.seekg(0, mFile.end);
	length = static_cast<int>(mFile.tellg());
	mFile.seekg(0, mFile.beg);
	return length;
}

int File::lineCount()
{
	return static_cast<int>((std::count(std::istreambuf_iterator<char>(mFile),
		std::istreambuf_iterator<char>(), '\n')));
}

void File::printAllData(std::vector<std::string>& x, std::array<char, 1> delimiter)
{
	std::copy(x.begin(), x.end(),
		std::ostream_iterator<std::string>(std::cout, delimiter.data()));
	std::cout << std::endl;
}

void File::processSTLBlock(std::vector<std::string>& inBlock, Traingulation& inTraingulation)
{
	std::vector<std::string> data;
	std::array<char, 1> delimiter = { ' ' };

	std::vector<double> normal;
	//std::vector<double> vertices;

	split(inBlock[0], data, delimiter[0], false);
	if (0 != data.at(0).compare("Solid"))
		return;
	data.clear();
	split(inBlock[1], data, delimiter[0], false);
	
	normal.push_back(std::atof(data.at(2).c_str()));
	normal.push_back(std::atof(data.at(3).c_str()));
	normal.push_back(std::atof(data.at(4).c_str()));

	data.clear();
	split(inBlock[3], data, delimiter[0], false);
	if (0 != data.at(0).compare("vertex"))
		return;

	.push_back(std::atof(data.at(1).c_str()));
	vertices.push_back(std::atof(data.at(2).c_str()));
	vertices.push_back(std::atof(data.at(3).c_str()));
	data.clear();




}

