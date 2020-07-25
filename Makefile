GCC=g++
OBJ = behavior_component.o entity.o gravity_component.o game.o
COMPILER_FLAGS = -g

all: main.cpp $(OBJ)
	$(GCC) main.cpp  $(OBJ) $(COMPILER_FLAGS)

game.o: game.cpp game.hpp
	$(GCC) -c game.cpp $(COMPILER_FLAGS)

behavior_component.o: behavior_component.cpp behavior_component.hpp
	$(GCC)  -c behavior_component.cpp $(COMPILER_FLAGS)

gravity_component.o: gravity_component.cpp gravity_component.hpp
	$(GCC) -c gravity_component.cpp $(COMPILER_FLAGS)

entity.o: entity.cpp entity.hpp
	$(GCC) -c entity.cpp $(COMPILER_FLAGS)

clean:
	-rm -f *.o *.a a.out