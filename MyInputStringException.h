#pragma once

#include <stdexcept>

using namespace std;

class MyInputStringException :
	public runtime_error {
private:
	string message;
public:
	MyInputStringException(string msg) : runtime_error(msg), message(msg) {};

	string what() {
		return this->message;
	}

};