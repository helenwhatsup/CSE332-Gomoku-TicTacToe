#pragma once

#include "AbstractCommand.h"
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "DirectoryFile.h"
#include "HierarchicalFileSystem.h"
#include<iostream>
#include<sstream>
#include<vector>

class CatCommand : public AbstractCommand {
	enum catEnum {
		failWrite,
		failAppend
	};

public:
	CatCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~CatCommand() = default;
private:
	AbstractFileSystem* fs;
};
