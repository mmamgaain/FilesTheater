
CC=g++
SRC_FILES=$(shell find src/ -type f -name "*.cpp")
ENC_SRC_FILES=$(shell find src/encoder/ -type f -name "*.cpp")
ENCODER_OUT=encoder
O_LEVEL=O2

run_encoder_test: compile_encoder
	./$(ENCODER_OUT)

compile_encoder:
	$(CC) -$(O_LEVEL) -o $(ENCODER_OUT) $(ENC_SRC_FILES) ~/Housekeeping_Scripts/backup_scripts/autocmdrc.vim

compile_tests: compile_encoder
	$(CC) -$(O_LEVEL) -o main $(SRC_FILES)
