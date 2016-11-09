/*
header file containing class defition and functions for the piano class
*/

#ifndef PIANO_H
#define PIANO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "key.h"
#include "sharp.h"
#include "stk/SineWave.h"
#include "stk/RtWvOut.h"
#include <cstdlib>

using namespace stk;

class Piano {//piano class
 public:
  Piano(SDL_Renderer *); //default constructor
  void drawKeys(SDL_Renderer *); //function draws the piano keys
  void drawSharps(SDL_Renderer *); //function draws the piano sharps
  void drawWholePiano(SDL_Renderer *); //function draws the piano
  void handleKeyPress(SDL_Renderer *, SDL_Event e); //funtion handles key press
  void playtheNote(float freq); //function plays the note
 private:
 	//creates each of the ten keys and seven sharps as objects in the piano class
	Key keyOne;
	Key keyTwo;
	Key keyThree;
	Key keyFour;
	Key keyFive;
	Key keySix;
	Key keySeven;
	Key keyEight;
	Key keyNine;
	Key keyTen;
	Sharp sharpOne;
	Sharp sharpTwo;
	Sharp sharpThree;
	Sharp sharpFour;
	Sharp sharpFive;
	Sharp sharpSix;
	Sharp sharpSeven;
};

//default constructor sets x position and y position for each of the ten keys and seven sharps
Piano::Piano(SDL_Renderer* gRenderer){
	keyOne.setVals(30,30);
	keyTwo.setVals(90,30);
	keyThree.setVals(150,30);
	keyFour.setVals(210,30);
	keyFive.setVals(270,30);
	keySix.setVals(330,30);
	keySeven.setVals(390,30);
	keyEight.setVals(450,30);
	keyNine.setVals(510,30);
	keyTen.setVals(570,30);
	sharpOne.setVals(75,30);
	sharpTwo.setVals(135,30);
	sharpThree.setVals(255,30);
	sharpFour.setVals(315,30);
	sharpFive.setVals(375,30);
	sharpSix.setVals(495,30);
	sharpSeven.setVals(555,30);
}

//function draws each of the keys with drawOneKey function from the key class
void Piano::drawKeys(SDL_Renderer* gRenderer){
	keyOne.drawOneKey(gRenderer);
	keyTwo.drawOneKey(gRenderer);
	keyThree.drawOneKey(gRenderer);
	keyFour.drawOneKey(gRenderer);
	keyFive.drawOneKey(gRenderer);
	keySix.drawOneKey(gRenderer);
	keySeven.drawOneKey(gRenderer);
	keyEight.drawOneKey(gRenderer);
	keyNine.drawOneKey(gRenderer);
	keyTen.drawOneKey(gRenderer);
}

//function draws each of the sharps with drawOneSharp function from the sharp class
void Piano::drawSharps(SDL_Renderer* gRenderer){
	sharpOne.drawOneSharp(gRenderer);
	sharpTwo.drawOneSharp(gRenderer);
	sharpThree.drawOneSharp(gRenderer);
	sharpFour.drawOneSharp(gRenderer);
	sharpFive.drawOneSharp(gRenderer);
	sharpSix.drawOneSharp(gRenderer);
	sharpSeven.drawOneSharp(gRenderer);
}

//function draws the entire piano
void Piano::drawWholePiano(SDL_Renderer* gRenderer){
  SDL_Rect screenRect = {0, 0, 700, 500}; //creates the screen rectangle
  SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255); //changes SDL drawing color
  SDL_RenderFillRect(gRenderer, &screenRect); //fills rectangle 
  SDL_Rect outlineRect = {30, 30, 600, 450}; //outlines rectangle
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 100, 100); //changes SDL drawing color
  SDL_RenderDrawRect(gRenderer, &outlineRect); //draws rectangle
  drawKeys(gRenderer); //draws the keys by using the drawKeys function above
  drawSharps(gRenderer); //draws the sharps by using the drawSharps function above
}

