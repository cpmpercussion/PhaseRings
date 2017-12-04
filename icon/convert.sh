#!/bin/bash

SRC_FILE="1024.png"

convert "$SRC_FILE" -resize 58x58 	58.png
convert "$SRC_FILE" -resize 87x87 	87.png
convert "$SRC_FILE" -resize 80x80 	80.png
convert "$SRC_FILE" -resize 120x120 	120.png
convert "$SRC_FILE" -resize 180x180 	180.png
convert "$SRC_FILE" -resize 20x20	20.png
convert "$SRC_FILE" -resize 40x40 	40.png
convert "$SRC_FILE" -resize 60x60 	60.png


