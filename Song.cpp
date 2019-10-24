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

Song::~Song(){

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

bool Song::operator == (Song const &rhs){

  if((artist == rhs.getArtist()) && (title == rhs.getTitle()) && (size == rhs.getSize())){
    return true;
  }
    return false;

}