//function that handles key press
void Piano::handleKeyPress(SDL_Renderer* gRenderer, SDL_Event e){
  int value=0, freq = 0;

  // case statement for key presses (color key and set frequency)
  // when a key needs to be colored, it colors the key and draws the sharp
  // when a sharp needs to be colored, it draws the keys and colors the sharp
  switch(e.key.keysym.sym){
  case 'a': // Middle C (C4)
    keyOne.colorKey(gRenderer);
    drawSharps(gRenderer); 
    freq=261.63;             
    break;
  case 's': // D4
    keyTwo.colorKey(gRenderer);
    drawSharps(gRenderer);
    freq=293.66;
    break;
  case 'd': // E4
    keyThree.colorKey(gRenderer);
    drawSharps(gRenderer);
    freq=329.63;
    break;
  case 'f': // F4
    keyFour.colorKey(gRenderer);
    drawSharps(gRenderer);
    freq=349.23;
    break;
  case 'g': // G4
    keyFive.colorKey(gRenderer);
    drawSharps(gRenderer);
    freq=392.00;
    break;
  case 'h': // A4 (tuning pitch)
    keySix.colorKey(gRenderer);
    drawSharps(gRenderer);
    freq=440.00;
    break;
  case 'j': // B4
    keySeven.colorKey(gRenderer);
    drawSharps(gRenderer);
    freq=493.88;
    break;
  case 'k': // C5
    keyEight.colorKey(gRenderer);
    drawSharps(gRenderer);
    freq=523.25;
    break;
  case 'l': // D5
    keyNine.colorKey(gRenderer);
    drawSharps(gRenderer);
    freq=587.33;
    break;
  case ';': // E5
    keyTen.colorKey(gRenderer);
    drawSharps(gRenderer);
    freq=659.25;
    break;
  case 'w': // C#4/ Db4
    drawKeys(gRenderer);
    sharpOne.colorSharp(gRenderer);
    freq=277.18;
    break;
  case 'e': // D#4/ Eb4
    drawKeys(gRenderer);
    sharpTwo.colorSharp(gRenderer);
    freq=311.13;
    break;
  case 't': // F#4/ Gb4
    drawKeys(gRenderer);
    sharpThree.colorSharp(gRenderer);
    freq=369.99;
    break;
  case 'y': // G#4/ Ab4
    drawKeys(gRenderer);
    sharpFour.colorSharp(gRenderer);
    freq=415.30;
    break;
  case 'u': // A#4/ Bb4
    drawKeys(gRenderer);
    sharpFive.colorSharp(gRenderer);
    freq=466.16;
    break;
  case 'o': // C#5/ Db5
    drawKeys(gRenderer);
    sharpSix.colorSharp(gRenderer);
    freq=554.37;
    break;
  case 'p': // D#5/ Eb5
    drawKeys(gRenderer);
    sharpSeven.colorSharp(gRenderer);
    freq=622.25;
    break;
 }
  SDL_RenderPresent(gRenderer); //renders to screen
  playtheNote(freq); //plays appropriate note
  SDL_Delay(500); //delays
}

void Piano::playtheNote(float freq){
  // Sound Stuff:
  // Set the global sample rate before creating class instances.
  Stk::setSampleRate( 44100.0 );
  Stk::showWarnings( true );

  int nFrames = 100000;
  SineWave sine;
  RtWvOut *dac = 0;

  try {
    // Define and open the default realtime output device for one-channel playback
    dac = new RtWvOut( 1 );
  }
  catch ( StkError & ) {
    exit( 1 );
  }

  // play a note of frequency "freq"
  sine.setFrequency( freq );

  for ( int i=0; i<nFrames; i++ ) {
    try {
      dac->tick( sine.tick() );
     }
    catch ( StkError & ) {
      goto cleanup;
    }
  }

  cleanup:
    delete dac;
}

#endif