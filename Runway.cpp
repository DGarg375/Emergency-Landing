#include<iostream>
#include "Runway.h"

using namespace std;

Runway::Runway(string s): site_number_(s.substr(0, 10)), name_(s.substr(13, 7)), length_(convert_length(s.substr(20, 5)))
{
}

int Runway::length(void) const
{
    return this->length_;
}

string Runway::site_number(void) const 
{
    return this->site_number_;
}

int Runway::convert_length(std::string s) const
{
    return stoi(s);
}

string Runway::name(void) const
{
    return this->name_;
}


