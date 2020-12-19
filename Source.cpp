#include<iostream>
#include <string>
using namespace std;

class identificare
{
public: string comanda;
	  
	  identificare(string comanda)
	  {
		  if (comanda == "create table" || comanda=="drop table" || comanda=="display table")
		  {
			  this->comanda = comanda;
		  }
	  }
};

class create_table
{
public: 
	string denumire;
	int nr_atribute;
	string* atribut;	
	string* tip;
	create_table(string denumire = "Tabel", int nr_atribute = 0, string* atribut = nullptr, string* tip = nullptr)
	{
		  this->denumire = denumire;
		  if (atribut != nullptr && nr_atribute > 0)
		  {
			  this->nr_atribute = nr_atribute;
			  this->atribut = new string[nr_atribute];
			  for (int i = 0; i < nr_atribute; i++)
			  {
				  this->atribut[i] = atribut[i];
			  }
		  }
		  else
		  {
			  this->nr_atribute = 0;
			  this->atribut = nullptr;
		  }
		  if (tip != nullptr && nr_atribute > 0)
		  {
			  this->nr_atribute = nr_atribute;
			  this->tip = new string[nr_atribute];
			  for (int i = 0; i < nr_atribute; i++)
			  {
				  this->tip[i] = tip[i];
			  }
		  }
		  else
		  {
			  this->nr_atribute = 0;
			  this->tip = nullptr;
		  }
		  
		  cout << "S a apelat constructorul" << endl;
	}
	create_table(const create_table& t)
	{
		this->denumire = t.denumire;
		if (t.atribut != nullptr && t.nr_atribute>0 && t.tip!=nullptr)
		{
			this->nr_atribute = t.nr_atribute;
			this->atribut = new string[nr_atribute];
			this->tip = new string[nr_atribute];
			for (int i = 0; i < t.nr_atribute; i++)
			{
				this->atribut[i] = t.atribut[i];
				this->tip[i] = t.tip[i];
			}
		}
		else
		{
			this->atribut = nullptr;
			this->nr_atribute = 0;
			this->tip = nullptr;
		}
	}

	create_table& operator=(const create_table& t)
	{
		if (atribut != nullptr )
		{
			delete[] atribut;
		}
		if (tip != nullptr)
		{
			delete[] tip;
		}
		this->denumire = t.denumire;
		if (t.atribut != nullptr && t.nr_atribute > 0 && t.tip!=nullptr)
		{
			this->nr_atribute = t.nr_atribute;
			this->atribut = new string[nr_atribute];
			this->tip = new string[nr_atribute];
			for (int i = 0; i < t.nr_atribute; i++)
			{
				this->atribut[i] = t.atribut[i];
				this->tip[i] = t.tip[i];
			}
		}
		else
		{
			this->atribut = nullptr;
			this->nr_atribute = 0;
			this->tip = nullptr;
		}
		return *this;
	}
	~create_table()
	{
		if (atribut != nullptr)
		{
			delete[] atribut;
		}
		if (tip != nullptr)
		{
			delete[] tip;
		}
		cout << "S a apelat destructorul" << endl;
	}
};


class linie
{
public:
	int nr_coloane;
	string nume_coloane;

};


int main()
{
	string n;
	cout << "Doriti sa creati tabele? Da/Nu" << endl;
	cin >> n;
	if (n == "Da")
	{
		int nr;
		cout << "Cate tabele doriti sa adaugati?" << endl;
		cin >> nr;
		for (int i = 0; i < nr; i++)
		{
			int m;
			string denum;
			cout << "Numele tabelei "<< i+1<<" este: ";
			cin >> denum;
			cout << "Numarul de atribute: ";
			cin >> m;
			string* coloana = new string[m];
			string* tipul = new string[m];
			for (int i = 0; i < m; i++)
			{
				cout << "atributul " << i + 1 << " ";
				cin >> coloana[i];
				cout << "tipul " << " ";
				cin >> tipul[i];
			}
			create_table tabel(denum, m, coloana, tipul);
		}
	}
	else
	{
		cout << "La revedere";
	}
	//cout << "Doriti sa stergeti tabele? Da/Nu";
	
}
