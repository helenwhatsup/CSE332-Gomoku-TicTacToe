#pragma once

#include "AbstractFile.h"
#include "AbstractFileVisitor.h"
#include "DirectoryFile.h"
#include "ImageFile.h"
#include "TextFile.h"
#include <vector>	

class ProxyFile : public AbstractFile {
	//friends
	friend class SimpleFileSystem;
	friend class HierarchicalFileSystem;
public:
	ProxyFile(ProxyFile*);
	ProxyFile(AbstractFile*);
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual AbstractFile* clone();

	virtual ~ProxyFile();

	virtual void accept(AbstractFileVisitor*) override;

protected:
	virtual int addChild(AbstractFile*) override;
	virtual int removeChild(std::string name) override;
	virtual void setParent(AbstractFile*) override;
	virtual AbstractFile* getChild(std::string name) override;
	virtual AbstractFile* getParent() override;
	

private:
	std::vector<char> contents;
	std::string name;
	AbstractFile* parent;
	int* count; 
	AbstractFile* realFile;
};
