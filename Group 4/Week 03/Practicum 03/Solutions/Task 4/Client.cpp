#include "Client.h"
#include <string>

Client::Client() : name(nullptr)
{
    billFilename[0] = '\0';
}

Client::Client(const char* _name, const char* _billFilename)
{
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
    strcpy(billFilename, _billFilename);
    billFilename[255] = '\0';
}

Client::~Client()
{
    delete[] name;
}

Client::Client(const Client& other)
{
    if (other.name)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    else
    {
        name = nullptr;
    }
    strcpy(billFilename, other.billFilename);
}

Client& Client::operator=(const Client& other)
{
    if (this != &other)
    {
        delete[] name;
        if (other.name)
        {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        else
        {
            name = nullptr;
        }
        strcpy(billFilename, other.billFilename);
    }
    return *this;
}