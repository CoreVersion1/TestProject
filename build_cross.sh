#!/bin/bash

cmake -B ./build -S . -DUSE_CROSS_COMPILE=ON && cmake --build ./build -j
