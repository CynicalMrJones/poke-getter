
# Poke-Getter
A CLI tool that will get the stats of any pokemon.

## Warning 
This is currently WIP and will be worked on continuly

## PokeAPI
This program uses [PokeApi](https://pokeapi.co/) to get a Jason (json) to parse and get relavent data

## cJSON 
This program also uses [cJSON](https://github.com/DaveGamble/cJSON). A very cool C library and the only reason I am still continuing this project. I sure as heck ain't writing no JSON parser.

## Dependencies
This program uses curl got get the data from PokeAPI. Check with your distro for installation

## Installation
Clone the repo
```
git clone https://github.com/cynicalmrjones/poke-getter
```
Run install using make
```
make install
```
The binary will be placed in /usr/bin

## Uninstall
```
make remove
```
## Usage
```
poke-get "name of pokemon"
```
