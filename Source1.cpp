#include<iostream>
#include <string>
using namespace std;

class identificare
{
private:
 string comanda;
  public:
	  identificare()
	  {
		  comanda ="no";
	  }
	  identificare(string comanda)
	  {
		 
			  this->comanda = comanda;
		  
		  cout << "const";
	  }

	  string getcomanda()
	  {
		  return comanda;
	  }

	  void setcomanda(string comanda)
	  {
		  
			  this->comanda = comanda;

	  }

	  friend istream& operator>>(istream&, identificare&);
	  friend ostream& operator<<(ostream&, identificare);
	  friend class create_table;

};

istream& operator>>(istream& in, identificare& i)
{
	cout << "Comanda dorita este create/drop/display/insert/delete/update/select?" << endl;
	in >> i.comanda;
	if (i.comanda == "create" or i.comanda == "drop" or i.comanda == "display" or i.comanda == "insert"
		or i.comanda == "delete" or i.comanda == "update" or i.comanda == "select")
	{
		return in;
	}
	else
	{
		cout << "Comanda invalida";
	}

}

ostream& operator<<(ostream& out, identificare i)
{
	out << "Comanda: " << i.comanda;
	return out;
}


class create_table
{
private:
	string denumire;
	int nr_atribute;
	string* atribut;
	string* tip;
public:
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
		if (t.atribut != nullptr && t.nr_atribute > 0 && t.tip != nullptr)
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
		if (atribut != nullptr)
		{
			delete[] atribut;
		}
		if (tip != nullptr)
		{
			delete[] tip;
		}
		this->denumire = t.denumire;
		if (t.atribut != nullptr && t.nr_atribute > 0 && t.tip != nullptr)
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
	friend istream& operator>>(istream&, create_table&);
	friend ostream& operator<<(ostream&, create_table);

};

istream& operator>>(istream& in, create_table& t)
{

	
	cout << "Denumire: ";
	in >> t.denumire;
	cout << "Numar de atribute: ";
	in >> t.nr_atribute;
	if (t.atribut != nullptr)
	{
		delete[] t.atribut;
	}
	if (t.tip != nullptr)
	{
		delete[] t.tip;
	}
	if (t.nr_atribute > 0)
	{
		t.atribut = new string[t.nr_atribute+1];
		t.tip = new string[t.nr_atribute +1];
		int k = 1; int i;
		for (i = 0; i < t.nr_atribute; i++);
		{
			
			cout << "atribut " <<  k << ":";
			in >> t.atribut[i];
			cout << "tipul " << k << ":";
			in >> t.tip[i];
			k++;
		}
	}
	else
	{
		t.nr_atribute = 0;
		t.atribut = nullptr;
	}
	return in;
}
class linie
{
public:
	int nr_coloane;
	string nume_coloane;

};


int main()
{

	identificare i;
	cin >> i;
	if (i.getcomanda() == "create")
	{
		create_table t;
		cin >> t;

	}
	/*string n;
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
			cout << "Numele tabelei " << i + 1 << " este: ";
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
	}*/
	//cout << "Doriti sa stergeti tabele? Da/Nu";

}