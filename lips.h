#ifndef LIPS_H
#define LIPS_H

#include <vector>
#include "list/list.h"

using namespace std;

namespace lips {
	class Lips {
		vector <string> scope;
	public:
		Lips ();
		List* eval (List*);
	};
}

#endif /* LIPS_H */
