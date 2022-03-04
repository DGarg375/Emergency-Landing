#ifndef SITENUMBER_H
#define SITENUMBER_H
#include<string>
#include "Runway.h"
#include "Facility.h"

class SiteNumber
{
	private:
		std::string sitenum;
	public:
    		SiteNumber(std::string sitenum): sitenum(sitenum)
		{
		}
		bool operator()(Runway* runway)
		{
        			if(sitenum.compare(runway->site_number())==0)	
				return true;
  			else
				return false;
		}
};

#endif
