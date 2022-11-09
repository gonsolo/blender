BLENDER = ../../build_linux/bin/blender
SCENE = ~/Dokumente/blender/junkshop/gonso.blend
THREADS = #-t 1
LD = LD_LIBRARY_PATH=/home/gonsolo/bin/mesa/lib/x86_64-linux-gnu
OPTIX_ROOT = ~/bin/NVIDIA-OptiX-SDK-7.5.0-linux64-x86_64

all: compile run
c: compile_and_notify
compile_and_notify: compile notify
compile:
	CYCLES_RUNTIME_OPTIX_ROOT_DIR=$(OPTIX_ROOT) OPTIX_ROOT_DIR=$(OPTIX_ROOT) cd ..; make developer ccache ninja gonsolo; cd -
notify:
	$(shell notify-send "Compilation finished")
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
.PHONY: all c compile_and_notify compile notify r run

