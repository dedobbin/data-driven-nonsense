GCC=g++
OBJ = behavior_component.o entity.o game.o visuals.o action.o sdl_utils.o pos_component.o sprite_component.o physics_component.o gravity_component.o collision_component.o observer.o input.o
COMPILER_FLAGS = -g -w
LINKER_FLAGS = -lSDL2 -lSDL2_ttf  -lSDL2_image -lSDL2_mixer -ldump_lib

all: main.cpp $(OBJ)
	$(GCC) main.cpp  $(OBJ) $(COMPILER_FLAGS) $(LINKER_FLAGS)

game.o: game.cpp game.hpp
	$(GCC) -c game.cpp $(COMPILER_FLAGS)

behavior_component.o: behavior_component.cpp behavior_component.hpp
	$(GCC)  -c behavior_component.cpp $(COMPILER_FLAGS)

entity.o: entity.cpp entity.hpp
	$(GCC) -c entity.cpp $(COMPILER_FLAGS)

visuals.o: visuals.cpp visuals.hpp
	$(GCC) -c visuals.cpp $(COMPILER_FLAGS)

observer.o: observer.cpp observer.hpp
	$(GCC) -c observer.cpp $(COMPILER_FLAGS)

action.o: action.cpp action.hpp
	$(GCC) -c action.cpp $(COMPILER_FLAGS)

input.o: input.cpp input.hpp
	$(GCC) -c input.cpp $(COMPILER_FLAGS)

sdl_utils.o: sdl_utils.cpp sdl_utils.hpp
	$(GCC) -c sdl_utils.cpp $(COMPILER_FLAGS)

pos_component.o: pos_component.cpp pos_component.hpp
	$(GCC) -c pos_component.cpp $(COMPILER_FLAGS)

sprite_component.o: sprite_component.cpp sprite_component.hpp
	$(GCC) -c sprite_component.cpp $(COMPILER_FLAGS)

physics_component.o: physics_component.cpp physics_component.hpp
	$(GCC) -c physics_component.cpp $(COMPILER_FLAGS)

gravity_component.o: gravity_component.cpp gravity_component.hpp
	$(GCC) -c gravity_component.cpp $(COMPILER_FLAGS)

collision_component.o: collision_component.cpp collision_component.hpp
	$(GCC) -c collision_component.cpp $(COMPILER_FLAGS)

clean:
	-rm -f *.o *.a a.out