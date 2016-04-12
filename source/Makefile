# The compiled
CXX=clang++
# Compiler flags
CXX_FLAGS=-pedantic -c -Wall -O3 -std=c++14
# Sources
SOURCES=EMMA.cpp \
        Copyright.cpp \
        Data.cpp \
        docopt/docopt.cpp \
        GivenData.cpp \
        IndividualElectionStatistics.cpp \
        Introduction.cpp \
        License.cpp \
        OverviewStatistics.cpp \
        Printing.cpp \
        RequestedInformation.cpp \
        Results.cpp \
        RunMode.cpp \
        RunState.cpp \
        StatisticsRequired.cpp \
        Title.cpp \
        TranslateOption.cpp
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
