#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

UtPod::UtPod(){
    songs = NULL;
    memSize = MAX_MEMORY;
    }


UtPod::UtPod(int size){
    songs = NULL;
    if(size > MAX_MEMORY || size <= 0){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = size;
    }
}

UtPod::~UtPod(){
// need to free songs
  clearMemory();
}


int UtPod::addSong(Song const &s){
  if (UtPod::getRemainingMemory() <= memSize){
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




void UtPod::sortSongList(){
  if ((songs == NULL) || (songs->next == NULL)){
    return;
  }
  SongNode *ptr;
  SongNode *end = NULL;
  bool swapped = true;
  while(swapped){
    swapped = false;
    ptr = songs;
    while(ptr->next != end){
      if(ptr->next->s < ptr->s){
        swap(ptr, ptr->next);
        swapped = true;
      }
      ptr = ptr->next;
    }
    end = ptr;
  }
}

void UtPod::swap(SongNode *first, SongNode *second){
  Song temp = first->s;
  first->s = second->s;
  second->s = temp;
  showSongList();
}
// void UtPod::mergeSort(SongNode *header){
//   SongNode *first;
//   SongNode *second;
//   if (header == NULL || header->next == NULL){
//     return;
//   }
//   split(header, &first, &second);
//   //mergeSort(first);
//   //mergeSort(second);
//   //header = combine(&header, first, second);
// }
//
// void UtPod::split(SongNode *header, SongNode **first, SongNode **second){
//   SongNode *fast = header->next;
//   SongNode *slow = header;
//
//   while(fast->next != NULL){
//     fast = fast->next;
//     if(fast->next != NULL){
//       fast = fast->next;
//       slow = slow->next;
//     }
//   }
//   *first = header;
//   *second = slow;
// }
//
// SondNode* UtPod::combine(SongNode *header, SongNode *first, SongNode *second){
//   if(first == NULL){
//     return second;
//   }
//   if(second == NULL){
//     return first;
//   }
//    if(first->s <= second->s){
//
//    }
//    else if(second->s <= first->s){
//
//    }
//
//}

void UtPod::clearMemory(){
  if(songs == NULL){
    return;
  }
  else{
    SongNode *ptr = songs;
    while(ptr != NULL){
      SongNode *temp = ptr;
      delete temp;
      ptr = ptr->next;
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
