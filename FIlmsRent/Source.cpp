#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <ctime>
#include "Auth.h"
#include "Class.h"
#include "DB.h"
using namespace std;

FilmDB& fDB = FilmDB::getInstance();
OrderDB& oDB = OrderDB::getInstance();
RentDB& rDB = RentDB::getInstance();
BlackListDB& blDB = BlackListDB::getInstance();
ProducerDB& pDB = ProducerDB::getInstance();
BuyerDB& bDB = BuyerDB::getInstance();
SellerDB& sDB = SellerDB::getInstance();

Rent::Rent(Buyer& buyer, DATE date)
{
	Producer p; string name, type;
	int count; double price;
	cout << "Enter film name: "; getline(cin, name);
	cout << "Enter count of films: "; cin >> count;
	cout << "Enter type of disk: ";	getchar(); getline(cin, type);
	cout << "Enter price of type: "; cin >> price;
	this->buyer = &buyer;
	this->film = p.makeFilm(name, count, type, price);
	fDB.write(*film);
	this->price = film->getPrice();
}
void VipBuyer::makeOrder()
{
	while (true)
	{
		char ch;
		cout << "Are you want to add yet?\n";
		cin >> ch;
		if (tolower(ch) == 'n')
			break;
		DATE date = 0;
		Rent r(*this, date);
		rent.push_back(r);
	}
	for (Rent item : rent)
		oDB.write(item);
}
Seller::Seller(string name, string tel, string address) { this->name = name; this->tel = tel; this->address = address; sDB.write(*this); }
void Seller::setRent(Buyer& buyer, Film* film) { DATE date = 0; Rent r; if (film == NULL) r = Rent(buyer, date); else r.setPrice(buyer, date, film); rDB.write(r); }
void Seller::getRent(Rent& rent) { if (!rent.isSafe()) { fDB.del(rent.getFilm()); } rDB.del(rent); }
bool Seller::findFilm(string filmName) { if (fDB.read(filmName)) { cout << "Film is founded!\n"; return true; } else { cout << "Film isn`t founded!\n"; return false; } }
void Seller::addProducer(Producer& producer) { pDB.write(producer); }
void Seller::delProducer(Producer& producer) { pDB.del(producer); }
void Seller::readProducer() { pDB.read(); }
void Seller::writeBuyer(Buyer& buyer) { bDB.write(buyer); }
void Seller::readBuyer() { bDB.read(); }
void Seller::writeRent(Rent& rent) { rDB.write(rent); }
void Seller::readRent() { rDB.read(); }
void Seller::delRent(Rent& rent) { rDB.del(rent); }
void Seller::writeBlackList(Buyer& buyer) { blDB.write(buyer); }
void Seller::readBlackList() { blDB.read(); }
void Seller::readOrder() { oDB.read(); }
void Seller::doOrder() { Rent r = *oDB.getOrder(); oDB.del(r); }
void main()

{
	srand(time(0));
	Buyer b("Danylo", "Kolomiets", "3945015", "DEfwrger", true);
	Buyer b1("EFwgre", "Bfbd", "3425", "ZVCB", false);
	Seller s("Igor", "134546542", "Nigegn");
	s.writeBuyer(b);
	s.writeBuyer(b1);
	s.readBuyer();
	s.setRent(b);
	s.readRent();
	system("pause");
}