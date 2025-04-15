CXX = g++
CXXFLAGS = -std=c++20 -Wall -g

TARGET = compiler
SRCS = mycalc.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(OBJS) $(TARGET)
	@echo "Cleaned up the object files and the target executable."