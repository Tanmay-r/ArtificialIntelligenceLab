CC=gcc
CXX=g++
RM=rm -f

SRCS=astar.cpp  main.cpp  state.cpp  state_list.cpp bidirection.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: tool

tool: $(OBJS)
	g++ -o astar $(OBJS)
	@mkdir -p objects
	@mv *.o objects

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend;
	$(CXX) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)
	$(RM) -rf objects
	$(RM) astar

dist-clean: clean
	$(RM) *~ .dependtool

include .depend
