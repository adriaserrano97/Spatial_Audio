# SPATIAL AUDIO 
## Introduction to the problem

We all love music, don't we? 

<iframe src="https://giphy.com/embed/ku5EcFe4PNGWA" width="480" height="360" frameBorder="0" class="giphy-embed" allowFullScreen></iframe><p><a href="https://giphy.com/gifs/it-rare-pingu-ku5EcFe4PNGWA">via GIPHY</a></p>

For this reason, I'm sure you will want to add music to you game eventually. Not only that, I'm sure you will want to add sfx, dialogue, atmospheric sounds... However, as you may already know, there are a number of ways to go about that. Long past are the days when our games had only a couple channels of audio, delighting us with those ancient 8bit themes. Nowadays, we expect sound in videogames to feel real: if something in game happens on the of the screen, we expect to hear it from there. Just the same as we expect sounds to sound louder the closer they are to the camera. 

Sounds great, doesn't it? Let me show you how to do it!

## What does the industry have to offer?

Here comes the bad news: videogame industry has not taken audio to the levels of cinema (yet). One (if not the main) reason why is quite simple: the devices we use to propagate audio. Videogames are limited to only 2 sources of sound (either the left/right of the headphones or similar setups with buffers). For that reason, videogames have developed tools to emulate a realistic sound. Some cutting edge games in that regard are:
- Shadow of the tomb rider
- For Honor
- Star Wars Battlefront
- Overwatch

## What can we do?

In this tutorial, we will tackle the problem using the SDL library. With functions present in SDL (SDL_mixer extension, to be more specific) and a little imagination we will create a structure which enables us to create a semblance of realistic sound in our own games.

What are you waiting for? Download the ZIP in the release and look for the "TODO". Follow them in order and they will guide you through the process from playing a song in loop all the way to creating your own function to micro-manage sfx reproduction taking into account angle, distance from camera, channel, fade and volume.

Enjoy!

## Documentation



