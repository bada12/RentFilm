#ifndef CLASSES
#define CLASSES
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;
class FilmType
{
private:
	string name;
	double price;
public:
	void setType(string name, double price) { this->name = name; this->price = price; }
	double getPrice() { return this->price; }
	FilmType() { this->name = "unknow"; this->price = -10; }
	FilmType(string name, double price) { this->name = name; this->price = price; }
	friend ostream& operator<<(ostream &os, const FilmType& ftype)
	{
		os << "Type: " << ftype.name << endl << "Price of type: " << ftype.price << endl;
		return os;
	}
	bool operator==(const FilmType& ft) { if (this->name == ft.name && this->price == ft.price) return true; else return false; }
};
class Film
{
private:
	string name;
	double price;
	int count;
	FilmType type;
public:
	Film() {}
	string getName() { return this->name; }
	double getPrice() { return price; }
	Film(string name, int count, string name1, double price) :type(name1, price) { this->name = name; ; this->count = count; this->price = type.getPrice()*count; }
	friend ostream& operator<<(ostream &os, const Film& film)
	{
		os << "Name: " << film.name << endl << "Amount: " << film.count << endl
			<< film.type << endl;
		return os;
	}
	bool operator==(const Film& f) { if (this->name == f.name && this->type == f.type) return true; else return false; }
};
class AUser
{
protected:
	string name;
	string tel;
	string address;
public:
	virtual void getPersonalData() = 0;
};
class Buyer : public AUser
{
protected:
	string surname;
	bool state;
public:
	virtual void getPersonalData() override
	{
		cout << "Name: " << name << endl << "Surname: " << surname << endl << "Tel: " << tel << endl
			<< "Address: " << address << endl << "State: " << state << endl;
	}
	Buyer() { name = "unknow"; tel = "unknow"; address = "unknow"; surname = "unknow"; state = true; }
	Buyer(string name, string surname, string tel, string address, bool state) { this->name = name; this->surname = surname;  this->tel = tel; this->address = address; this->state = state; }
	void auth(Authorization au) { au.doAuth(); }
	void getSMS(string mess) { cout << mess << endl; }
	friend ostream& operator<<(ostream &os, const Buyer& buyer)
	{
		os << "Name: " << buyer.name << endl << "Surname: " << buyer.surname << endl << "Tel: " << buyer.tel << endl
			<< "Address: " << buyer.address << endl << "State: " << buyer.state << endl;
		return os;
	}
	bool operator==(const Buyer& b) { if (this->name == b.name && this->surname == b.surname) return true; else return false; }
};
class Producer : public AUser
{
public:
	virtual void getPersonalData() override
	{
		cout << "Name: " << name << endl << "Tel: " << tel << endl << "Address: " << address << endl;
	}
	Producer() { name = "unknow"; tel = "unknow"; address = "unknow"; }
	Producer(string name, string tel, string address) { this->name = name; this->tel = tel; this->address = address; }
	Film* makeFilm(string name, int count, string name1, double price) { return new Film(name, count, name1, price); }
	friend ostream& operator<<(ostream &os, const Producer& producer)
	{
		os << "Name: " << producer.name << endl << "Tel: " << producer.tel << endl
			<< "Address: " << producer.address << endl;
		return os;
	}
	bool operator==(const Producer& p) { if (this->name == p.name && this->tel == p.tel && this->address == p.address) return true; else return false; }
};
class Rent
{
private:
	DATE data;
	Film* film;
	Buyer* buyer;
	double price;
	DATE setDataRet;
	DATE factDataRet;
public:
	Rent() {}
	Rent(Buyer& buyer, DATE date);
	void setPrice(Buyer& buyer, DATE date, Film* film = 0) {}
	double getPrice() { return price; }
	Film& getFilm() { return *film; }
	void setFine() { price *= 10; }
	void sendSMS(string mess) { buyer->getSMS(mess); }
	bool isSafe() { if (rand() % 10)return false; return false; }
	friend ostream& operator<<(ostream &os, const Rent& rent)
	{
		os << "Buyer information: \n" << *rent.buyer << "Date: " << rent.data << endl << "Film information: " << *rent.film
			<< "When must return: " << rent.setDataRet << endl << "When fact return: " << rent.factDataRet << endl;
		return os;
	}
	bool operator==(const Rent& r) { if (this->buyer == r.buyer && this->film == r.film) return true; else return false; }
};
class VipBuyer :public Buyer
{
private:
	vector<Rent>rent;
public:
	VipBuyer() {}
	VipBuyer(string name, string surname, string tel, string address, bool state) { this->name = name; this->surname = surname;  this->tel = tel; this->address = address; this->state = state; }
	void makeOrder();
};
class Seller : public AUser
{
public:
	virtual void getPersonalData() override
	{
		cout << "Name: " << name << endl << "Tel: " << tel << endl << "Address: " << address << endl;
	}
	Seller() { name = "unknow"; tel = "unknow"; address = "unknow"; }
	Seller(string name, string tel, string address);
	void setRent(Buyer& buyer, Film* film = 0);
	void getRent(Rent& rent);
	bool findFilm(string filmName);
	void addProducer(Producer& producer);
	void delProducer(Producer& producer);
	void readProducer();
	void writeBuyer(Buyer& buyer);
	void readBuyer();
	void writeRent(Rent& rent);
	void readRent();
	void delRent(Rent& rent);
	void writeBlackList(Buyer& buyer);
	void readBlackList();
	void readOrder();
	void doOrder();
	void auth(Authorization au) { au.doAuth(); }
	friend ostream& operator<<(ostream &os, const Seller& seller)
	{
		os << "Name: " << seller.name << endl << "Tel: " << seller.tel << endl
			<< "Address: " << seller.address << endl;
		return os;
	}
	bool operator==(const Seller& s) { if (this->name == s.name && this->tel == s.tel && this->address == s.address) return true; else return false; }
};
#endif