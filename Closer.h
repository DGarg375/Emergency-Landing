#ifndef CLOSER_H
#define CLOSER_H
#include<string>
#include "Facility.h"

class Closer
{
	private:
		double clatitude;
		double clongitude;
	public:
		Closer(double clatitude, double clongitude): clatitude(clatitude), clongitude(clongitude)
		{
		}
		bool operator()(Facility* F1, Facility* F2)
		{
			return (F1->distance(clatitude, clongitude) < F2->distance(clatitude, clongitude));
		}
};

#endif