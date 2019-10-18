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


int UtPod::addSong(Song const &s){

        SongNode *temp = new SongNode;
        temp->next = songs;
        songs = temp;
        temp->s.setTitle(s.getTitle());
        temp->s.setArtist(s.getArtist());
        temp->s.setSize(s.getSize()); 
        return 0;
    

}



int UtPod::removeSong(Song const &s){
    return 0;

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
            cout << ptr->s.getTitle()<< " by " << ptr->s.getArtist() << " size of: " << ptr->s.getSize() << endl;
            ptr = ptr->next;
        }
    }
}



void UtPod::sortSongList(){
    
}


void UtPod::clearMemory(){

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


UtPod::~UtPod(){

}