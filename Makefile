compile:
	g++ -c lib/MatrixMath3D.cc execution/MatrixMath3D.o
	g++ -c lib/Tetrahedron.cc execution/Tetrahedron.o
	g++ -c lib/Vec3.cc execution/Vec3.o
	g++ -c src/Sierpinsky.cc execution/Sierpinsky.o
all:
	./execution/all.sh
fes_imatges:
	./execution/to_png.sh
video:
	ffmpeg -framerate 24 -i output/pngs/Tetrahedron%02d.png -pix_fmt yuv420p output/output.mp4
