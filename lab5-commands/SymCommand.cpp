#include "SymCommand.h"

using namespace std;

SymCommand::SymCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int SymCommand::execute(std::string& CWD, std::string options) {
	AbstractFile* f = fs->openFile(CWD);
	if (f == nullptr) { 
		cout << "Error: failed to open directory" << endl;
		fs->closeFile(f);
		return directorydoesnotexist;
	}
	else {
		// parse options
		stringstream s;
		s << options;
		string filenameToProxy;
		string proxyToPath;
		string inputTemp;
		string input[2];
		size_t inputCount = 0;
		while (s >> inputTemp && inputCount != 2) {
			input[inputCount] = inputTemp;
			++inputCount;
		}
		if (inputCount != 2) {
			cout << "Error: filename not loaded!" << endl;
			fs->closeFile(f);
			return inputFailure;
		}
		filenameToProxy = input[symFileIndex];
		proxyToPath = input[symPathIndex];
		proxyToPath += "/";
		cout << "Making proxy of " << filenameToProxy << " to: " << proxyToPath << endl;
		string path = CWD + "/" + filenameToProxy;
		AbstractFile* thisDir = fs->openFile(path);
		if (thisDir == nullptr) {
			cout << "Error: can not open file!" << endl;
			fs->closeFile(thisDir);
			fs->closeFile(f);
			return filedoesnotexist;
		}
		// making proxy on a proxy file
		if (ProxyFile * p = dynamic_cast<ProxyFile*> (thisDir)) {
			ProxyFile* newProxy = new ProxyFile(p);
			int result = fs->addFile(proxyToPath, newProxy);
			if (result == success) {
				fs->closeFile(thisDir);
				fs->closeFile(f);

				cout << "Proxy set!" << endl;
				return success;
			}
		}
		// making proxy on an abstract file
		else {
			AbstractFile* temp = thisDir->clone();
			ProxyFile* thisProxy = new ProxyFile(temp);
			ProxyFile* newProxy = new ProxyFile(thisProxy);
			fs->closeFile(thisDir);
			fs->deleteFile(path);
			int result = fs->addFile(path, thisProxy);
			result += fs->addFile(proxyToPath, newProxy);
			if (result == success) {
				fs->closeFile(thisDir);
				fs->closeFile(f);

				cout << "Proxy set!" << endl;
				return success;
			}
		}
		fs->closeFile(thisDir);
		fs->closeFile(f);
		cout << "Error: failed to sym!" << endl;
		return AbstractCommand::failtosym;
		
		
	}


}

void SymCommand::displayInfo() {
	// Regular sym
	cout << "Make proxy of the current file" << endl;
	cout << "Usage: sym" << endl;
}
