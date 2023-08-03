
CC=g++
SRC_FILES=$(shell find src/ -type f -name "*.cpp")
ENC_SRC_FILES=$(shell find src/encoder/ -type f -name "*.cpp")
ENCODER_OUT=encoder
O_LEVEL=O2

run_encoder_test: compile_encoder
	./$(ENCODER_OUT) "/home/mayank/Downloads/American Psycho (2000)/American.Psycho.2000.720p.BrRip.x264.YIFY.mp4"

update_avcpp:
	bash scripts/build_avcpp.sh

compile_encoder:
	$(CC) -$(O_LEVEL) -o $(ENCODER_OUT) $(ENC_SRC_FILES)

compile_tests: compile_encoder
	$(CC) -$(O_LEVEL) -o main $(SRC_FILES)
