//
// Created by kgaft on 10/23/23.
//
#pragma once

#include <vector>
#include "Route.h"
#include "Param.hpp"

class Request {
public:
    Request(char *data);

private:
    Route route;
    unsigned int id;
    std::vector<Param> params;
public:
    Route &getRoute();

    unsigned int getId();

    std::vector<Param> &getParams();
};

