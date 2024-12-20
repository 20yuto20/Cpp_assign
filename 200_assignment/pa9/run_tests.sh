#!/bin/bash
for i in {1..5}
do
    g++ app_prog$i.cpp RationalNumber.cpp -o prog$i
    ./prog$i
    echo "Press Enter to continue..."
    read
done