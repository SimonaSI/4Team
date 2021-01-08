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


	void adauga(string* valori)
	{
		ofstream f(denumire, ios::binary);
		cout << "INSERT INTO  "<<denumire<<" VALUES "<<endl;
		for (int i = 0; i <nr_atribute; i++)
		{
			cout << atribut[i] << " : ";
			cin >> valori[i];
			int length=valori[i].length();
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

	//void create()
	//{
	//	cout << "Numele fisierului: ";
	//	string num;
	//	cin >> num;
	//	ofstream g;
	//	g.open(num);
	//	g << denumire << endl;
	//	g<< nr_atribute << endl;
	//	for (int i = 0; i < nr_atribute; i++)
	//	{
	//		g<< atribut[i] << " " ;
	//		g<< tip[i] << " ";
	//		g<< dimensiune[i] << " ";
	//		g<< valori_imp[i] << " ";
	//		g << endl;
	//	}
	//	g.close();
	//}

	void display(string n)
	{
		cout << "Numele fisierului: ";
		string num;
		cin >> num;
		ifstream f;
		f.open(num);
		cout << "Denumire tabelei: ";
		f >> denumire;
		cout << "Numar de atribute: ";
		f >> nr_atribute;

		for (int i = 0; i < nr_atribute; i++)
		{
			cout << "atributul " << i + 1 << " ";
			f >> atribut[i];
			cout << "tipul atributului " << atribut[i] << " este ";
			f >> tip[i];
			cout << "dimesiunea atributului " << atribut[i] << " este ";
			f >> dimensiune[i];
			cout << "valoarea implicita " << atribut[i] << " este ";
			f >> valori_imp[i];

		}

		f.close();


	}
	void serializare()
	{
		ofstream f(denumire, ios::binary);
		int length = denumire.length();
		f.write((char*)&length, sizeof(length));
		f.write(denumire.c_str(), length + 1);
		f.write((char*)&nr_atribute, sizeof(nr_atribute));
		for (int i = 0; i < nr_atribute; i++)
		{
			int length2 = atribut[i].length();
			f.write((char*)&length2, sizeof(length2));
			f.write(atribut[i].c_str(), length2 + 1);
			int length1 = tip[i].length();
			f.write((char*)&length1, sizeof(length1));
			f.write(tip[i].c_str(), length1 + 1);
			f.write((char*)&dimensiune[i], sizeof(dimensiune[i]));
			int length3 = valori_imp[i].length();
			f.write((char*)&length3, sizeof(length3));
			f.write(valori_imp[i].c_str(), length3 + 1);


		}
		f.close();
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
		cout << "Denumire tabelei: "<<endl;
		//in >> ws;
		getline(in, t.denumire);
		cout << "Numar de atribute: "<<endl;
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
				cout << endl<<"tipul atributului este ";
				getline(in, t.tip[i]);

				cout <<endl<< "dimesiunea atributului  este ";
				in >> t.dimensiune[i];
				in >> ws;
				cout << endl<<"valoarea implicita  este ";
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
			ofstream g;
			string num;
			cout << "Numele fisierului: ";
			cin >> num;
			g.open(num);
			g << t;
			g.close();
			string n;
			cout << "Nume: ";
			cin >> n;
			ifstream f(n);
			f >> t;

			f.close();
			




				/*char optiune2;
				cin >> optiune2;
				switch (optiune2)
				{
				case 'a': {cout << "DISPLAY ";
					string num;
					cin >> num;
					t.display(num);
				}
					break;
				}*/
			}
			break;
		case '2': {

			string nume;
			cin >> nume;
			remove(nume.c_str());
		}
				break;
		case '3': {

			/*cout << "DISPLAY ";
			string num;
			cin >> num;*/
			//create_table::display(num);

			//t.display(num);
		}

				break;
		case '4': cout << "Rezultatul este: " << endl << endl;
			break;
		case '5': cout << "Rezultatul este: " << endl << endl;
			break;
		case '6': cout << "Rezultatul este: " << endl << endl;
			break;
		case '7': cout << "Rezultatul este: " << endl << endl;
			break;
		case 'x': exit(1);
		default: cout << "Optiune incorecta!";

		}

		} while (optiune != 'x');




		//int ok = 1;
		//string m;
		//identificare i;
		//create_table c[100];
		//int k = 0;
		//int k1 = 0;
		//cin >> i;
		//while (ok == 1)
		//{

		//	if (i.getcomanda() == "create")
		//	{
		//		
		//		string op;
		//		int op1;
		//		string op2;
		//		create_table t;
		//		cin >> t;
		//		c[k] = t;
		//		k++;
		//		string* values;
		//		values = new string[t.getnr_atribute()];
		//		cout << "Doriti sa adaugati inregistrari? Da/Nu " << endl;
		//	     cin >> op;
		//		 if (op == "Da")
		//		 {
		//			 cout << "Cate inregistrari doriti sa adaugati?"<<endl;
		//			 cin >> op1;
		//			 if (op1 > 0)
		//			 {
		//				 string** inr;
		//				 int co = 0;
		//				 inr = new string * [op1];
		//				 for (int i = 0; i < op1; i++)
		//				 {
		//					 inr[i] = new string[t.getnr_atribute()];
		//				 }
		//				 for (int i = 0; i < op1; i++)
		//				 {
		//					 t.adauga(values);

		//					 for (int j = 0; j < t.getnr_atribute(); j++)
		//					 {
		//						 inr[co][j] = values[j];
		//					 }
		//					 co++;

		//				 }

		//				 cout << "Doriti alta comanda? Delete/Select/Update"<<endl;
		//					 string l;
		//				 cin >> l;
		//				 while (l =="Delete" or l == "Select" or l == "Update")
		//				 {
		//					 if (l == "Delete")
		//					 {
		//						 cout << "Doriti sa stergeti o inregistrare? Da/Nu " << endl;
		//						 cin >> op;
		//						 if (op == "Da")
		//						 {
		//							 t.sterge(inr, co);
		//							 cout << "Mai stergeti? Da/Nu ";
		//							 cin >> op2;
		//							 while (op2 == "Da")
		//							 {
		//								 t.sterge(inr, co);
		//								 cout << "Mai stergeti? Da/Nu ";
		//								 cin >> op2;

		//							 }
		//						 }

		//					 }
		//					 if (l == "Select")
		//					 {
		//						 cout << "Doriti sa faceti o selectie? Da/Nu " << endl;
		//						 cin >> op;
		//						 if (op == "Da")
		//						 {
		//							 t.select(inr, co);
		//							 cout << "Mai selectati? Da/Nu ";
		//							 cin >> op2;
		//							 while (op2 == "Da")
		//							 {
		//								 t.select(inr, co);
		//								 cout << "Mai selectati? Da/Nu ";
		//								 cin >> op2;

		//							 }
		//						 }
		//					 }
		//					 if (l == "Update")
		//					 {
		//						 cout << "Doriti sa modificati un camp? Da/Nu ";
		//						 cin >> op;
		//						 if (op == "Da")
		//						 {
		//							 t.modif(inr, co);
		//							 cout << "Mai modificati? Da/Nu ";
		//							 cin >> op2;
		//							 while (op2 == "Da")
		//							 {
		//								 t.modif(inr, co);
		//								 cout << "Mai modificati? Da/Nu ";
		//								 cin >> op2;

		//							 }
		//						 }
		//					 }
		//					 cout << "Doriti alta comanda? Delete/Select/Update";
		//						 cin >> l;
		//				 }
		//				
		//			 }
		//			
		//		 }
		//		

		//	}

		//	if (i.getcomanda() == "drop")
		//	{
		//		cout << "DROP TABLE ";
		//		string name;
		//		cin >> name;
		//		for (int i = 0; i < k; i++)
		//		{
		//			if (c[i].getdenumire() == name)
		//			{
		//				for (int j = i; j < k - 1; j++)
		//				{
		//					c[j] = c[j + 1];
		//				}
		//				k--;
		//			}
		//		}
		//		

		//	}

		//	if (i.getcomanda() == "display")
		//	{
		//		cout << "DISPLAY TABLE ";
		//		string name1;
		//		cin >> name1;
		//		for (int i = 0; i < k; i++)
		//		{
		//			if (c[i].getdenumire() == name1)
		//			{
		//				cout << c[i]<<endl;
		//			}
		//			

		//		}
		//	}

		//	cout << "Doriti sa efectuati alte operatiuni? Da/Nu ";
		//	cin >> m;
		//	if (m == "Da")

		//	{
		//		cin >> i;
		//	}
		//	else
		//	{
		//		ok = 0;
		//	}
		//}




	

}