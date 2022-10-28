BLENDER = ../../build_linux/bin/blender
SCENE = ~/Dokumente/blender/junkshop/gonso.blend
THREADS = #-t 1
LD = LD_LIBRARY_PATH=/home/gonsolo/bin/mesa/lib/x86_64-linux-gnu

all: compile run
c: compile
compile:
	cd ..; make developer ccache ninja gonsolo; cd -
r: run
run:
	$(BLENDER) -W $(SCENE)
b: background
background:
	$(BLENDER) --background $(SCENE) --render-output ./bla. --render-format OPEN_EXR --render-frame 1 -- --cycles-device OPTIX
	gimp ./bla.0001.exr
gdb:
	echo "run -W $(SCENE)" > gdb_execution
	gdb -x gdb_execution $(BLENDER)
	rm gdb_execution
rz: run_zink
run_zink:
	__GLX_VENDOR_LIBRARY_NAME=mesa MESA_LOADER_DRIVER_OVERRIDE=zink GALLIUM_DRIVER=zink $(BLENDER) $(THREADS) -W $(SCENE)
rzm: run_zink_mesa
run_zink_mesa:
	$(LD)  __GLX_VENDOR_LIBRARY_NAME=mesa MESA_LOADER_DRIVER_OVERRIDE=zink GALLIUM_DRIVER=zink $(BLENDER) $(THREADS) -W $(SCENE)
bench:
	vi ../../benchmark/gonsolo/config.py
	cd ../tests/performance; ./benchmark run gonsolo
.PHONY: all c compile r run

