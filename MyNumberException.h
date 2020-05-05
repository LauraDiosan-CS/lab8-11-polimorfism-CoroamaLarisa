#pragma once

#include <stdexcept>

using namespace std;

class MyNumberException :
	public runtime_error {
private:
	string message;
public:
	MyNumberException(string msg) : runtime_error(msg), message(msg) {};

	string what() {
		return message;
	}


};