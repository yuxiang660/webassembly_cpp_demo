TARGET = web_api

all: TARGET

TARGET: clean
	em++ -std=c++20 web_api.cpp -lutil -Llib -Iinclude --no-entry -o $(TARGET).wasm

serve:
	python -m SimpleHTTPServer

dump:
	wasm2wat $(TARGET).wasm -o $(TARGET).wat

clean:
	@rm -rf *.wasm *.wat
