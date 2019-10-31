#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>

#include "Song.h"
#include "UtPod.h"

using namespace std;
UtPod::UtPod(){
    songs = NULL;
    memSize = MAX_MEMORY;
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
    }


UtPod::UtPod(int size){
    songs = NULL;
    if(size > MAX_MEMORY || size <= 0){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = size;
    }
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
}

UtPod::~UtPod(){
// need to free songs
  clearMemory();
}


int UtPod::addSong(Song const &s){
  if (UtPod::getRemainingMemory() >= s.getSize()){
    SongNode *temp = new SongNode;
    temp->next = songs;
    songs = temp;
    temp->s.setTitle(s.getTitle());
    temp->s.setArtist(s.getArtist());
    temp->s.setSize(s.getSize());
    return 0;
  }
  else{
    return 1;
  }
}



int UtPod::removeSong(Song const &s){
    if(songs == NULL){
      return 1;
    }
    else{
      SongNode *ptr = songs;
      if (ptr->s == s){
        //(ptr->s.getTitle() == s.getTitle()) && (ptr->s.getArtist() == s.getArtist()) && (ptr->s.getSize() == s.getSize())
        SongNode *temp = songs;
        songs = songs->next;
        delete temp;
        return 0;
      }
      else{
        SongNode *ptr2 = songs->next;
        while (ptr2 != NULL) {
          if(ptr2->s == s){
            //(ptr2->s.getTitle() == s.getTitle()) && (ptr2->s.getArtist() == s.getArtist()) && (ptr2->s.getSize() == s.getSize())
            ptr->next = ptr2->next;
            delete ptr2;
            return 0;
          }
          ptr = ptr->next;
          ptr2 = ptr2->next;
        }
      }
      return 1;
     }
}



void UtPod::shuffle(){
  if(songs == NULL){
    return;
  }
  else{
    int size = 0;
    SongNode *ptr = songs;
    while(ptr != NULL){
      size++;
      ptr = ptr->next;
    }
    ptr = songs;
    for(int i = 0; i <= size && ptr != NULL; i++){
     ptr->s.swap(randomNode(size)->s);
     ptr = ptr->next;
    }
  }

}

UtPod::SongNode* UtPod::randomNode(int size){
  SongNode *ptr = songs;
  int count = rand()%size;
  while(count != 0){
    ptr = ptr->next;
    count--;
  }
  return ptr;
}





void UtPod::showSongList(){
    if(songs == NULL){
        cout<<"list is empty"<<endl;
    }
    else{
        SongNode *ptr = songs;
        while(ptr != NULL){
            cout << ptr->s << endl;
            ptr = ptr->next;
        }
    }
}


// bubble sort
//referenced https://www.geeksforgeeks.org/c-program-bubble-sort-linked-list/

void UtPod::sortSongList(){
  if ((songs == NULL) || (songs->next == NULL)){
    return;
  }
  SongNode *ptr;
  bool swapped = true;
  while(swapped){
    swapped = false;
    ptr = songs;
    while(ptr->next != NULL){
      if(ptr->next->s < ptr->s){
        //swap(ptr, ptr->next);
        ptr->s.swap(ptr->next->s);
        swapped = true;
      }
      ptr = ptr->next;
    }
  }
}

// void UtPod::swap(SongNode *first, SongNode *second){
//   Song temp = first->s;
//   first->s = second->s;
//   second->s = temp;
// }
void UtPod::clearMemory(){
  if(songs == NULL){
    return;
  }
  else{
    SongNode *ptr = songs;
    while(ptr != NULL){
      SongNode *temp = ptr;
      ptr = ptr->next;
      delete temp;
    }
    songs = ptr;
  }
}



int UtPod::getRemainingMemory(){
    int curSize = 0;
    if(songs == NULL){
        return memSize;
    }
    else{
        SongNode *ptr = songs;
        while(ptr != NULL){
            curSize += ptr->s.getSize();
            ptr = ptr->next;
        }
    }
    return memSize - curSize;
}
