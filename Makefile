TARGET = web_api
SRC = api.cpp web_api.cpp

all: TARGET

TARGET: clean
	em++ -std=c++20 $(SRC) --no-entry -o $(TARGET).js

serve:
	python -m SimpleHTTPServer

dump:
	wasm2wat $(TARGET).wasm -o $(TARGET).wat

clean:
	@rm -rf *.wasm *.js *.wat
