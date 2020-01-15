/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "LSCommand.h"
#include "ReadFileVisitor.h"
#include "ReadMetadataFileVisitor.h"
#include <iostream>
#include <sstream>

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int LSCommand::execute(std::string& CWD, std::string options) {
	AbstractFile* f = fs->openFile(CWD);
	if (f == nullptr) { // file creation failed
		cout << "failed to open directory" << endl;
		return directorydoesnotexist;
	}
	else {
		// with option
		if (options == "-l") {
			ReadMetadataFileVisitor metaReader;
			vector<char> contents = f->read();
			stringstream stream;
			for (size_t i = 0; i < contents.size(); ++i) {
				stream << contents[i];
			}
			string filename;
			while (stream >> filename) {
				string path = CWD + "/" + filename;
				AbstractFile* thisFile = fs->openFile(path);
				thisFile->accept(&metaReader);
				fs->closeFile(thisFile);
			}
			fs->closeFile(f);
		}
		// without option
		else {
			ReadFileVisitor reader;
			f->accept(&reader);
			fs->closeFile(f);		
		}
		return success;
	}

}
void LSCommand::displayInfo() {
	// Regular ls
	cout << "lists the contents of the current directory" << endl;
	cout << "Usage: ls" << endl;
	// Detailed ls
	cout << "detailed lists the contents of the current directory" << endl;
	cout << "Usage: ls -l" << endl;
}