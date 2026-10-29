#!/bin/bash

sudo apt update
sudo apt install -y g++

export PORT=8080
export AMBIENTE=producao

g++ main.cpp -o app
./app
