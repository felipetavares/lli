#include "list/list.h"
#include "lips.h"
#include <iostream>
using namespace std;
using namespace lips;

int main () {
	Lips lips;	

	List *l = new List();
	List *m = new List();
	List *n = new List();

	List *p = new List();
	List *q = new List();
	List *r = new List();

	p->car()->set (new fAdd());
	q->car()->set (4);
	r->car()->set (3);

	l->car()->set(new fAdd());
	m->car()->set(p);
	n->car()->set(0.3);

	l->append (m);
	m->append (n);

	p->append (q);
	q->append (r);

	l->print();

	lips.eval(l)->print();

	return 0;
}
