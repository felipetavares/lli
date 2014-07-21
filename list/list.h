#ifndef LIPS_LIST_H
#define LIPS_LIST_H

#include <iostream>

namespace lips {
#define nil NULL

	class List;

	class Function {
	public:
		virtual List* call (List*) = 0;
	};

	class fAdd: public Function {
		List* call (List*);
	};

	class Value {
	public:
		enum Type {NUMBER, LIST, FUNCTION, NIL};
	private:
		Type mType;

		double mNumber;
		List *mList;
		Function *mFunction;
	public:
		Value ();
		Value (double);
		Value (List*);
		Value (Function*);

		Type getType();

		double getNumber ();
		List* getList();
		Function* getFunction();

		void set (Value*);
		void set (double);
		void set (List*);
		void set (Function*);

		std::string str();
	};

	class List {
	protected:
		Value *mCar;
		List *mCdr;
	public:
		List ();
		List (Value*);

		Value* car();
		List* cdr();

		void append (List*);
		void print();
	};

	/*
	class GarbageCollector {
	private:
		List *lists; // All lists active in the software
	public:
		GarbageCollector();

		List*  createList ();
		Value* createValue();

		void collectGarbage ();
	};

	class LipsMachine {
	private:
		GarbageCollector garbageCollector;
	public:
		LipsMachine();
	};
	*/
}

#endif /* LIPS_LIST_H */
