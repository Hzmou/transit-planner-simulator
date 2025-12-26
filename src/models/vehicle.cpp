/* Full implementation of the Vehicle class.*/

#include "models/Vehicle.h"

using namespace std;

namespace transit
{

    // public constructor of the vehicle class.

    Vehicle::Vehicle(Id id, string label, uint32_t capacity)
        : id_(id), label_(move(label)), capacity_(capacity), route_(nullptr), route_index_(0)
    {
    }
    Vehicle::Id Vehicle::id() const noexcept
    {
        return id_;
    }


    const string &Vehicle::label() const noexcept{
        return label_;
    }

     uint32_t  Vehicle::capacity() const noexcept{
        return capacity_;
    }

    size_t Vehicle::route_index() const noexcept{
        return route_index_;
    }
    
    void Vehicle:: assign_route(const Route* route){
        route_ = route;
        route_index_ = 0; // reset route index when assigning a new route   
    }
    void Vehicle:: assign_route(const Route* route){
       route_ = route;
      route_index_ =0;   

    }

    const Route* Vehicle::route() const noexcept{
        return route_;
    }

    




}