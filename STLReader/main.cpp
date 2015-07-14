#include<iostream>
#include "File.h"
#include "Traingulation.h"
void main()
{
	File f("stl.txt");
	Traingulation t;
	f.read(File::STLFileType::ASCII_STL,t);
	

}