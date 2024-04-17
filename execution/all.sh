#!/bin/sh

temp=$(mktemp -d)
echo "[INFO]: Placing old files into $temp"

echo "[INFO]: Cleaning up, readying"
mv images "$temp"
mv pngs "$temp"
mv /tmp/output.mp4 "$temp"

echo "[INFO]: Generant svgs" ####
mkdir images
g++ src/SierpinskyPyramid.cc -o sierp && ./sierp

echo "[INFO]: Passant a png" #####
mkdir pngs
make fes_imatges

echo "[INFO]: Fent video"
make video
echo "[INFO]: Finished"
