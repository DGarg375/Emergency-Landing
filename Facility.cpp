#include "gcdistance.h"
#include "Facility.h"
#include<iostream>
#include<cmath>

using namespace std;

Facility::Facility(std::string s): site_number_(s.substr(0, 10)), type_(s.substr(11, 13)), code_(s.substr(24, 4)), name_(s.substr(130, 50)), latitude_(convert_latitude(s.substr(535, 12))), longitude_(convert_longitude(s.substr(562, 12)))
{
}

string Facility::site_number(void) const 
{
	return this->site_number_;
}

string Facility::code(void) const 
{
    return this->code_;
}

string Facility::name(void) const 
{
    return this->name_;
}

string Facility::type(void) const 
{
    return this->type_;
}

double Facility::latitude(void) const
{
    return this->latitude_;
}

double Facility::longitude(void) const
{
    return this->longitude_;
}

double Facility::distance(double latitude, double longitude) const
{
    return gcdistance(this->latitude_, this->longitude_, latitude, longitude);
}

double Facility::convert_latitude(std::string s) const
{
	double LA=1.0;
    char check=s.back();
    if(check=='S')
	{
        LA= -1.0;
    }
    LA *= (std::stod(s.substr(0, 11)))/3600.0000;
    return LA;
}

double Facility::convert_longitude(std::string s) const 
{
	double LO=1.0;
    char check=s.back();    
    if(check=='W')
	{
        LO= -1.0;
    }
    LO *= (std::stod(s.substr(0, 11)))/3600.0000;
    return LO;
}
