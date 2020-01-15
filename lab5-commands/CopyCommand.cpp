#include "CopyCommand.h"

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int CopyCommand::execute(std::string& CWD, std::string options) {
	AbstractFile* f = fs->openFile(CWD);
	if (f == nullptr) { // file creation failed
		cout << "Error: failed to open directory" << endl;
		fs->closeFile(f);
		return directorydoesnotexist;
	}
	else {
		stringstream s;
		s << options;
		string filenameToCopy;
		string copyToPath;
		string inputTemp;
		string input[2];
		size_t inputCount = 0;
		while (s >> inputTemp && inputCount != 2) {
			input[inputCount] = inputTemp;
			++inputCount;
		}
		// check two strings are passsed in as options
		if (inputCount != 2) {
			cout << "Error: filename not loaded!" << endl;
			fs->closeFile(f);
			return inputFailure;
		}
		filenameToCopy = input[fileIndex];
		copyToPath = input[pathIndex];
		copyToPath += "/";
		cout << "Copying " << filenameToCopy << " to: " << copyToPath << endl;
		string path = CWD + "/" + filenameToCopy;
		AbstractFile* thisDir = fs->openFile(path);
		if (thisDir == nullptr) {
			cout << "Error: can not open file!" << endl;
			fs->closeFile(thisDir);
			fs->closeFile(f);
			return filedoesnotexist;
		}
		AbstractFile* fileToCopy = thisDir->clone();
		int result = fs->addFile(copyToPath, fileToCopy);
		if (result != success) {
			cout << "Error: failed to add file to file system!" << endl;
			fs->closeFile(thisDir);
			fs->closeFile(f);
			return failedtoadd;
		}
		else {
			cout << "Copied!" << endl;
		}

		fs->closeFile(thisDir);
		fs->closeFile(f);
		
		
		return success;
	}


}

void CopyCommand::displayInfo() {
	// Regular cp
	cout << "copy current file" << endl;
	cout << "Usage: cp" << endl;
}
