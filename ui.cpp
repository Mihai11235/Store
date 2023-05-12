#include "ui.h"

using std::getline;
using std::ws;

using std::cout;
using std::cin;

using std::numeric_limits;
using std::streamsize;

using std::pair;


void UI::runUI(){
	//populare_ui();
	string comanda;
	
	while (1) {
		system("cls");
		print_comenzi_ui();
		cout << "Introduceti comanda: ";
		cin >> comanda;
		if (comanda == "x")
			return;

		if (comenzi.count(comanda))
			try {
			(this->*comenzi[comanda])();
			}
			catch(ValidationError& ve){
				cout << "ValidationError: " << string(ve) << '\n';
			}
			catch (RepoError re) {
				cout << "RepoError: " << string(re) << '\n';
			}
			catch (CartError ce) {
				cout << "SartError: " << string(ce) << '\n';
			}
			catch (const string& s) {
				cout << s << '\n';
			}
		else
			cout << "Comanda invalida!\n";

		cout << "Pretul total al produselor din cos este " << service.get_pret_total_cart_service() << "\n";
		system("pause");
	}
}

void UI::read_id(int& id) const{
	cout << "Introduceti identificatorul unic: ";
	cin >> id;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw string("Identificatorul unic trebuie sa fie intreg!\n");
	}
}

void UI::read_nume(string& nume) const {
	cout << "Introduceti numele: ";
	getline(cin >> ws, nume);
}

void UI::read_tip(string& tip) const {
	cout << "Introduceti tipul: ";
	getline(cin >> ws, tip);
}

void UI::read_producator(string& producator) const {
	cout << "Introduceti producatorul: ";
	getline(cin >> ws, producator);
}

void UI::read_pret(double& pret) const {
	cout << "Introduceti pretul: ";
	cin >> pret;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw string("Pretul trebuie sa fie un numar real!\n");
	}
}

void UI::print_comenzi_ui(){
	cout << " 1. Afiseaza produse\n";
	cout << " 2. Adauga produs\n";
	cout << " 3. Sterge produs\n";
	cout << " 4. Modifica produs\n";
	cout << " 5. Cauta produs\n";
	cout << " 6. Filtreaza produse\n";
	cout << " 7. Sorteaza produse\n";
	cout << " 8. Adauga produs in cos dupa nume\n";
	cout << " 9. Goleste cos\n";
	cout << "10. Genereaza produse aleator in cos\n";
	cout << "11. Genereaza dictionar in functie de pret\n";
	cout << "12. Export cos in fisier\n";
	cout << "13. Undo\n";
	cout << " x. Exit\n";
}

void UI::afiseaza_produse_ui(){
	const vector<Produs>& produse = service.get_all_service();
	if (produse.size() == 0) {
		cout << "Nu exista produse in lista!\n";
		return;
	}
	for (const Produs& p : produse)
		cout << p << '\n';
}

void UI::adauga_ui(){
	int id; string nume, tip, producator; double pret;
	read_id(id);
	read_nume(nume);
	read_tip(tip);
	read_producator(producator);
	read_pret(pret);

	service.adauga_service(id, nume, tip, producator, pret);
}

void UI::modifica_ui(){
	int id; string nume, tip, producator; double pret;
	read_id(id);
	read_nume(nume);
	read_tip(tip);
	read_producator(producator);
	read_pret(pret);

	service.modifica_service(id, nume, tip, producator, pret);
}

void UI::sterge_ui(){
	int id;
	read_id(id);

	service.sterge_service(id);
}

void UI::cauta_ui(){
	int id;
	read_id(id);

	cout<<service.cauta_service(id);
}

void UI::filtreaza_ui() {
	cout << "Introduceti criteriul de filtrare (pret/nume/producator): ";
	string criteriu; cin >> criteriu;

	if (criteriu == "pret") {
		cout << "Introduceti pretul: ";
		double pret; read_pret(pret);
		print_ui(service.filtreaza_pret_service(pret));
	}
	
	if (criteriu == "nume") {
		cout << "Introduceti numele: ";
		string nume; read_nume(nume);
		print_ui(service.filtreaza_nume_service(nume));
	}
	
	if (criteriu == "producator") {
		cout << "Introduceti producatorul: ";
		string producator; read_producator(producator);
		print_ui(service.filtreaza_producator_service(producator));
	}
}

void UI::sorteaza_ui() {
	cout << "Introduceti criteriul de filtrare (nume/pret/nume+tip): ";
	string criteriu; cin >> criteriu;

	if (criteriu == "nume")
		print_ui(service.sort_nume());
	
	if (criteriu == "pret")
		print_ui(service.sort_pret());
	
	if (criteriu == "nume+tip")
		print_ui(service.sort_nume_tip());
	
}

void UI::adauga_in_cos_ui()
{
	string nume;
	read_nume(nume);
	service.adauga_cart_service(nume);
}

void UI::goleste_cos_ui()
{
	service.goleste_cart_service();
}

void UI::genereaza_cart_ui()
{
	cout << "Introduceti numerul de elemente care doriti sa fie generate: ";
	int nrElems; cin >> nrElems;
	service.genereaza_cart_service(nrElems);
}

void UI::populare_ui()
{
	service.adauga_service(1, "Twix", "alimentar", "ProdTwix", 4.5);
	service.adauga_service(2, "Snickers", "alimentar", "ProdSnickers", 5);
	service.adauga_service(3, "Mars", "alimentar", "ProdMars", 4);
	service.adauga_service(4, "Alfers", "alimentar", "ProdAlfers", 7);
	service.adauga_service(5, "Kinder", "alimentar", "ProdKinder", 3.5);
	service.adauga_service(6, "Pantofi", "nealimentar", "Adidas", 100);
	service.adauga_service(7, "Danone", "alimentar", "ProdDanone", 2);
	service.adauga_service(8, "Faina", "alimentar", "Boromir", 5);
	service.adauga_service(9, "Malai", "alimentar", "Boromir", 6);
	service.adauga_service(10, "Sosete", "alimentar", "Nike", 4);
}

void UI::genereaza_dictionar_pret_ui()
{
	unordered_map<double, vector<Produs>> map = service.genereaza_dictionar_pret_service();
	for (const pair<double, vector<Produs>>& p : map) {
		cout << p.first << " : ";
		for (const Produs& x : p.second) {
			cout << x << " , ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void UI::export_cart_ui()
{
	string file;
	cout << "Introduceti numele fisierului: ";
	cin >> file;

	service.export_cart_service(file);
}

void UI::undo_ui(){
	service.undo_service();
}

void UI::print_ui(const vector<Produs>& list) {
	if (list.size() == 0) {
		cout << "Nu exista produse in lista!\n";
		return;
	}
	for (const Produs& p : list)
		cout << p << '\n';
}