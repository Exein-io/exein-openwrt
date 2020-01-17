#
# Copyright (C) 2019 Exein
#
# This is free software, licensed under the GNU General Public License v3.
# See /LICENSE for more information.
#

PROJECT_BINARY_NAME = eigen-test
PROJECT_SOURCES = eigen.cc


all:	$(PROJECT_BINARY_NAME)

$(PROJECT_BINARY_NAME):	$(PROJECT_SOURCES)
	$(CXX) -std=c++11 -I /usr/include/eigen3/ $(CXXFLAGS) $(PROJECT_SOURCES) -o $(PROJECT_BINARY_NAME)


clean:
	rm -f $(PROJECT_BINARY_NAME)
