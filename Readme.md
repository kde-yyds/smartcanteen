# About this project
An open source food ordering program designed for Chinese schools.  
# Project structure
This project is based on QT, an open source and cross platform graphical library.  
It is developed on Archlinux. It works on all GNU/Linux distributions. Not tested on Windows and Macos.
## Directories
### ./smartcanteen-client
Client program to order foods. It should be run on the computer in a classroom. It should compile and work on all platforms.
### ./smartcanteen-server
Proram to run on the server to edit food list and view orders uploaded form multiple clients.
# Building and  testing
Only tested on GNU/Linux.
## Dependences
```
QT
libboost
openssh (binary)
sshpass (binary)
```
## Clone the repository
```
git clone https://github.com/kde-yyds/smartcanteen
cd smartcanteen
```
## Build the server program
```
cd smartcanteen/smartcanteen-server
mkdir build
cd build
cmake ..
make -j16
sudo make install
```
## Build the client program
```
cd ../../smartcanteen-client
mkdir build
cd build
cmake ..
make -j16
sudo make install
```

## Requirments
see comments in smartcanteen-server/path.h
