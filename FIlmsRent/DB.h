#ifndef DB
#define DB
#include "Class.h"
using namespace std;
template<class T>
void fileWrite(const char* fname, T p)
{
	FILE *fp;
	T* t = new T();
	if (fopen_s(&fp, fname, "a+") == 0)
	{
		while (true)
		{
			fread(t, sizeof(T), 1, fp);
			if (feof(fp))
				break;
			if (*t == p)
			{
				fclose(fp);
				return;
			}
		}
		fwrite(&p, 1, sizeof(T), fp);
		fclose(fp);
	}
}
template<class T>
void fileDel(const char* fname, T& t)
{
	FILE *fp;
	T* p = new T();
	int size;
	T *mas = NULL;
	if (fopen_s(&fp, fname, "r") == 0)
	{
		fseek(fp, 0, SEEK_END);
		size = ftell(fp) / sizeof(T) - 1;
		fseek(fp, 0, SEEK_SET);
		mas = new T[size];
		for (int i = 0, k = 0; i <= size; i++)
		{
			fread(p, sizeof(T), 1, fp);
			if (feof(fp))
				break;
			if (t == *p)
				continue;
			mas[k++] = *p;
		}
		fclose(fp);
	}
	if (fopen_s(&fp, fname, "w") == 0)
	{
		for (int i = 0; i < size; i++)
			fwrite(&mas[i], 1, sizeof(T), fp);
		fclose(fp);
	}
}
class FilmDB
{
private:
	static string fname;
	FilmDB() {}
public:
	void write(Film&f) { fileWrite(fname.c_str(), f); }
	bool read(string fileName = 0)
	{
		FILE *fp;
		Film* film = new Film();
		if (fopen_s(&fp, fname.c_str(), "r") != NULL)
		{
			while (true)
			{
				fread(film, sizeof(Buyer), 1, fp);
				if (feof(fp))
					break;
				if (fileName == film->getName())
					return true;
			}
			fclose(fp);
		}
		return false;
	}
	void del(Film&f) { fileDel(fname.c_str(), f); }
	static FilmDB& getInstance()
	{
		static FilmDB instance;
		return instance;
	}
};
class OrderDB
{
private:
	static string fname;
	OrderDB() {}
public:
	void write(Rent&r) { fileWrite(fname.c_str(), r); }
	void read() {
		FILE *fp; Rent* r = new Rent();
		if (fopen_s(&fp, fname.c_str(), "r") == 0)
		{
			while (true)
			{
				fread(r, sizeof(Rent), 1, fp);
				if (feof(fp))
					break;
				cout << *r << endl;
			}
			fclose(fp);
		}
	}
	void del(Rent&r) { fileDel(fname.c_str(), r); }
	Rent* getOrder()
	{
		FILE *fp;
		Rent*r = new Rent();
		if (fopen_s(&fp, fname.c_str(), "r") == 0)
		{
			fseek(fp, 0, SEEK_END);
			int size = ftell(fp);
			fseek(fp, 0, SEEK_SET);
			for (int i = 0; i < size; i++)
			{
				fread(r, sizeof(Rent), 1, fp);
				if (feof(fp))
					break;
				cout << r << endl;
				char ch;
				cout << "Next?\n";
				cin >> ch;
				if (tolower(ch) == 'n')
					return r;
			}
			fclose(fp);
		}
		return NULL;
	}
	static OrderDB& getInstance()
	{
		static OrderDB instance;
		return instance;
	}
};
class RentDB
{
private:
	static string fname;
	RentDB() {}
public:
	void write(Rent&r) { fileWrite(fname.c_str(), r); }
	void read() {
		FILE *fp; Rent* r = new Rent();
		if (fopen_s(&fp, fname.c_str(), "r") == 0)
		{
			while (true)
			{
				fread(r, sizeof(Rent), 1, fp);
				if (feof(fp))
					break;
				cout << *r << endl;
			}
			fclose(fp);
		}
	}
	void del(Rent&r) { fileDel(fname.c_str(), r); }
	static RentDB& getInstance()
	{
		static RentDB instance;
		return instance;
	}
};
class BlackListDB
{
private:
	static string fname;
	BlackListDB() {}
public:
	void write(Buyer&b) { fileWrite(fname.c_str(), b); }
	void read() {
		FILE *fp; Buyer* b = new Buyer();
		if (fopen_s(&fp, fname.c_str(), "r") == 0)
		{
			while (true)
			{
				fread(b, sizeof(Buyer), 1, fp);
				if (feof(fp))
					break;
				cout << *b << endl;
			}
			fclose(fp);
		}
	}
	static BlackListDB& getInstance()
	{
		static BlackListDB instance;
		return instance;
	}
};
class ProducerDB
{
private:
	static string fname;
	ProducerDB() {}
public:
	void write(Producer&p) { fileWrite(fname.c_str(), &p); }
	void read() {
		FILE *fp; Producer* p = new Producer();
		if (fopen_s(&fp, fname.c_str(), "r") == 0)
		{
			while (true)
			{
				fread(p, sizeof(Producer), 1, fp);
				if (feof(fp))
					break;
				cout << *p << endl;
			}
			fclose(fp);
		}
	}
	void del(Producer&p) { fileDel(fname.c_str(), p); }
	static ProducerDB& getInstance()
	{
		static ProducerDB instance;
		return instance;
	}
};
class BuyerDB
{
private:
	static string fname;
	BuyerDB() {}
public:
	void write(Buyer& b) { fileWrite(fname.c_str(), b); }
	void read() {
		FILE *fp; Buyer* b = new Buyer();
		if (fopen_s(&fp, fname.c_str(), "r") == 0)
		{
			while (true)
			{
				fread(b, sizeof(Buyer), 1, fp);
				if (feof(fp))
					break;
				cout << *b << endl;
			}
			fclose(fp);
		}
	}
	void del(Buyer&b) { fileDel(fname.c_str(), b); }
	static BuyerDB& getInstance()
	{
		static BuyerDB instance;
		return instance;
	}
};
class SellerDB
{
private:
	static string fname;
	SellerDB() {}
public:
	void write(Seller&s) { fileWrite(fname.c_str(), &s); }
	void read() {
		FILE *fp; Buyer* b = new Buyer();
		if (fopen_s(&fp, fname.c_str(), "r") == 0)
		{
			while (true)
			{
				fread(b, sizeof(Buyer), 1, fp);
				if (feof(fp))
					break;
				cout << *b << endl;
			}
			fclose(fp);
		}
	}
	void del(Seller&s) { fileDel(fname.c_str(), s); }
	static SellerDB& getInstance()
	{
		static SellerDB instance;
		return instance;
	}
};
string FilmDB::fname = "FilmDB.txt";
string OrderDB::fname = "OrderDB.txt";
string RentDB::fname = "RentDB.txt";
string BlackListDB::fname = "BlackListDB.txt";
string ProducerDB::fname = "ProducerDB.txt";
string BuyerDB::fname = "BuyerDB.txt";
string SellerDB::fname = "SellerDB.txt";
#endif