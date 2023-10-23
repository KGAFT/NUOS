//
// Created by kgaft on 10/23/23.
//

#include "Route.h"

#include <Util/StringUtils.h>
#include <cstring>

Route::Route(const std::string &routeBase) : routeBase(routeBase) {}

bool Route::compare(char *src) {
    return !strcmp(src, routeBase.c_str());
}

bool Route::isIn(char *src) {
    return StringUtils::contains(src, const_cast<char *>(routeBase.c_str()));
}
