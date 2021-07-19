#pragma once

#include "ofMain.h"

class ofxFFSound {
public:
    void addFragment(string path_, float volume_ = 1, bool bRandomPan_ = false);
    void playFragment();
    void update();
    
    void addLong(string path_, float volume_, float length_);
    
    void multiPlay(float time_, string path_, float minInterval_, float maxInterval_, float minSpeed_, float maxSpeed_);
    
private:
    vector<ofSoundPlayer> fragments;
    
    vector<ofSoundPlayer> longs;
    vector<float> lengthes;
    vector<float> playedTimes;

    vector<ofSoundPlayer> sounds;
    float lastPlayedTime = 0;
    float interval = 0;
};
