#include "ui.h"
#include "tests.h"
#include <assert.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> 
#include "Lista.h"
#include "shopping_cart.h"
#include "file_repository.h"

void run_tests() {
	Tests tests;
	tests.run_all_tests();
}

void run_app() {
	Validator val;
	Repository MemoryRepo;
	FileRepository FileRepo{ "products.txt" };
	Cart cart;
	Service service{ FileRepo, val, cart };
	UI console {service};

	console.runUI();
}


int main() {
	run_tests();
	run_app();
	_CrtDumpMemoryLeaks();
	return 0;
}