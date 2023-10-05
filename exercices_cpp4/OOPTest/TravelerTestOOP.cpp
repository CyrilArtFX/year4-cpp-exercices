#include "TravelerTestOOP.h"

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>



struct Road
{
	class City* origin;
	class City* destination;
	int distance;
};


struct Plan
{
	std::vector<City*> cities_path;
	int distance;
};


struct Possibility
{
	std::vector<City*> cities_to_travel;
};



class City
{
public:
	City(std::string _name) : name(_name) {}

	void AddRoad(struct Road road) 
	{
		roads.push_back(road);
	}

	std::vector<struct Road> roads;
	std::string name{ "" };
};



class Traveler
{
public:
	Traveler() {}

	void AddCity(class City* city)
	{
		cities.push_back(city);
	}

	void Travel(class City* start);

private:
	std::vector<class City*> cities;
};


void Traveler::Travel(City* start)
{
	std::vector<Possibility> possibilities;


	std::vector<City*> cities_remaining_1 = cities;
	auto iter_1 = std::find(cities_remaining_1.begin(), cities_remaining_1.end(), start);
	if (iter_1 != cities_remaining_1.end())
	{
		std::iter_swap(iter_1, end(cities_remaining_1) - 1);
		cities_remaining_1.pop_back();
	}


	//  fill possibilities (the way I do this only works with 5 cities)
	for (auto city_1 : cities_remaining_1)
	{
		std::vector<City*> cities_remaining_2 = cities_remaining_1;
		auto iter_2 = std::find(cities_remaining_2.begin(), cities_remaining_2.end(), city_1);
		if (iter_2 != cities_remaining_2.end())
		{
			std::iter_swap(iter_2, end(cities_remaining_2) - 1);
			cities_remaining_2.pop_back();
		}

		for (auto city_2 : cities_remaining_2)
		{
			std::vector<City*> cities_remaining_3 = cities_remaining_2;
			auto iter_3 = std::find(cities_remaining_3.begin(), cities_remaining_3.end(), city_2);
			if (iter_3 != cities_remaining_3.end())
			{
				std::iter_swap(iter_3, end(cities_remaining_3) - 1);
				cities_remaining_3.pop_back();
			}

			for (auto city_3 : cities_remaining_3)
			{
				std::vector<City*> cities_remaining_4 = cities_remaining_3;
				auto iter_4 = std::find(cities_remaining_4.begin(), cities_remaining_4.end(), city_3);
				if (iter_4 != cities_remaining_4.end())
				{
					std::iter_swap(iter_4, end(cities_remaining_4) - 1);
					cities_remaining_4.pop_back();
				}

				std::vector<City*> poss_cities{ start, city_1, city_2, city_3, *cities_remaining_4.begin(), start};

				possibilities.push_back({ poss_cities });
			}
		}
	}


	//  create plans
	std::vector<Plan> plans;
	for (Possibility possibility : possibilities)
	{
		//  check if possibility is realisable
		bool realisable = true;
		int plan_distance = 0;

		for (int i = 0; i < possibility.cities_to_travel.size() - 1; i++)
		{
			bool city_check = false;
			for (Road road : possibility.cities_to_travel[i]->roads)
			{
				if (road.destination == possibility.cities_to_travel[i + 1])
				{
					city_check = true;
					plan_distance += road.distance;
					break;
				}
			}
			if (!city_check)
			{
				realisable = false;
				break;
			}
		}

		if (!realisable) continue;


		//  store the possibility in a plan
		plans.push_back({ possibility.cities_to_travel, plan_distance });
	}


	//  find the shortest plan
	if (plans.empty())
	{
		std::cout << "The traveler could not find a way :(\n\n";
		return;
	}

	Plan shortest_plan = plans[0];
	for (Plan plan : plans)
	{
		if (plan.distance < shortest_plan.distance)
		{
			shortest_plan = plan;
		}
	}


	//  write the shortest plan
	std::cout << "\n\nOne of the shortest plan to travel through all cities, starting and ending on city " << start->name << " is :  ";
	for (int i = 0; i < shortest_plan.cities_path.size(); i++)
	{
		std::cout << shortest_plan.cities_path[i]->name;
		if (i < shortest_plan.cities_path.size() - 1)
		{
			std::cout << " -> ";
		}
	}
	std::cout << "  and it's total distance is " << shortest_plan.distance << ".\n\n";
}




void TravelerTestOOP::Execute()
{
	std::cout << "Executing object oriented programming test with the traveler. (Using brute force)\n";
	std::cout << "---------------------------------------------------------------------------------\n\n";


	City* A = new City("A");
	City* B = new City("B");
	City* C = new City("C");
	City* D = new City("D");
	City* E = new City("E");

	A->AddRoad(Road{ A, B, 2 });
	A->AddRoad(Road{ A, C, 2 });

	B->AddRoad(Road{ B, A, 2 });
	B->AddRoad(Road{ B, C, 3 });
	B->AddRoad(Road{ B, D, 3 });
	B->AddRoad(Road{ B, E, 1 });

	C->AddRoad(Road{ C, A, 2 });
	C->AddRoad(Road{ C, B, 3 });
	C->AddRoad(Road{ C, D, 1 });
	C->AddRoad(Road{ C, E, 3 });

	D->AddRoad(Road{ D, B, 3 });
	D->AddRoad(Road{ D, C, 1 });
	D->AddRoad(Road{ D, E, 3 });

	E->AddRoad(Road{ E, B, 1 });
	E->AddRoad(Road{ E, C, 3 });
	E->AddRoad(Road{ E, D, 3 });


	Traveler traveler;

	traveler.AddCity(A);
	traveler.AddCity(B);
	traveler.AddCity(C);
	traveler.AddCity(D);
	traveler.AddCity(E);


	//  you can change the starting city here
	traveler.Travel(D);


	delete A;
	delete B;
	delete C;
	delete D;
	delete E;
}
