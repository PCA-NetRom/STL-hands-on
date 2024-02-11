#include "Unordered.h"

#include <iostream>
#include <unordered_set>
#include <unordered_map>

struct Vehicle
{
	std::string make;
	std::string model;
	int productionDate;
    
    // Needed to be able to use Vehicle in unordered_map
    bool operator==(const Vehicle& other) const
    {
        return make == other.make && model == other.model && productionDate == other.productionDate;
    }
};

// Needed to be able to use Vehicle in unordered_map
namespace std {
    template <>
    struct hash<Vehicle>
    {
        std::size_t operator()(const Vehicle& v) const
        {
            // Bad hash, creates collisions
            return hash<string>()(v.make);

            // Use a combination of the hash values of individual members
            //return hash<string>()(v.make) ^ (hash<string>()(v.model) << 1) ^ (hash<int>()(v.productionDate) << 2);
        }
    };
}

void unorderedMap()
{
    std::unordered_map<Vehicle, int> vehiclePrices;
    vehiclePrices.insert({ { "Acura", "NSX", 2017 }, 120000 });
    vehiclePrices.insert({ { "VW", "Passat", 2005 }, 3000 });
    vehiclePrices.insert({ { "VW", "Tiguan", 2018 }, 23000 });
    vehiclePrices.insert({ { "Dacia", "Sandero", 2019 }, 10000 });

    // Elements are stored in buckets
    std::cout << "Max bucket count: " << vehiclePrices.bucket_size(vehiclePrices.bucket({ "VW", "Passat", 2005 })) << std::endl;
}

void unorderedSet()
{
    std::unordered_set<Vehicle> vehicleSet;
    vehicleSet.insert({ "Acura", "NSX", 2017 });
    vehicleSet.insert({ "VW", "Passat", 2005 });
    vehicleSet.insert({ "VW", "Passat", 2005 });
    vehicleSet.insert({ "VW", "Tiguan", 2018 });
    vehicleSet.insert({ "Dacia", "Sandero", 2019 });

    // Elements are stored in buckets
    std::cout << "Max bucket count: " << vehicleSet.bucket_size(vehicleSet.bucket({ "VW", "Passat", 2005 })) << std::endl;
}

void unorderedMain()
{
    unorderedMap();

    //unorderedSet();
}