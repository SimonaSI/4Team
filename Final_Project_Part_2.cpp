#include<iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
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

class create_table
{
private:
	string denumire;
	int nr_atribute;
	string* tip;
	string* atribut;
	int* dimensiune;
	string* valori_imp;
public:
	friend class insert;

	create_table()
	{
		denumire = "Noname";
		nr_atribute = 1;
		atribut = nullptr;
		tip = nullptr;
		dimensiune = nullptr;
		valori_imp = nullptr;

	}
	create_table(int nr_atribute, string* atribut)
	{

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
			nr_atribute = 0;
			atribut = nullptr;


		}

	}
	create_table(string denumire, int nr_atribute, string* atribut, string* tip, int* dimensiune, string* valori_imp)
	{
		this->denumire = denumire;
		if (atribut != nullptr && nr_atribute > 0 && dimensiune != nullptr && valori_imp != nullptr)
		{
			this->nr_atribute = nr_atribute;
			this->atribut = new string[nr_atribute];
			this->tip = new string[nr_atribute];
			this->dimensiune = new int[nr_atribute];
			this->valori_imp = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				this->atribut[i] = atribut[i];
				this->tip[i] = tip[i];
				this->dimensiune[i] = dimensiune[i];
				this->valori_imp[i] = valori_imp[i];
			}
		}
		else
		{
			this->nr_atribute = 0;
			this->atribut = nullptr;
			this->tip = nullptr;
			this->dimensiune = nullptr;
			this->valori_imp = nullptr;
		}


	}
	create_table(const create_table& t)
	{
		this->denumire = t.denumire;
		if (t.atribut != nullptr && t.nr_atribute > 0 && t.tip != nullptr && t.dimensiune != nullptr && t.valori_imp != nullptr)
		{
			this->nr_atribute = t.nr_atribute;
			this->atribut = new string[t.nr_atribute];
			this->tip = new string[t.nr_atribute];
			this->dimensiune = new int[t.nr_atribute];
			this->valori_imp = new string[t.nr_atribute];
			for (int i = 0; i < t.nr_atribute; i++)
			{
				this->atribut[i] = t.atribut[i];
				this->tip[i] = t.tip[i];
				this->dimensiune[i] = t.dimensiune[i];
				this->valori_imp[i] = t.valori_imp[i];
			}
		}
		else
		{
			this->atribut = nullptr;
			this->nr_atribute = 0;
			this->tip = nullptr;
			this->dimensiune = nullptr;
			this->valori_imp = nullptr;
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
		if (dimensiune != nullptr)
		{
			delete[] dimensiune;
		}
		if (valori_imp != nullptr)
		{
			delete[] valori_imp;
		}
		this->denumire = t.denumire;
		if (t.atribut != nullptr && t.nr_atribute > 0 && t.tip != nullptr && t.dimensiune != nullptr && t.valori_imp != nullptr)
		{
			this->nr_atribute = t.nr_atribute;
			this->atribut = new string[t.nr_atribute];
			this->tip = new string[t.nr_atribute];
			this->dimensiune = new int[t.nr_atribute];
			this->valori_imp = new string[t.nr_atribute];
			for (int i = 0; i < t.nr_atribute; i++)
			{
				this->atribut[i] = t.atribut[i];
				this->tip[i] = t.tip[i];
				this->dimensiune[i] = t.dimensiune[i];
				this->valori_imp[i] = t.valori_imp[i];
			}
		}
		else
		{
			this->atribut = nullptr;
			this->nr_atribute = 0;
			this->tip = nullptr;
			this->dimensiune = nullptr;
			this->valori_imp = nullptr;
		}
		return *this;
	}

	int getnr_atribute()
	{

		return nr_atribute;

	}

	string getdenumire()
	{
		return denumire;

	}

	string* gettip()
	{
		if (tip != nullptr)
		{
			string* copie = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				copie[i] = tip[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	int* getdimensiune()
	{
		if (dimensiune != nullptr)
		{
			int* copie = new int[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				copie[i] = dimensiune[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	string* getatribut()
	{
		if (atribut != nullptr)
		{
			string* copie = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				copie[i] = atribut[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	string* getvalori_imp()
	{
		if (valori_imp != nullptr)
		{
			string* copie = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				copie[i] = valori_imp[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	void setnr_atribute(int nr_atribute)
	{
		if (nr_atribute > 0)
		{
			this->nr_atribute = nr_atribute;
		}
	}

	void setdenumire(string denumire)
	{
		if (denumire != " ")
		{
			this->denumire = denumire;
		}
	}

	void settip(string* tip, int nr_atribute)
	{
		if (tip != nullptr && nr_atribute > 0)
		{
			this->nr_atribute = nr_atribute;
			if (this->tip != nullptr)
			{
				delete[] this->tip;
			}
			this->tip = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				this->tip[i] = tip[i];
			}
		}
	}
	void setdimensiune(int* dimensiune, int nr_atribute)
	{
		if (dimensiune != nullptr && nr_atribute > 0)
		{
			this->nr_atribute = nr_atribute;
			if (this->dimensiune != nullptr)
			{
				delete[] this->dimensiune;
			}
			this->dimensiune = new int[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				this->dimensiune[i] = dimensiune[i];
			}
		}
	}
	void setatribut(string* atribut, int nr_atribute)
	{
		if (atribut != nullptr && nr_atribute > 0)
		{
			this->nr_atribute = nr_atribute;
			if (this->atribut != nullptr)
			{
				delete[] this->atribut;
			}
			this->atribut = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				this->atribut[i] = atribut[i];
			}
		}
	}
	void setvalori_imp(string* valori_imp, int nr_atribute)
	{
		if (valori_imp != nullptr && nr_atribute > 0)
		{
			this->nr_atribute = nr_atribute;
			if (this->valori_imp != nullptr)
			{
				delete[] this->valori_imp;
			}
			this->valori_imp = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				this->valori_imp[i] = valori_imp[i];
			}
		}
	}

	int& operator[](int index)
	{

		if (index > 0 && index < nr_atribute)
		{
			return dimensiune[index];
		}

	}


	void adauga(string den,string* valori)
	{
		ofstream f(den, ios::binary | ios::app);
		for (int i = 0; i < nr_atribute; i++)
		{

			int length = valori[i].length();
			f.write((char*)&length, sizeof(length));
			f.write(valori[i].c_str(), length + 1);


		}
		f.close();



	}
	/*
	void sterge(string** inr,int &co)
	{
		cout << "DELETE FROM "<<denumire<<endl;
		string col;
		string val;
		int poz;
		cout << " WHERE ";
		cin >> col;
		cout <<" = ";
		cin >> val;
		for (int j = 0; j < nr_atribute; j++)
		{

			if (atribut[j] == col)
				{
				poz = j;

				}

		}
		int i = 0;
		while (i<co)
		{
				if ( inr[i][poz] == val)
				{

					for (int k = i; k < co-1; k++)
					{
						for (int j = 0; j < nr_atribute; j++)
						{
							inr[k][j] = inr[k + 1][j];
						}

					}
					co--;
				}
				else
				{
					i++;
				}


		}

		 for (int i = 0; i <co; i++)
					 {
						 for (int j = 0; j < nr_atribute; j++)
						 {
							 cout << inr[i][j] << " ";
						 }
						 cout << endl;
					 }


	}

	void select(string** inr,int &co )
	{
		cout << "Se introduc coloane pana la intalnirea tastei 0" << endl;
		int* poz;
		string* poz1;
		string op;
		poz = new int[nr_atribute];
		poz1 = new string[nr_atribute];
		string col; int k = 0;
		cout << "SELECT ";
		while (cin >> col && col!="0")
		{
			for (int i = 0; i < nr_atribute; i++)
			{
				if (col == atribut[i])
				{
					poz1[k] = atribut[i];
					poz[k] = i;
					k++;
				}
			}
		}
		cout << " FROM " << denumire<<endl;

		for (int i = 0; i < k; i++)
		{
			cout << poz1[i] << " ";

		}
		cout << endl;
		for (int i = 0; i < co; i++)
		{
			for (int j = 0; j < nr_atribute; j++)
			{

				for (int o = 0; o < k; o++)
				{

					if (j == poz[o] )
					{
						cout << inr[i][j] << " ";
					}
				}

			}
			cout << endl;
		}


	}

	void modif(string** inr, int& co)
	{
		cout << "UPDATE " << denumire<<endl;
		cout << "SET ";
		string col;
		string val;
		string val2;
		string col2;
		int poz;
		cin >> col;
		cout << " = ";
		cin >> val;
		cout << " WHERE ";
		cin >> col2;
		cout << " = ";
		cin >> val2;
		for (int j = 0; j < nr_atribute; j++)
		{

			if (atribut[j] == col)
			{
				poz = j;

			}

		}
		for (int i = 0; i < co; i++)
		{
			for (int j = 0; j < nr_atribute; j++)
			{
				if (atribut[j] == col2 && inr[i][j] == val2)
				{
					inr[i][poz] = val;
				}
			}
		}

		for (int i = 0; i < co; i++)
		{
			for (int j = 0; j < nr_atribute; j++)
			{
				cout << inr[i][j] << " ";
			}
			cout << endl;
		}
	}*/

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
		if (dimensiune != nullptr)
		{
			delete[] dimensiune;
		}
		if (valori_imp != nullptr)
		{
			delete[] valori_imp;
		}

	}
	friend istream& operator>>(istream&, create_table&);
	friend ostream& operator<<(ostream&, create_table);


	create_table operator++(int i)
	{
		create_table copie = *this;
		this->nr_atribute++;
		return copie;
	}

	create_table operator++()
	{
		this->nr_atribute++;
		return *this;
	}

	operator int()
	{
		return nr_atribute;
	}

	explicit operator string()
	{
		return denumire;
	}

	bool operator!()
	{
		return nr_atribute > 0;
	}

	bool operator <(const create_table& t) {
		if (denumire < t.denumire)
		{
			return true;
		}

		return false;
	}

	bool operator==(const create_table& t1)
	{
		return *this == t1;
	}



	create_table operator+(int valoare)
	{

		create_table copie = *this;
		copie.nr_atribute += valoare;
		return copie;


	}

	friend ofstream& operator<<(ofstream&, create_table);
	friend ifstream& operator>>(ifstream&, create_table&);

};

ofstream& operator<<(ofstream& g, create_table t)
{
	if (g.is_open())
	{
		g << t.denumire << endl;
		g << t.nr_atribute << endl;
		if (t.atribut != nullptr && t.tip != nullptr && t.dimensiune != nullptr && t.valori_imp != nullptr)
		{
			for (int i = 0; i < t.nr_atribute; i++)
			{
				g << t.atribut[i] << " ";
				g << t.tip[i] << " ";
				g << t.dimensiune[i] << " ";
				g << t.valori_imp[i] << " ";
				g << endl;
			}
		}
	}
	return g;
}

ifstream& operator>>(ifstream& in, create_table& t)
{
	if (in.is_open())
	{
		cout << "Denumire tabelei: " << endl;
		getline(in, t.denumire);
		cout << "Numar de atribute: " << endl;
		in >> t.nr_atribute;
		if (t.atribut != nullptr)
		{
			delete[] t.atribut;
		}
		if (t.tip != nullptr)
		{
			delete[] t.tip;
		}
		if (t.dimensiune != nullptr)
		{
			delete[] t.dimensiune;
		}
		if (t.valori_imp != nullptr)
		{
			delete[] t.valori_imp;
		}
		if (t.nr_atribute > 0)
		{
			t.atribut = new string[t.nr_atribute + 1];
			t.tip = new string[t.nr_atribute + 1];
			t.dimensiune = new int[t.nr_atribute + 1];
			t.valori_imp = new string[t.nr_atribute + 1];
			for (int i = 0; i < t.nr_atribute; i++)
			{
				in >> ws;
				cout << "atributul " << i + 1 << " ";
				getline(in, t.atribut[i]);
				in >> ws;
				cout << endl << "tipul atributului este ";
				getline(in, t.tip[i]);

				cout << endl << "dimesiunea atributului  este ";
				in >> t.dimensiune[i];
				in >> ws;
				cout << endl << "valoarea implicita  este ";
				getline(in, t.valori_imp[i]);
				cout << endl;
			}

		}
		else
		{
			t.nr_atribute = 0;
			t.atribut = nullptr;
			t.tip = nullptr;
			t.dimensiune = nullptr;
			t.valori_imp = nullptr;
		}
	}
	return in;

}


create_table operator+(int valoare, create_table tr)
{
	int x = tr.getnr_atribute();
	x += valoare;
	return tr;
}
istream& operator>>(istream& in, create_table& t)
{


	cout << "Denumire tabelei: ";
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
	if (t.dimensiune != nullptr)
	{
		delete[] t.dimensiune;
	}
	if (t.valori_imp != nullptr)
	{
		delete[] t.valori_imp;
	}
	if (t.nr_atribute > 0)
	{
		t.atribut = new string[t.nr_atribute + 1];
		t.tip = new string[t.nr_atribute + 1];
		t.dimensiune = new int[t.nr_atribute + 1];
		t.valori_imp = new string[t.nr_atribute + 1];
		for (int i = 0; i < t.nr_atribute; i++)
		{
			cout << "atributul " << i + 1 << " ";
			in >> t.atribut[i];
			cout << "tipul atributului " << t.atribut[i] << " este ";
			in >> t.tip[i];
			cout << "dimesiunea atributului " << t.atribut[i] << " este ";
			in >> t.dimensiune[i];
			cout << "valoarea implicita " << t.atribut[i] << " este ";
			in >> t.valori_imp[i];

		}

	}
	else
	{
		t.nr_atribute = 0;
		t.atribut = nullptr;
		t.tip = nullptr;
		t.dimensiune = nullptr;
		t.valori_imp = nullptr;
	}
	return in;
}

ostream& operator<<(ostream& out, create_table t)
{
	out << "Denumirea tabelei: " << t.denumire << endl;
	out << "Numar de atribute: " << t.nr_atribute << endl;
	for (int i = 0; i < t.nr_atribute; i++)
	{
		out << "Nume atribut " << i + 1 << " " << t.atribut[i] << endl;
		out << "Tipul atributului " << t.atribut[i] << " este " << t.tip[i] << endl;
		out << "Dimensiunea atributului " << t.atribut[i] << " este " << t.dimensiune[i] << endl;
		out << "Valoarea implicita a atributului " << t.atribut[i] << " este " << t.valori_imp[i] << endl;
	}
	return out;
}

int main()
{

	create_table ta[100];
	int k = 0;
	char optiune;
	do
	{
		cout << endl << endl << "                                   MENIU       " << endl;
		cout << "                    1 - CREATE TABLE" << endl;
		cout << "                    2 - DROP TABLE" << endl;
		cout << "                    3 - DISPLAY TABLE" << endl;
		cout << "                    4 - INSERT" << endl;
		cout << "                    5 - UPDATE" << endl;
		cout << "                    6 - DELETE" << endl;
		cout << "                    7 - SELECT" << endl;
		cout << "                    x - iesire" << endl;
		cout << "Introduceti comanda: ";
		cin >> optiune;

		switch (optiune)
		{
		case '1': {

			create_table t;
			cin >> t;
			ta[k] = t;
			k++;
			ofstream g;
			string num;
			num = t.getdenumire();
			g.open(num);
			g << t;
			g.close();

		

		}
				break;
		case '2': {

			string nume;
			cout << "DROP TABLE ";
			cin >> nume;
			remove(nume.c_str());
			cout << "Tabela " << nume << " a fost stearsa cu succes.";
		}
				break;
		case '3': {
			cout << "DISPLAY ";
			string nume;
			cin >> nume;
			for (int i = 0; i < k; i++)
			{
				if (ta[i].getdenumire() == nume)
				{
					cout << ta[i];
				}
				else
				{
					cout << "Tabela nu exista!";
				}

			}
			
		}

				break;
		case '4':
		{
			string num,num1;
			num1 = '1';
			cout << "INSERT INTO   ";
			cin >> num;
			for (int i = 0; i < k; i++)
			{
				if (ta[i].getdenumire()==num)
				{
					string* p;
					p = new string[ta[i].getnr_atribute()];
					cout << "VALUES ";
					for (int g = 0; g < ta[i].getnr_atribute(); g++)
					{
						cin >> p[g];
					}

					ta[i].adauga(num+num1,p);
				}

			}
			
		}

		   break;
		case '5': cout << "Rezultatul este: " << endl << endl;
			break;
		case '6': 
		{
			string c;
			cout << "DELETE FROM ";
			cin >> c;
			cout << "WHERE ";
			string n,v;
			cin >> n;
			cout << " = ";
			cin >> v;
			int ok = 0;
			string c1 = c + '1';
			ifstream f(c1, ios::binary);
			ofstream g("temp.bin", ios::binary | ios::trunc);
			for (int i = 0; i< k; i++)
			{
				if (ta[i].getdenumire() == c)
				{
					string* s = ta[i].getatribut();
				 
					int p = 0;
					while (p < ta[i].getnr_atribute() && ok == 0)
					{
						if (s[p] == n)
						{
							ok = 1;
						}
						
						p++;
					}
				

					string va;
					string* vl;
					vl = new string[ta[i].getnr_atribute() + 1];
					while (!f.eof())
					{
						int ok1 = 1;
						int k1 = 0;
						for (int k = 0; k < ta[i].getnr_atribute(); k++)
						{
							
							va = "";
							char c = 0;
							while ((c = f.get()) != 0)
							{
								va += c;
							}
							cout << va;
								vl[k1] = va;
								k1++;
								if (va == v && k == p-1)
								{

									ok1 = 0;

								}
							
						}

						if (ok1 == 1)
						{
							for (int t = 0; t < ta[i].getnr_atribute(); t++)
							{
								g.write((char*)&vl[t], sizeof(vl[t]));
							}

						}
						
					}
					f.close();
					g.close();
					remove(c1.c_str());
				   rename("temp.bin", c1.c_str());
					
				}
			}
			

		}
			break;
		case '7': cout << "Rezultatul este: " << endl << endl;
			break;
		case 'x': exit(1);
		default: cout << "Optiune incorecta!";

		}

	} while (optiune != 'x');

 };