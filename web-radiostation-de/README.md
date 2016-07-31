# Web-Radiostation-De

## Introduction
A client- and serverside radiostation listener for my school (GIB Muttenz, Switzerland)

## Idea
* Overview of the played MP3 tracks
* Read track information via ID3

## Features
* Overview of the played tracks
* Search for a played track via time
* Add a new track

## Installation

### Base-Setup
* git clone https://github.com/swaechter/web-radiostation-de
* cd web-radiostation-de
* git submodule init
* git submodule update

### SQL-Setup
* Change the SQL connection data in src/functions.php
* Import the SQL dump in sql/tracks.sql

### Add first track
* Open the URL http://localhost/web-radiostation-de/src/index.php?file=media/sample.mp3 in your browser
* Change to  http://localhost/web-radiostation-de/src/index.php and see the new track

## Notes
* Note: The ID3 library can only read ID3v2.1 - not v2.2 - so take a tool and change the ID3 version!
