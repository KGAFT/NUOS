//
// Created by kgaft on 10/23/23.
//
#pragma once

#include <map>
#include "Route.h"
#include "Param.hpp"

class Request {
private:
    Route route;
    unsigned int id;
    std::map<Param> params;

};

