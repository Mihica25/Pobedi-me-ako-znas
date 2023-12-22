#!/bin/bash

# Postavke
SERVER_DIR="/home/user/pobedi-me-ako-znas/server/build-server-Desktop-Debug"
APPLICATION_DIR="/home/user/pobedi-me-ako-znas/build-application-Desktop-Debug"

# Kompajliranje i pokretanje servera
cd "$SERVER_DIR" || exit
make
qterminal  -e bash -c "./server" &

# Kompajliranje i pokretanje prve aplikacije
cd "$APPLICATION_DIR" || exit
make
qterminal  -e bash -c "./application" &

# Kompajliranje i pokretanje druge aplikacije
qterminal  -e bash -c  "./application" &
