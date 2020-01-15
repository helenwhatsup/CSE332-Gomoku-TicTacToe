#pragma once

#include "AbstractCommand.h"
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "ReadFileVisitor.h"
#include "HierarchicalFileSystem.h"
#include<iostream>
#include<sstream>
#include<vector>

class DisplayCommand : public AbstractCommand {

public:
	DisplayCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~DisplayCommand() = default;
private:
	AbstractFileSystem* fs;
};
