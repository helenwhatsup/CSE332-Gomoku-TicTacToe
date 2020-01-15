#include "ProxyFile.h"
#include<iostream>

using namespace std;

ProxyFile::ProxyFile(ProxyFile* file) {
	
		count = file->count;
		++*count;
		realFile = file->realFile;
		parent = nullptr;

}

ProxyFile::ProxyFile(AbstractFile* file) {

	count = new int(1);
	parent = file->getParent();
	file->setParent(nullptr);
	realFile = file;

}

unsigned int ProxyFile::getSize() {
	return realFile->getSize();
}

string ProxyFile::getName() {
	return realFile->getName();
}

vector<char> ProxyFile::read() {
	return realFile->read();
}

void ProxyFile::accept(AbstractFileVisitor* fv) {

	if (fv) {
		realFile->accept(fv);
	}

}

int ProxyFile::write(vector<char> data) {

	return realFile->write(data);
}

int ProxyFile::append(vector<char> data) {

	return realFile->append(data);
}

AbstractFile* ProxyFile::clone() {
	return realFile->clone();
}

int ProxyFile::addChild(AbstractFile* file) {
	return notacomposite;
}

int ProxyFile::removeChild(string name) {
	return realFile->removeChild(name);
}

AbstractFile* ProxyFile::getChild(std::string name) {
	return nullptr;
}

AbstractFile* ProxyFile::getParent() {
	return parent;
}

void ProxyFile::setParent(AbstractFile* p) {
	parent = p;

}

ProxyFile::~ProxyFile() {
	if (*count == 1) {
		delete count;
		delete realFile;
	}
	else {
		--*count;
	}
}