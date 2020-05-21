#include "MyException.h"

MyException::MyException(string message) : message(message){

}

string MyException::getMessage()
{
	return message;
}