#pragma once
#include "service.h"
#include <unordered_map>
#include <iostream>
#include <limits>

//map of UI Methods to be called
using std::unordered_map;

class UI;

//UIMethod type
typedef void(UI::* UIMethod)();

class UI {
private:
	Service& service;
	
	unordered_map<string, UIMethod> comenzi = {
		{"1", &UI::afiseaza_produse_ui},
		{"2", &UI::adauga_ui},
		{"3", &UI::sterge_ui},
		{"4", &UI::modifica_ui},
		{"5", &UI::cauta_ui},
		{"6", &UI::filtreaza_ui},
		{"7", &UI::sorteaza_ui},
		{"8", &UI::adauga_in_cos_ui},
		{"9", &UI::goleste_cos_ui},
		{"10", &UI::genereaza_cart_ui},
		{"11", &UI::genereaza_dictionar_pret_ui},
		{"12", &UI::export_cart_ui},
		{"13", &UI::undo_ui}
	};

	void read_id(int&) const;
	void read_nume(string&) const;
	void read_tip(string&) const;
	void read_producator(string&) const;
	void read_pret(double&) const;

	void print_comenzi_ui();
	void print_ui(const vector<Produs>&);

	void afiseaza_produse_ui();
	void adauga_ui();
	void modifica_ui();
	void sterge_ui();
	void cauta_ui();
	void filtreaza_ui();
	void sorteaza_ui();
	void adauga_in_cos_ui();
	void goleste_cos_ui();
	void genereaza_cart_ui();
	void populare_ui();
	void genereaza_dictionar_pret_ui();
	void export_cart_ui();
	void undo_ui();
public:
	UI(Service& service) :service{ service } {};
	UI(const UI& u) = delete;
	void runUI();

};
