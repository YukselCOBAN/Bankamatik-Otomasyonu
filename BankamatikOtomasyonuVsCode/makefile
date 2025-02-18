hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/MusteriBilgi.o -c ./src/MusteriBilgi.cpp
	g++ -I ./include/ -o ./lib/YetkiliIslem.o -c ./src/YetkiliIslem.cpp
	g++ -I ./include/ -o ./lib/MusteriIslem.o -c ./src/MusteriIslem.cpp
	g++ -I ./include/ -o ./lib/AnaMenu.o -c ./src/AnaMenu.cpp
	g++ -I ./include/ -o ./bin/main ./lib/MusteriBilgi.o ./lib/YetkiliIslem.o ./lib/MusteriIslem.o ./lib/AnaMenu.o ./src/main.cpp


calistir:
	./bin/main
