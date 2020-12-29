#include<iostream>
#include <string>
#include"create_table.h"
#include"Identificare.h"
using namespace std;

int main()
{
	int ok = 1;
	string m;
	identificare i;
	create_table c[100];
	int k = 0;
	int k1 = 0;
	cin >> i;
	while (ok == 1)
	{
		if (i.getcomanda() == "create")
		{
			string op;
			int op1;
			string op2;
			create_table t;
			cin >> t;
			c[k] = t;
			k++;
			string* values;
			values = new string[t.getnr_atribute()];
			cout << "Doriti sa adaugati inregistrari? Da/Nu " << endl;
			cin >> op;
			if (op == "Da")
			{
				cout << "Cate inregistrari doriti sa adaugati?" << endl;
				cin >> op1;
				if (op1 > 0)
				{
					string** inr;
					int co = 0;
					inr = new string * [op1];
					for (int i = 0; i < op1; i++)
					{
						inr[i] = new string[t.getnr_atribute()];
					}
					for (int i = 0; i < op1; i++)
					{
						t.adauga(values);

						for (int j = 0; j < t.getnr_atribute(); j++)
						{
							inr[co][j] = values[j];
						}
						co++;
					}
					cout << "Doriti alta comanda? Delete/Select/Update" << endl;
					string l;
					cin >> l;
					while (l == "Delete" or l == "Select" or l == "Update")
					{
						if (l == "Delete")
						{
							cout << "Doriti sa stergeti o inregistrare? Da/Nu " << endl;
							cin >> op;
							if (op == "Da")
							{
								t.sterge(inr, co);
								cout << "Mai stergeti? Da/Nu "<<endl;
								cin >> op2;
								while (op2 == "Da")
								{
									t.sterge(inr, co);
									cout << "Mai stergeti? Da/Nu "<<endl;
									cin >> op2;
								}
							}
						}
						if (l == "Select")
						{
							cout << "Doriti sa faceti o selectie? Da/Nu " << endl;
							cin >> op;
							if (op == "Da")
							{
								t.select(inr, co);
								cout << "Mai selectati? Da/Nu "<<endl;
								cin >> op2;
								while (op2 == "Da")
								{
									t.select(inr, co);
									cout << "Mai selectati? Da/Nu "<<endl;
									cin >> op2;
								}
							}
						}
						if (l == "Update")
						{
							cout << "Doriti sa modificati un camp? Da/Nu "<<endl;
							cin >> op;
							if (op == "Da")
							{
								t.modif(inr, co);
								cout << "Mai modificati? Da/Nu "<<endl;
								cin >> op2;
								while (op2 == "Da")
								{
									t.modif(inr, co);
									cout << "Mai modificati? Da/Nu "<<endl;
									cin >> op2;
								}
							}
						}
						cout << "Doriti alta comanda? Delete/Select/Update"<<endl;
						cin >> l;
					}
				}
			}
		}
		if (i.getcomanda() == "drop")
		{
			cout << "DROP TABLE ";
			string name;
			cin >> name;
			for (int i = 0; i < k; i++)
			{
				if (c[i].getdenumire() == name)
				{
					for (int j = i; j < k - 1; j++)
					{
						c[j] = c[j + 1];
					}
					k--;
				}
			}
		}
		if (i.getcomanda() == "display")
		{
			cout << "DISPLAY TABLE ";
			string name1;
			cin >> name1;
			for (int i = 0; i < k; i++)
			{
				if (c[i].getdenumire() == name1)
				{
					cout << c[i] << endl;
				}
			}
		}
		cout << "Doriti sa efectuati alte operatiuni? Da/Nu "<<endl;
		cin >> m;
		if (m == "Da")
		{
			cin >> i;
		}
		else
		{
			ok = 0;
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout << endl << c[i] << endl;
	}
}