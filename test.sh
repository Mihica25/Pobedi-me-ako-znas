#!/bin/bash

# Postavke
SERVER_DIR="/home/tamara/Desktop/pobedi-me-ako-znas/server/build-server-Desktop_Qt_5_12_12_GCC_64bit-Debug"
APPLICATION_DIR="/home/tamara/Desktop/pobedi-me-ako-znas/build-application-Desktop_Qt_5_12_12_GCC_64bit-Debug"

# Kompajliranje i pokretanje servera
cd "$SERVER_DIR" || exit
make
xterm  -e bash -c "./server" &

# Kompajliranje i pokretanje prve aplikacije
cd "$APPLICATION_DIR" || exit
make
xterm  -e bash -c "./application" &

# Kompajliranje i pokretanje druge aplikacije
xterm  -e bash -c  "./application" &
