#include "list.h"
#include <sstream>
using namespace lips;

Value::Value () {
	set ((List*)nil);
}

Value::Value (double number) {
	set (number);
}

Value::Value (List *list) {
	set (list);
}

Value::Value (Function* function) {
	set (function);
}

void Value::set (Value *v) {
	mType = v->mType;
	mNumber = v->mNumber;
	mList = v->mList;
	mFunction = v->mFunction;
}

void Value::set (double number) {
	mType = NUMBER;
	mNumber = number;
}

void Value::set (List* list) {
	if (list == nil) {
		mType = NIL;
		mList = nil;
	} else {
		mType = LIST;
		mList = list;
	}
}

void Value::set (Function* function) {
	mType = FUNCTION;
	mFunction = function;
}

List* Value::getList () {
	if (mType == LIST) {
		return mList;
	}
	return nil;
}

double Value::getNumber () {
	if (mType == NUMBER) {
		return mNumber;
	}
	return 0;
}

Function* Value::getFunction () {
	if (mType == FUNCTION) {
		return mFunction;
	}
	return nil;
}


Value::Type Value::getType () {
	return mType;
}

std::string Value::str () {
	std::stringstream ss;

	switch (mType) {
		case NUMBER:
			ss << getNumber();
		break;
		case FUNCTION:
			ss << "<fn>";
		break;
		case LIST:
			ss << "[]";
		break;
		case NIL: default:
			ss << "nil";
	}

	return ss.str();
}

// List
List::List () {
	mCar = new Value();
	mCdr = nil;
}

List::List (Value *car) {
	mCar = car;
	mCdr = nil;
}

Value* List::car () {
	return mCar;
}

List* List::cdr () {
	return mCdr;
}

void List::append (List *list) {
	List *end = this;

	while (end->cdr() != nil) {
		end = end->cdr();
	}

	end->mCdr = list;
}

void List::print () {
	List *i = this;

	do {
		if (i && i->car())
			std::cout << i->car()->str();
		else
			std::cout << "nil";

		if (i)
			i = i->cdr();
		else
			break;

		std::cout << " ";
	} while (1);

	std::cout << std::endl;
}

List* fAdd::call (List *args) {
	List *ret = new List();
	List *i = args;
	double result = 0;
	while (i != nil) {
		if (i->car()->getType() == Value::NUMBER)
			result += i->car()->getNumber();
		if (i->car()->getType() == Value::LIST)
			result += i->car()->getList()->car()->getNumber();

		i = i->cdr();
	}
	ret->car()->set(result);
	return ret;
}
