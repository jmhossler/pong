BLD_DIR := bld_dir
SRC_DIR := $(shell pwd)/src
.PHONY: all clean

all:
	mkdir -pv $(BLD_DIR)
	cp -sfv $(SRC_DIR)/* $(BLD_DIR)
	$(MAKE) -C $(BLD_DIR)
	cp -v $(BLD_DIR)/pong .

clean:
	rm -rf $(BLD_DIR) pong
