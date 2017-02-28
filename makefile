BLD_DIR := bld_dir
SRC_DIR := $(shell pwd)/src
.PHONY: all clean

all:
	mkdir -p $(BLD_DIR)
	cp -sf $(SRC_DIR)/* $(BLD_DIR)
	$(MAKE) -C $(BLD_DIR)
	cp $(BLD_DIR)/pong .

clean:
	rm -rf $(BLD_DIR) pong
