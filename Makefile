CXXFLAGS := -std=c++11

all: main

# sample-graph.csv: collect_data.bash sample
# 	./collect_data.bash > sample-graph.csv

# test-run: sample
# 	./sample 100 3

main: main.cpp
	g++ $(CXXFLAGS) -o $@ $^

clean:
	-rm -f main
