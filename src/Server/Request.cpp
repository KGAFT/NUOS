//
// Created by kgaft on 10/23/23.
//

#include "Request.h"

#include <cstring>

int parseRequestId(char* data);

void parseRoute(char* data, Route& output);

void parseParams(char* data, std::vector<Param>& output);

Request::Request(char *data) {
    Request::id = parseRequestId(data);
    parseRoute(data, route);
    parseParams(data, params);
    free(data);
}

 Route &Request::getRoute()  {
    return route;
}

unsigned int Request::getId()  {
    return id;
}

 std::vector<Param> &Request::getParams()  {
    return params;
}

int parseRequestId(char* data){
    std::string idStr;
    size_t counter = 0;
    while(data[counter]!='/'){
        idStr+=data[counter];
        counter++;
    }
    return std::stoi(idStr);
}

void parseRoute(char* data, Route& output){
    std::string routeBase;
    size_t counter = 0;
    bool found = false;
    while(data[counter]!='\n'){
        if(data[counter]=='/'){
            found = true;
        }
        if(found){
            routeBase+=data[counter];
        }
        counter++;
    }
    output.setRouteBase(routeBase);
}

void parseParams(char* data, std::vector<Param>& output){
    size_t counter = 0;
    bool paramStarted = false;
    while(data[counter]!='\0'){
        if(data[counter]=='\n'){
            paramStarted = true;
            counter++;
            continue;
        }
        if(paramStarted){
            NUParamType paramType = (NUParamType) (data[counter]-48);
            std::string paramName;
            size_t dataSize = 0;
            counter++;
            while(data[counter]!=' '){
                paramName+=data[counter];
                counter++;
            }
            counter++;
            while(data[counter]!='\n'){
                dataSize++;
                counter++;
            }
            void* resData = calloc(dataSize, sizeof(char));
            std::memcpy(resData, &data[counter-dataSize], dataSize);
            output.push_back(Param(paramType, resData, paramName));
        }
        counter++;
    }
}