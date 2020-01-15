#pragma once

#include "AbstractCommand.h"
#include <sstream>

enum inputIndex {
	fileIndex = 0, 
	pathIndex = 1
};

class CopyCommand : public AbstractCommand {

public:
	CopyCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string&, std::string) override;
	virtual void displayInfo() override;
	virtual ~CopyCommand() = default;
private:
	AbstractFileSystem* fs;
};
