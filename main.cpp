#include <stdlib.h>
#include <stdio.h>

#include "App.h"

int main()
{	
	App app (nullptr); // создание корневого объекта
	app.buildTree();     // конструирование системы, построение дерева объектов
	return app.execApp();         // запуск системы
	
}


