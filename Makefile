.SUFFIXES: .cpp .o

CXX			= g++
CXXFLAGS	= -g -Wall
TARGET		= app

INC		= -Iinclude

OBJS		= main.o ./include/timer.o ./include/bin.o
# HEAD		= timer.h arr.h
SRCS 		= $(OBJS:.o=.cpp)

# LIBS		= -lprint -larr -ltimer
# LIBS_DIRS	= -L./lib

# .cpp.o:
# 	$(CXX) $(CXXFLAGS) -c $< 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(INC)

# main.o: main.cpp $(HEAD)
# timer.o: timer.cpp
# arr.o: arr.cpp

# dep:
# 	gccmakedep $(INC) $(SRCS)

clean:
	rm -rf $(OBJS)

# DO NOT DELETE
