TARGET = web_api

all: TARGET

TARGET: clean
	@rm -rf build && mkdir build
	em++ -std=c++20 web_api.cpp -lutil -Llib -Iinclude --no-entry -o $(TARGET).js
	@cp $(TARGET).wasm ./build
	@cp $(TARGET).js ./build
	@cp index.html ./build

serve:
	python -m SimpleHTTPServer

dump:
	wasm2wat $(TARGET).wasm -o $(TARGET).wat

clean:
	@rm -rf *.wasm *.wat build web_api.js
