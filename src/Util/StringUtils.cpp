//
// Created by kgaft on 10/23/23.
//

#include <cstdlib>
#include "StringUtils.h"

bool StringUtils::contains(char *what, char *in) {
    size_t whatSize = 0;
    size_t counter = 0;
    while(in[counter]!='\0'){
        if(whatSize==0){
            bool found = true;
            while(what[whatSize]!='\0'){
                if(found){
                    found = what[whatSize]==in[whatSize];
                }
                whatSize++;
            }
            if(found){
                return true;
            }
        } else {
            bool found = true;
            for(size_t i = 0; i<whatSize; i++){
                found = what[i]==in[i+counter];
                if(!found){
                    break;
                }
            }
            if(found){
                return true;
            }
        }
        counter++;
    }
    return false;
}