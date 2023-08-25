#include<bits/stdc++.h>
using namespace std;

class FileSystem {
public:
	virtual void ls() = 0;
};

class File: public FileSystem {
public:
	string name;

	File(string name): name(name) {}

	void ls() {
		cout << "File Name: " << name << '\n';
	}
};

class Directory: public FileSystem {
public:
	string name;
	list<FileSystem*> currList;

	Directory(string name) {
		this->name = name;
	}

	void add(FileSystem* currObj) {
		currList.push_back(currObj);
	}

	void ls() {
		cout << "Directory Name: " << name << '\n';
		cout << "start of " << name << " Directory\n";
		for (FileSystem* curr : currList) {
			curr->ls();
		}
		cout << "end of " << name << " Directory\n";
		cout << '\n';
	}
};

int main() {

	Directory* fs = new Directory("Movies");
	Directory* SiFiDirectory = new Directory("SiFi");
	SiFiDirectory->add(new File("Gravity"));
	SiFiDirectory->add(new File("Interstaller"));

	Directory* ThillerDirectory = new Directory("Thiller");
	ThillerDirectory->add(new File("Sherlock"));
	ThillerDirectory->add(new File("Heart of Stone"));

	fs->add(new File("studyMaterial"));
	fs->add(SiFiDirectory);
	fs->add(ThillerDirectory);

	fs->ls();

}