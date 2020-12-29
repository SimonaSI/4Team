#pragma once
#include<iostream>
using namespace std;

class identificare
{
private:
	string comanda;
public:
	identificare()
	{
		comanda = "no";
	}
	identificare(string comanda)
	{
		this->comanda = comanda;
	}

	string getcomanda()
	{
		return comanda;
	}

	void setcomanda(string comanda)
	{
		this->comanda = comanda;
	}

	explicit operator string()
	{
		return comanda;
	}

	bool operator!()
	{
		return comanda > "";
	}

	bool operator<(const identificare& i)
	{
		if (comanda < i.comanda)
		{
			return true;
		}
		return false;
	}

	bool operator!=(const identificare& i)
	{
		return *this != i;
	}

	friend istream& operator>>(istream&, identificare&);
	friend ostream& operator<<(ostream&, identificare);
};

istream& operator>>(istream& in, identificare& i)
{
	cout << "Comanda dorita este create/drop/display?" << endl;
	in >> i.comanda;
	if (i.comanda == "create" or i.comanda == "drop" or i.comanda == "display")
	{
		return in;
	}
	else
	{
		cout << "Comanda invalida" << endl;
	}
}

ostream& operator<<(ostream& out, identificare i)
{
	out << "Comanda: " << i.comanda;
	return out;
}
