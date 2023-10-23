//
// Created by kgaft on 10/23/23.
//
#include <string>

enum NUParamType{
    NU_INTEGER_TYPE,
    NU_LONG_TYPE,
    NU_DOUBLE_TYPE,
    NU_STRING_TYPE,
    NU_BLOB_TYPE
};

template <typename T> class Param {
public:
    Param(NUParamType paramType, T data, const std::string &paramName) : paramType(paramType), data(data),
                                                                         paramName(paramName) {}

private:
    NUParamType paramType;
    T data;
    std::string paramName;
public:
    T getData() {
        return data;
    }

    NUParamType getParamType()  {
        return paramType;
    }

    std::string &getParamName()  {
        return paramName;
    }
};
