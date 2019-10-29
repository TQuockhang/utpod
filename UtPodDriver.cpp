/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
//test adding
  cout << "testing adding" << endl;
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();


    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "result = " << result << endl;
    cout << "memory = " << t.getRemainingMemory() << endl;

    cout << "should fail here" << endl;

    Song s6("Beatles", "Hey Jude5", 512);
    result = t.addSong(s6);
    cout << "result = " << result << endl;
    cout << "memory = " << t.getRemainingMemory() << endl;
    Song s7("Beatles", "Hey Jude5", 700);
    result = t.addSong(s7);
    cout << "result = " << result << endl;
    cout << "memory = " << t.getRemainingMemory() << endl;
    t.showSongList();


  cout << "===================================" << endl;

  cout << "testing remove" << endl;
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    t.showSongList();


    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
    t.showSongList();


    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    t.showSongList();


    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    cout << "should fail here" << endl;

        result = t.removeSong(s5);
        cout << "delete result = " << result << endl;
        t.showSongList();


        result = t.removeSong(s4);
        cout << "delete result = " << result << endl;

        t.showSongList();
        cout << "memory = " << t.getRemainingMemory() << endl;


    cout << "===================================" << endl;

    cout << "testing clear memory" << endl;
      result = t.addSong(s1);
      cout << "result = " << result << endl;

      t.showSongList();

      result = t.addSong(s2);
      cout << "result = " << result << endl;

      result = t.addSong(s3);
      cout << "result = " << result << endl;

      result = t.addSong(s4);
      cout << "result = " << result << endl;

      result = t.addSong(s5);
      cout << "result = " << result << endl;
      cout << "memory = " << t.getRemainingMemory() << endl;

      cout <<"after clear" << endl;
      // t.clearMemory();
      // t.showSongList();

      // t.clearMemory();
      // t.showSongList();

      cout << "memory = " << t.getRemainingMemory() << endl;

    cout << "===================================" << endl;


    cout << "testing sorting" << endl;
    cout << "1 element sort" << endl;

    t.addSong(s1);
    t.sortSongList();
    t.showSongList();

    cout << "2 element sort" << endl;
    t.addSong(s2);
    t.sortSongList();
    t.showSongList();

    cout << "multiple element sort" << endl;
    t.addSong(s4);
    t.addSong(s3);
    t.addSong(s5);
    t.sortSongList();
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;


    cout << "===================================" << endl;
    cout << "testing shuffle" << endl;
    t.showSongList();

    cout << "first shuffle"<< endl;
    t.shuffle();
    t.showSongList();
    cout << "second shuffle"<< endl;
    t.shuffle();
    t.showSongList();
    cout << "third shuffle"<< endl;
    t.shuffle();
    t.showSongList();
    cout << "===================================" << endl;



}
