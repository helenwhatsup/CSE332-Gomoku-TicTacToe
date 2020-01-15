#include "DisplayCommand.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int DisplayCommand::execute(std::string& CWD, std::string options) {
	string strr = "-d";
	bool optioned = false;
	string fullPath = CWD;
	fullPath += '/';
	if (options.find(strr) != string::npos && options.find(strr) != 0) {
		options.replace(options.find(strr) - 1, strr.length() + 1, "");
		optioned = true;
	}
	fullPath += options;
	cout << fullPath << endl;
	AbstractFile* f = fs->openFile(fullPath);
	if (f == nullptr) {
		cout << "Error: can not open file" << endl;
		fs->closeFile(f);
		return directorydoesnotexist;
	}
	if (optioned) {
		vector<char> contents = f->read();
		for (size_t i = 0; i < contents.size(); ++i) {
			cout << contents[i];
		}
		cout << endl;
		fs->closeFile(f);
		return success;
	}
	else {
		ReadFileVisitor reader;
		f->accept(&reader);
		fs->closeFile(f);
		return success;
	}
	
}

void DisplayCommand::displayInfo() {
	// Regular ds
	cout << "display current file formatted" << endl;
	cout << "Usage: ds" << endl;
	// Detailed ds
	cout << "display current file unformatted" << endl;
	cout << "Usage: ds -d" << endl;
}
