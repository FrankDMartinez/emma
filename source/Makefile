# The compiled
CXX=clang++
# Compiler flags
CXX_FLAGS=-c -Wall -O3 -std=c++11
# Sources
SOURCES=EMMA.cpp \
        Copyright.cpp \
        Data.cpp \
        Introduction.cpp \
        License.cpp \
        RequestedInformation.cpp \
        Results.cpp \
        Title.cpp
# Object files
OBJECTS=$(SOURCES:.cpp=.o)
# Resultant binary
BINARY=emma

all: $(SOURCES) $(BINARY)

$(BINARY): $(OBJECTS)
		$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
		$(CXX) $(CXX_FLAGS) $< -o $@

clean:
		rm *.o emma
