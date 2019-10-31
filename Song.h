#include <cstdlib>
#include <iostream>

#ifndef SONG_H
#define SONG_H
class Song
{
private:
    std::string artist;
    std::string title;
    int size;

public:
    Song();
    Song(std::string insertArtist, std::string insertTitle, int insertsize);

    /*
    set title
    inputs string
    returns nothing
    */
    void setTitle(std::string);
    /*
    set artist
    inputs string 
    returns nothing
    */
    void setArtist(std::string);

  /*
  set size
  inputs ints
  returns nothing
  */
    void setSize(int);
  /*
    get title
    no inputs
    returns string
  */
    std::string getTitle() const
        {return title;}
/*
  get Artist
  no inputs
  returns string
*/
    std::string getArtist() const
        {return artist;}

/*get size
no inputs
return size*/
    int getSize() const
        {return size;}


    void swap(Song &second);


    /*bool operator overloads
    artist takes prority
    then it looks at title if the artist is the same
    and lastly it looks at size
    */

    bool operator == (Song const &rhs);

    bool operator > (Song const &rhs);

    bool operator < (Song const &rhs);

    bool operator <= (Song const &rhs);

    bool operator >= (Song const &rhs);



  };
std::ostream& operator << (std::ostream& out, const Song &s);


#endif
