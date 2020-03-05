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
- Please use this
-- https://www.libsdl.org/projects/SDL_mixer/docs/index.html

- Nice informative article
-- https://www.gamasutra.com/blogs/RobBridgett/20190619/344991/The_Positive_Future_of_Spatial_Audio_for_Games.php

- Fun related videos. Don't look for answers to your bugs here, but they are interessant 
-- https://www.youtube.com/watch?v=L2Kckjq0Gcs

-- https://www.youtube.com/watch?v=M-MhP2T3Adw 

- If you feel lost, start here
-- https://lazyfoo.net/tutorials/SDL/21_sound_effects_and_music/index.php
 
- In this topic, some flaws of SDL are exposed. Useful to know, saves time
-- https://www.gamedev.net/forums/topic/188112-3d-sound-with-sdl

-- https://discourse.libsdl.org/t/surround-multichannel-sound/8639

- These are technical. Unless you're into sound design and/or sound engineering, you have nothing to see (or hear lmao) here
-- https://www.semanticscholar.org/paper/Game-Sound-Technology-and-Player-Interaction%3A-and-Grimshaw/93a979a7af230e4ca00a13dfca6f4b2abd3aa4bf

-- https://www.acousticalsurfaces.com/acoustic_IOI/101home.htm



