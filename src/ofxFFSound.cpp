#include "ofxFFSound.h"

//--------------------------------------------------------------
void ofxFFSound::addFragment(string path_, float volume_, bool bRandomPan_) {
    
    fragments.push_back(ofSoundPlayer());
    fragments.back().load(path_);
    fragments.back().setLoop(false);
    fragments.back().setVolume(volume_);
    if (bRandomPan_) fragments.back().setPan(ofRandom(-1, 1));
}

//--------------------------------------------------------------
void ofxFFSound::playFragment() {
 
    if (fragments.empty()) return;
    
    cout << ofGetElapsedTimef() << endl;
        
    bool bOk = false;
    for (int i = 0; i < fragments.size(); i++) {
        if (!fragments[i].isPlaying()) {
            fragments[i].play();
            bOk = true;
            break;
        }
    }
    if (!bOk) {
        fragments.push_back(fragments[(int)ofRandom((int)fragments.size())]);
        fragments.back().play();
    }
}

//--------------------------------------------------------------
void ofxFFSound::addLong(string path_, float volume_, float length_) {
    
    longs.push_back(ofSoundPlayer());
    longs.back().load(path_);
    longs.back().setMultiPlay(true);
    longs.back().setLoop(false);
    longs.back().play();
    lengthes.push_back(length_);
    playedTimes.push_back(ofGetElapsedTimef());
}

//--------------------------------------------------------------
void ofxFFSound::update() {
    
    for (int i = 0; i < longs.size(); i++) {
        if (ofGetElapsedTimef() - playedTimes[i] > lengthes[i]) longs[i].play();
    }
}

//--------------------------------------------------------------
void ofxFFSound::multiPlay(float time_, string path_, float minInterval_, float maxInterval_, float minSpeed_, float maxSpeed_) {
    
    //update
    for (int i = 0; i < sounds.size(); i++) {
        if (!sounds[i].isPlaying()) sounds.erase(sounds.begin() + i);
    }
    
    //play
    if (time_ - lastPlayedTime > interval) {
        sounds.push_back(ofSoundPlayer());
        sounds.back().load(path_);
        sounds.back().setSpeed(ofRandom(minSpeed_, maxSpeed_));
        sounds.back().setLoop(false);
        sounds.back().play();
        
        lastPlayedTime += interval;
        interval = ofRandom(minInterval_, maxInterval_);
    }
}
