#ifndef __BASE__H
#define __BASE__H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base{
	string name;
	Base* parent;
	vector <Base*> children;
public:
	Base(Base* parent, string name = "Base_object");
	bool setName(string name);
	string getName();
	Base* getParent();
	int getChildrenCount();
	void printTree();
	Base* findName(string name);
	Base* getChild(int idx);
	~Base();
	
	
};

#endif
