//
// Created by kgaft on 10/23/23.
//
#pragma once

#include <string>

class Route {
public:
    Route(const std::string &routeBase);
    Route();

private:
    std::string routeBase;
public:
    bool compare(char* src);
    bool isIn(char* src);

    const std::string &getRouteBase() const;

    void setRouteBase(const std::string &routeBase);
};



