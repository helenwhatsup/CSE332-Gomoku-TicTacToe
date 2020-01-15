#pragma once

#include "AbstractCommand.h"
#include "ProxyFile.h"
#include <sstream>

enum symIndex {
	symFileIndex = 0,
	symPathIndex = 1
};

class SymCommand : public AbstractCommand {

public:
	SymCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string&, std::string) override;
	virtual void displayInfo() override;
	virtual ~SymCommand() = default;
private:
	AbstractFileSystem* fs;
};
