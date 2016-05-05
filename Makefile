TARGET = game 

##########################################################"

CFLAGS = -g -O2 -Wall -Werror `pkg-config --cflags MLV`
LDFLAGS=
LDLIBS = `pkg-config --libs MLV`
SRC = print.c vaisseau.c ennemi.c missile.c main.c move.c
OBJ = $(SRC:.c=.o)


all: $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LDLIBS) 

# game: print.o main.o
# 	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

# print.o: print.c
# 	$(CC) -o $@ -c $< $(CFLAGS) $(LDLIBS)

# main.o: main.c print.h
# 	$(CC) -o $@ -c $< $(CFLAGS) $(LDLIBS)

clean:
	-rm -rf $(TARGET)

#   This file is part of the MLV Library.
#
#   Copyright (C) 2010,2011,2012,2013 Adrien Boussicault, Marc Zipstein
#
#
#    This Library is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This Library is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this Library.  If not, see <http://www.gnu.org/licenses/>.
