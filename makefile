final: UtPodDriver.o UtPod.o song.o
	g++ -o test  UtPodDriver.o UtPod.o song.o
UtPoddriver.o: UtPodDriver.cpp UtPod.h Song.h
	g++ -c UtPod_Driver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c UtPod.cpp
song.o: Song.cpp Song.h
	g++ -c Song.cpp
