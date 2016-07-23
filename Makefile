
TARGET = template

SRC_PATH = ./src/
INC_PATH = ./inc/
OBJ_PATH = ./build/obj/
TARGET_PATH = ./build/bin/

CFLAGS = -std=c++14 -MD

source = $(wildcard $(SRC_PATH)*.cpp)
object = $(patsubst $(SRC_PATH)%.cpp, $(OBJ_PATH)%.o, $(source)) 

all: create_folder build 

create_folder:
	@mkdir -p ./build/obj/
	@mkdir -p ./build/bin/

build: $(TARGET_PATH)$(TARGET)

$(TARGET_PATH)$(TARGET): $(object)
	@g++ -pthread $^ -o $@
 
$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@g++ -c $(CFLAGS) $< -o $@ -I$(INC_PATH)

include $(wildcard $(OBJ_PATH)*.d) 

clean: 
	@rm -rf $(TARGET_PATH) $(OBJ_PATH)
