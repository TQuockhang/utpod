#include <cstdlib>
#include <iostream>
#include "Song.h"

using namespace std;

Song::Song(std::string insertTitle, std::string insertArtist, int insertSize){
    title = insertTitle;
    artist = insertArtist;
    size = insertSize;

}

Song::~Song(){
//  cout << "debug: in " << song << "right now" << endl;
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

  return((artist == rhs.artist) && (title == rhs.title) && (size == rhs.size));


}

bool Song::operator > (Song const &rhs){
  if(!(artist == rhs.artist)){

  }
  else if(!(title == rhs.title)){

  }
  else if(!(size == rhs.size)){
    return (size > rhs.size);
  }
  return false;
}

bool Song::operator < (Song const &rhs){
  if(!(artist == rhs.artist)){

  }
  else if(!(title == rhs.title)){

  }
  else if(!(size == rhs.size)){
    return (size > rhs.size);
  }

  return false;

}
