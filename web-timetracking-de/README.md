# Web-Timetracking-De

## Introduction
A time tracking system for my school (GIB Muttenz)

## Features

### Basic functions
* Login/Logout
* Change password

### Normal user
* Add (own) work
* Edit (own) work
* Delete (own) work
* See your (own) work

### Head user
* Add (own) work
* Edit (own/other) work
* Delete (own/other) work
* Create a new user
* Edit an user
* Delete an user
* Create a customer
* Edit a customer
* Delete a customer
* Create a project
* Edit a project
* Delete a project
* See your (own/other) work
* See work for a customer for a specific time

## Installation
* git clone https://github.com/swaechter/web-timetracking-de
* cd web-timetracking-de
* git submodule init
* git submodule update
* Switch to your SQL control panel
    * Import the sql dump from sql/timetracking.sql
    * Create a new user. Use a SHA512 hash for the password and set the position to 2 (Equals to the head position)
* Run the site
