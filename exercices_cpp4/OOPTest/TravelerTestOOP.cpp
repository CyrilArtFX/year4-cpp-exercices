#include "TravelerTestOOP.h"

#include <iostream>
#include <vector>
#include <unordered_set>



/*
class City
{
public:
	City() {}

	void AddRoad(Road road) 
	{
		roads.push_back(road);
	}

	std::vector<Road> roads;
};



struct Road
{
	City* destination;
	int distance;
};



class Traveler
{
public:
	Traveler() {}

	void AddCity(City* city)
	{
		cities.push_back(city);
		cities_to_travel.insert(city);
	}

	void Start(City* start);

private:
	std::vector<City*> cities;
	City* start_city;
	std::unordered_set<City*> cities_to_travel;
};


void Traveler::Start(City* start)
{
	start_city = start;
	cities_to_travel.erase(start);


}

*/



void TravelerTestOOP::Execute()
{
	std::cout << "Executing object oriented programming test with the traveller.\n";
	std::cout << "--------------------------------------------------------------\n\n";


	/*City* A = new City();
	City* B = new City();
	City* C = new City();
	City* D = new City();
	City* E = new City();

	A->AddRoad(Road{ B, 2 });
	A->AddRoad(Road{ C, 2 });

	B->AddRoad(Road{ A, 2 });
	B->AddRoad(Road{ C, 3 });
	B->AddRoad(Road{ D, 3 });
	B->AddRoad(Road{ E, 1 });

	C->AddRoad(Road{ A, 2 });
	C->AddRoad(Road{ B, 3 });
	C->AddRoad(Road{ D, 1 });
	C->AddRoad(Road{ E, 3 });

	D->AddRoad(Road{ B, 3 });
	D->AddRoad(Road{ C, 1 });
	D->AddRoad(Road{ E, 3 });

	E->AddRoad(Road{ B, 1 });
	E->AddRoad(Road{ C, 3 });
	E->AddRoad(Road{ D, 3 });


	Traveler traveler;

	traveler.AddCity(A);
	traveler.AddCity(B);
	traveler.AddCity(C);
	traveler.AddCity(D);
	traveler.AddCity(E);


	traveler.Start(D);


	delete A;
	delete B;
	delete C;
	delete D;
	delete E;*/
}
