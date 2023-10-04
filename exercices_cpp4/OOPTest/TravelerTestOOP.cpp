#include "TravelerTestOOP.h"

#include <iostream>
#include <vector>
#include <unordered_set>



struct Road
{
	class City* destination;
	int distance;
};



class City
{
public:
	City() {}

	void AddRoad(struct Road road) 
	{
		roads.push_back(road);
	}

	std::vector<struct Road> roads;
};



class Traveler
{
public:
	Traveler() {}

	void AddCity(class City* city)
	{
		cities.push_back(city);
		cities_to_travel.insert(city);
	}

	int Travel(class City* start);

private:
	std::vector<class City*> cities;
	std::unordered_set<class City*> cities_to_travel;
};


int Traveler::Travel(City* start)
{
	cities_to_travel.erase(start);
	City* current_pos = start;
	int distance_traveled = 0;

	while (1)
	{
		std::vector<Road> roads_available = current_pos->roads;
		std::vector<Road> roads_desirable;

		if (roads_available.empty()) return -1;

		for (Road road : roads_available)
		{
			auto city = cities_to_travel.find(road.destination);
			if (city != cities_to_travel.end())
			{
				roads_desirable.push_back(road);
			}
		}

		if (roads_desirable.empty())
		{
			roads_desirable = roads_available;
		}

		Road best_road = roads_desirable[0];
		for (Road road : roads_desirable)
		{
			if (road.distance < best_road.distance)
			{
				best_road = road;
			}
		}

		current_pos = best_road.destination;
		distance_traveled += best_road.distance;
		cities_to_travel.erase(current_pos);

		if (cities_to_travel.empty())
		{
			if (current_pos == start)
			{
				return distance_traveled;
			}
			else
			{
				cities_to_travel.insert(start);
			}
		}
	}
}




void TravelerTestOOP::Execute()
{
	std::cout << "Executing object oriented programming test with the traveller.\n";
	std::cout << "--------------------------------------------------------------\n\n";


	City* A = new City();
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


	int min_dist = traveler.Travel(D);
	std::cout << "The minimum distance for going through each city (starting and finishing on city D) is " << min_dist << ".\n\n";


	delete A;
	delete B;
	delete C;
	delete D;
	delete E;
}
