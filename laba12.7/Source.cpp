#include<iostream>
#include <iomanip>
#include<string>
using namespace std;
typedef int faw;
typedef string faq;
struct emal 
{
	emal* link;

	faq nazv;
	faw termin;
	faw result;
	faw shf;
};
 
void creat(emal*& p)
{
	cout << "Nazva robot: " ;
	emal* tmp = new emal;
	cin>>tmp->nazv;

	cout << "Termin u HOUR: ";
	int termin;
	cin >> termin;
	tmp->termin=termin;
	cout << "Rezult 0-ne vukona,1- vukonano: ";
	int result;
	cin >> result;
	tmp->result = result;

	tmp->link = p;
	p = tmp;
	cout << endl;
}
void sort(emal*& p,emal*& p1)
{
	//while (p->link != NULL)
	{
		if (p->result == 0)
		{
			
			emal* tmp = new emal;
			tmp->nazv = p->nazv;
			cout << "Termin u HOUR: ";
			int termin;
			cin >> termin;
			tmp->termin = termin;
			
			int shf;
			cout << "Shtraf: ";
			cin >> shf;
			tmp->shf = shf;
			tmp->link = p1;
			p1 = tmp;
			cout << endl;
		}
		p = p->link;
	}

}
faq pop(emal*& top)
{
	emal* tmp = top->link; // 1
	faq value = top->nazv; // 2
	delete top; // 3
	top = tmp; // 4
	return value; // 5
}
int main()
{
	emal* p = NULL;
	emal* p1 = NULL;
	for (int i = 0; i < 2; i++)
		creat(p);
	for (int i = 1; i < 3; i++)
		sort(p, p1);
	while (p != NULL)
	{
		cout << pop(p);
	}
	cout << endl;
	while (p1 != NULL)
	{
		cout << pop(p1);
	}
}