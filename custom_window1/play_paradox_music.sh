#!/bin/bash

# define a new fcn that will ultimately call itself
function mp3 {
	# play the mp3 using SoX
	play ./paradoxzik.mp3
	# loop once the mp3 has finished playing
	mp3
}

mp3
