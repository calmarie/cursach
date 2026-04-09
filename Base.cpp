#include "Base.h"

Base::Base(Base* parent, string name){
	this->parent = parent;
	this->name = name;
}


bool Base::setName(string name){
	if (parent){
		for (int i = 0; i < parent->getChildrenCount(); i++){
			Base* child = parent->getChild(i);
			if (child->getName() == name){
				return 0;
			}
				
		}
	}
	this->name = name;
	return 1;
	
}


string Base::getName(){
	return name;
}


Base* Base::getParent(){
	return parent;
}


int Base::getChildrenCount(){
	return children.size();
}

void Base::printTree(){
	if (getChildrenCount() == 0){
		return;
	}
	cout << name << endl;
	for (int i = 0; i<getChildrenCount(); i++){
		cout << "  " << children[i]->getName();
	}
	children.back()->printTree();
	
}


Base* Base::getChild(int idx){
	return children[idx];
}
Base::~Base(){
	for (int i = 0; i < getChildrenCount(); i++){
		delete children[i];
	}
}

Base* Base::findName(string name){
	for (int i = 0; i<getChildrenCount(); i++){
		if (children[i]->getName() == name){
			return children[i];
		}
		
	} 
	return nullptr;
}