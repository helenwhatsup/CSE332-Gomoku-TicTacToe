/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "RemoveCommand.h"
#include "DirectoryFile.h"
#include "ReadFileVisitor.h"
#include <iostream>
#include <sstream>


using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

// removes a file from the current working directory
int RemoveCommand::execute(std::string& CWD, std::string options) {
	bool optioned = false;
	string strr = "-r";
	string fullPath = CWD;
	fullPath += '/';
	if (options.find(strr) != string::npos && options.find(strr)!= 0) {
		options.replace(options.find(strr) - 1, strr.length() + 1, "");
		optioned = true;
	}
	fullPath += options;
	int result = fs->deleteFile(fullPath);
	if (result == AbstractFileSystem::filedoesnotexist) {
		cout << "File does not exist" << endl;
		return filedoesnotexist;
	}
	else if (result == AbstractFileSystem::fileisopen) {
		cout << "File is currently in use" << endl;
		return fileinuse;
	}
	// with option
	if (optioned) {

		if (result == AbstractFileSystem::directorynotempty) {
			string thisDirPath = CWD + '/' + options;
			AbstractFile* f = fs->openFile(thisDirPath);
			ReadFileVisitor reader;
			f->accept(&reader);
			vector<char> contents = f->read();
			fs->closeFile(f);
			stringstream stream;
			int dirCount = 0;
			for (size_t i = 0; i < contents.size(); ++i) {
				stream << contents[i];
			}
			string filename;
			while (stream >> filename) {
				string path = filename + " -r";
				int thisDirCount = RemoveCommand::execute(thisDirPath, path);
				dirCount += thisDirCount;
			}
			int dir = fs->deleteFile(thisDirPath);
			return dirCount;
		}
	}
	// without option
	else {
		if (result == AbstractFileSystem::directorynotempty) {
			cout << "Error: this directory is not empty therefore cannot be deleted!" << endl;
		}
	}
	return success;
}

void RemoveCommand::displayInfo() {
	cout << "touch removes a file from the file system and then deletes the file" << endl;
	cout << "Usage: rm <filename>" << endl;
}
