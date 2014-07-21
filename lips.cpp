#include "lips.h"
using namespace lips;

Lips::Lips () {
	scope.push_back (new Symbol ("add", fAdd));
	scope.push_back (new Symbol ("print", fPrint));
}

List* Lips::eval (List* fn) {
	List *args,*fnargs;
	List *i;
	List *n;

	switch (fn->car()->getType()) {
		case Value::FUNCTION:
			fnargs = args = new List();
			i = fn->cdr();
			while (i != nil) {
				if (i->car()->getType() == Value::LIST)
					args->car()->set(eval(i->car()->getList()));
				else
					args->car()->set(i->car());
				
				n = new List();
				args->append(n);
				args = n;

				i = i->cdr();
			}
			return fn->car()->getFunction()->call(fnargs);
		break;
		case Value::NUMBER:
			return fn;
		break;
		case Value::LIST:
			return eval(fn->car()->getList());
		break;
		default:
			return fn;
	} 
}
