//
// mayday.cpp
//
// use: mayday latitude longitude min_length
//
// Provide a list of facilities and runways closest to the location specified
// by the coordinates (latitude,longitude).
// Only facilities having runways longer than min_length are printed.
// Only runways longer than min_length are printed.
//
// Input:
//   latitude, longitude in degrees decimal
//   min_length in ft
// Output:
//   list of nearest facilities and runways including distance in nautical miles

#include "Facility.h"
#include "Runway.h"
#include "Closer.h"
#include "SiteNumber.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;

int main(int argc, char **argv){
    // use: mayday current_latitude current_longitude min_runway_length
    // latitude and longitudes in degrees decimal
    // min runway length of runway in ft

    assert(argc==4);
    const double current_latitude = atof(argv[1]);
    const double current_longitude = atof(argv[2]);
    const int min_runway_length = atoi(argv[3]);

    vector<Facility*> facilities;
    // load facilities data
    // Insert your code here
	
    string stat;
    ifstream f1("Facilities.txt");
    Facility* fac;
    while(getline(f1, stat))
	{
      fac=new Facility(stat);
      facilities.push_back(fac);
    }
      // sort facilities in order of proximity to the current position
      sort(facilities.begin(), facilities.end(),Closer(current_latitude,current_longitude));
    vector<Runway*> runways;
    // load runways data
    // Insert your code here
	
      ifstream f2("Runways.txt");
      Runway* runcheck;
    while(getline(f2, stat))
	{
      runcheck=new Runway(stat);
      runways.push_back(runcheck);
    }

    // list up to 10 nearest facilities that have a long enough runway
    // list each runway that is long enough
    int count = 0;
    for (unsigned int i = 0; i < facilities.size() && count < 10; i++){
        Facility *a = facilities[i];
        // Find all runways of this facility that are long enough
        vector<Runway*> good_runways;
        // Insert your code here
		
        vector<Runway*>::iterator rem=runways.begin();
        vector<Runway*>::iterator R1;
        Runway* R2;
        while(rem!=runways.end())
		{
            R1=find_if(rem, runways.end(), SiteNumber(a->site_number()));
            if(R1!=runways.end())
			{
                R2= *R1;
                if(R2->length()>=min_runway_length)
				{
                    good_runways.push_back(R2);
                }
				rem=++R1;
            }
            else
                break;
        }
        // print this facility if it has long enough runways
        if ( !good_runways.empty()){
        // increment count of good facilities
        count++;
        cout << a->type() << " " << a->code() << " "<< a->name() << " ";
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout.setf(ios_base::right, ios_base::adjustfield);
        cout.width(5);
        cout.precision(1);
        cout << a->distance(current_latitude,current_longitude)<< " NM" << endl;
        // print all runways that are long enough
        for (unsigned int i = 0; i < good_runways.size(); i++){
            Runway *r = good_runways[i];
            cout << "  Runway: " << r->name() << "  length: " << r->length()<< " ft" << endl;
        }
      }
    }
}
