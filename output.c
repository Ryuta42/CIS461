#include <stdio.h>
#include <stdlib.h>

#include "Builtins.h"

void quackmain();

int main(int argc, char** argv) {
	quackmain();
	printf("--- Terminated successfully ---\n");
	exit(0);
}
void quackmain() {
	obj_Pt p1;
	obj_Pt p2;
	obj_Pt p3;
	p1 = -;
	p2 = -;
	p3 = p1->clazz->PLUS();
	p3 = p1->clazz->PLUS();
	c->clazz->PRINT((obj_Obj) c);
}
