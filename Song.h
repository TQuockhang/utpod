#include <cstdlib>
#include <iostream>

#ifndef SONG_H
#define SONG_H
class Song
{
private:
    std::string title;
    std::string artist;
    int size;

public:
    Song();
    Song(std::string insertTitle, std::string insertArtist, int insertsize);
    
    void setTitle(std::string);
    void setArtist(std::string);
    void setSize(int);

    std::string getTitle()
        {return title;}

    std::string getArtist()
        {return artist;}

    int getSize()
        {return size;}
};

#endif
