#include "App.h"
#include "Cl.h"
#include <string>
#include <iostream>
using namespace std;
	
App::App(Base* parent, string name): Base(parent, name){}

void App::buildTree(){
	string parent, child;
	string new_name;
	vector <Base *> created;
	vector <Base *> current_level;
	vector <Base *> next_level;
	int level_number, level_index;
	
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
	cout << getName() << endl;
	printTree();

	cin >> level_number;
	while (level_number != 0){
		cin >> level_index >> new_name;
		current_level.clear();
		current_level.push_back(this);
		for (int i = 1; i < level_number; i++){
			next_level.clear();
			for (int j = 0; j < current_level.size(); j++){
				for (int k = 0; k < current_level[j]->getChildrenCount(); k++){
					next_level.push_back(current_level[j]->getChild(k));
				}
			}
			current_level = next_level;
		}
		if ((level_index > 0) && (level_index <= current_level.size())){
			current_level[level_index - 1]->setName(new_name);
		}
		cin >> level_number;
	}
}

int App::execApp(){
	cout << getName() << endl;
	printTree();
	return 0;
}
