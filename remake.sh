#!/bin/sh

echo y | rm config.h
sudo make clean
sudo make install

