#!bin/bash

docker rm try
docker image rm serv

docker build -t serv .
