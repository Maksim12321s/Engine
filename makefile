BUILD_DIR = build
EXEC_PROG = engine
.PHOPY: build clean run


all: build

build:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..
	cmake --build $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

run: build
		./$(BUILD_DIR)/engine

rebuild: clean build