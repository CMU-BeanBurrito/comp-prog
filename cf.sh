#!/bin/bash

mkdir CF/CF$1
cp cfstart.cpp CF/CF$1/$2.cpp

if [[ -n $4 ]]; then
    mkdir CF/CF$3
    cp cfstart.cpp CF/CF$3/$4.cpp
fi

if [[ -n $6 ]]; then
    mkdir CF/CF$5
    cp cfstart.cpp CF/CF$5/$6.cpp
fi

if [[ -n $8 ]]; then
    mkdir CF/CF$7
    cp cfstart.cpp CF/CF$7/$8.cpp
fi

if [[ -n ${10} ]]; then
    mkdir CF/CF$9
    cp cfstart.cpp CF/CF$9/${10}.cpp
fi


