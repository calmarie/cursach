#ifndef __APP__H
#define __APP__H

#include "Base.h"

class App: public Base{
public:
	App(Base* parent, string name = "Base_object");
	void buildTree();
	int execApp();
};

#endif
