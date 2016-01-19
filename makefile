CXX     = g++
CFLAGS  = -W -Wall -g -std=c++11
TARGET  = util.out
SRCDIR  = .
SOURCES = $(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/*.s)
OBJS    = $(patsubst %.cpp,%.o,$(SOURCES))
LDFLAG  =
INCLUDE = -I. -I../include
EXTLIBS = -L../lib

%.o:%.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAG) $(EXTLIBS) $(INCLUDE)

clean:
	rm -f *.o $(TARGET)
