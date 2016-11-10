#!/bin/bash
g++ ./libmodbus.cpp -fPIC -shared -o ../ndll/Linux64/libmodbus.ndll -I../hxcpp/include -I/usr/include/modbus -L/usr/lib -lmodbus
