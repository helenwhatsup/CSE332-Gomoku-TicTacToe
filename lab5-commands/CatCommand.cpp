#include "CatCommand.h"

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int CatCommand::execute(std::string& CWD, std::string options) {

	string strr = "-a";
	bool optioned = false;
	string fullPath = CWD;
	fullPath += '/';
	if (options.find(strr) != string::npos && options.find(strr) != 0) {
		options.replace(options.find(strr) - 1, strr.length() + 1, "");
		optioned = true;
	}
	fullPath += options;
	cout << fullPath << endl;
	//cin << options;
	AbstractFile* f = fs->openFile(fullPath);
	string input;
	if (f == nullptr) {
		cout << "Error: can not open file!" << endl;
		return filedoesnotexist;
	}

	else {
		if(DirectoryFile * file = dynamic_cast<DirectoryFile*>(f)) {
			cout << "Error: this file type does not support cat!" << endl;
			fs->closeFile(f);
			return failtocat;
		}
		// cat with append
		if (optioned) {
			vector<char> temp;
			// prompt for input when the file type is txt
			vector<char> before = f->read();
			for (size_t i = 0; i < before.size(); ++i) {
				cout << before.at(i);
			}
			if (ImageFile * file = dynamic_cast<ImageFile*>(f)) {
				cout << endl;
				cout << "Error: this file type does not support append!" << endl;
				fs->closeFile(f);
				return failtocat;
			}
			cout << "Please enter input data for the file and then enter either :q to quit without saving or :wq to quit with saving" << endl;
			while (getline(cin, input)) {

				vector<char> content(input.begin(), input.end());

				//save and quit
				if (input == ":wq") {

					f->append(temp);
					fs->closeFile(f);
					return success;
				}
				//quit, no data saved
				else if (input == ":q") {
					fs->closeFile(f);
					return success;
				}

				for (size_t i = 0; i < content.size(); ++i) {
					temp.push_back(content[i]);
				}
				if (input.size() > 0) {
					temp.push_back('\n');
				}

			}
			return failtocat;

		}

		//cat with replacement
		else {
			vector<char> temp;
			// print original content

			cout << "Please enter input data for the file and then enter either :q to quit without saving or :wq to quit with saving" << endl;
			while (getline(cin, input)) {
				vector<char> content(input.begin(), input.end());
				//save and quit
				if (input == ":wq") {

					f->write(temp);
					fs->closeFile(f);
					return success;
				}
				//quit, no data saved
				else if (input == ":q") {
					fs->closeFile(f);
					return success;
				}
				for (size_t i = 0; i < content.size(); ++i) {
					temp.push_back(content[i]);
				}
				if (TextFile * file = dynamic_cast<TextFile*>(f)) {
					temp.push_back('\n'); //reinsert newline character
				}
			}
			return failtocat;
		}
	}

}

void CatCommand::CatCommand::displayInfo() {
	// Regular cat
	cout << "concatenate current file" << endl;
	cout << "Usage: cat" << endl;
	// Detailed cat
	cout << "show current content of the file and concatenate current file with append" << endl;
	cout << "Usage: cat -a" << endl;
}
