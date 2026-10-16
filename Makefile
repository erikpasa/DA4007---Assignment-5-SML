CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -MMD -MP

TARGET = slm
SOURCES = src/main.cpp src/reader.cpp src/writer.cpp
OBJECTS = $(SOURCES:.cpp=.o)
DEPS = $(OBJECTS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(TARGET) $(OBJECTS) $(DEPS)

.PHONY: all clean
