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
    Song(std::string insertTitle, std::string insertArtist, int insertsize);
    ~Song();

    void setTitle(std::string);
    void setArtist(std::string);
    void setSize(int);

    std::string getTitle() const
        {return title;}

    std::string getArtist() const
        {return artist;}

    int getSize() const
        {return size;}

    bool operator == (Song const &rhs);

    bool operator > (Song const &rhs);

    bool operator < (Song const &rhs);

  };

#endif
