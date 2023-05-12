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


//
///*
//  Functie folosit in teste
//  primeste vector prin valoare -> copy constructor
//  returneaza prin valoare -> copy constructor sau move constructor
//*/
//template <typename MyVector>
//MyVector testCopyIterate(MyVector v) {
//	double totalPrice = 0;
//	for (auto el : v) {
//		totalPrice += el.get_pret();
//	}
//	Produs p{1, "total","tt","ana",totalPrice};
//	v.push_back(p);
//	return v;
//}
//
//template <typename MyVector>
//void addPets(MyVector& v, int cate) {
//	for (int i = 0; i < cate; i++) {
//		Produs p{1, std::to_string(i) + "_type",std::to_string(i) + "_spec","ana",i + 10.0};
//		v.push_back(p);
//	}
//}
//
///*
//Testare constructori / assignment
//E template pentru a refolosi la diferite variante de VectorDinamic din proiect
//*/
//template <typename MyVector>
//void testCreateCopyAssign() {
//	MyVector v;//default constructor
//	addPets(v, 100);
//	assert(v.size() == 100);
//	assert(v.get(50).get_nume() == "50_type");
//
//	MyVector v2{ v };//constructor de copiere
//	assert(v2.size() == 100);
//	assert(v2.get(50).get_nume() == "50_type");
//
//	MyVector v3;//default constructor
//	v3 = v;//operator=   assignment
//	assert(v3.size() == 100);
//	assert(v3.get(50).get_nume() == "50_type");
//
//	auto v4 = testCopyIterate(v3);
//	assert(v4.size() == 101);
//	assert(v4.get(50).get_nume() == "50_type");
//}
//
///*
//  Test pentru move constructor si move assgnment
//*/
//template <typename MyVector>
//void testMoveConstrAssgnment() {
//	std::vector<MyVector> v;
//	//adaugam un vector care este o variabila temporara
//	//se v-a apela move constructor
//	v.push_back(MyVector{});
//
//	//inseram, la fel se apeleaza move costructor de la vectorul nostru
//	v.insert(v.begin(), MyVector{});
//
//	assert(v.size() == 2);
//
//	MyVector v2;
//	addPets(v2, 50);
//
//	v2 = MyVector{};//move assignment
//
//	assert(v2.size() == 0);
//
//}
//template <typename MyVector>
//void testAll() {
//	testCreateCopyAssign<MyVector>();
//	testMoveConstrAssgnment<MyVector>();
//}
//
//
//int main() {
//	testAll<list<Produs>>();
//
//	_CrtDumpMemoryLeaks();
//	return 0;
//}