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
	(int_literal(5));
	c->clazz->PRINT((obj_Obj) c);
}
