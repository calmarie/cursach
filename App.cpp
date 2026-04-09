#include "App.h"
#include "Cl.h"
#include <string>
#include <iostream>
using namespace std;
	
App::App(Base* parent, string name): Base(parent, name){}

void App::buildTree(){
	string parent, child;
	vector <Base *> created;
	
	cin >> parent;
	setName(parent);
	
	created.push_back(this);
	
	cin >> parent >> child;
	
	while (child!=parent) {
		for (int i=0; i<created.size(); i++){
			if ((created[i]->getName() == parent) && !(created[i]->findName(child))){
				Base* newborn = new Cl(created[i], child);
				//created.insert(created.begin, newborn);
				created.push_back(newborn);
				break;
			}
		
		}
		cin >> parent >> child;
	}	
	cout << getName();
}

int App::execApp(){
	printTree();
	return 0;
}