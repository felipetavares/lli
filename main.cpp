#include "list/list.h"
#include <iostream>
using namespace std;
using namespace lips;

int main () {
	List *l = new List();
	List *m = new List();
	List *n = new List();

	l->car()->set(10.5);
	m->car()->set(18.9);
	n->car()->set(0.3);

	l->append (m);
	m->append (n);

	l->print();
	m->print();
	n->print();

	l->cdr()->print();

	return 0;
}
