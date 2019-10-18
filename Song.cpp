#include <cstdlib>
#include <iostream>
#include "Song.h"

using namespace std;

Song::Song(){

}
Song::Song(std::string insertTitle, std::string insertArtist, int insertSize){
    title = insertTitle;
    artist = insertArtist;
    size = insertSize;

}

void Song::setTitle(std::string insertTitle){
    title = insertTitle;
}
void Song::setArtist(std::string insertArtist){
    artist = insertArtist;
}
void Song::setSize(int insertSize){
    size = insertSize;
}