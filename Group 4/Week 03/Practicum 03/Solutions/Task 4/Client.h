#pragma once

struct Client
{
    char* name;
    char billFilename[256];

    Client();
    Client(const char* _name, const char* _billFilename);
    ~Client();
    Client(const Client& other);
    Client& operator=(const Client& other);
};