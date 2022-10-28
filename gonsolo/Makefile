BLENDER = ../../build_linux/bin/blender
#BLENDER = ../../build_linux_debug/bin/blender
#BLENDER = blender
SCENE = ~/Dokumente/blender/junkshop/gonso.blend
THREADS = #-t 1
LD = LD_LIBRARY_PATH=/home/gonsolo/bin/mesa/lib/x86_64-linux-gnu
#OPTIX_ROOT_DIR=~/bin/NVIDIA-OptiX-SDK-7.5.0-linux64-x86_64

all: compile run
c: compile
compile:
	#cd ..; make debug developer ccache ninja gonsolo; cd -
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
rz: run_zink
run_zink:
	__GLX_VENDOR_LIBRARY_NAME=mesa MESA_LOADER_DRIVER_OVERRIDE=zink GALLIUM_DRIVER=zink $(BLENDER) $(THREADS) -W $(SCENE)
rzm: run_zink_mesa
run_zink_mesa:
	$(LD)  __GLX_VENDOR_LIBRARY_NAME=mesa MESA_LOADER_DRIVER_OVERRIDE=zink GALLIUM_DRIVER=zink $(BLENDER) $(THREADS) -W $(SCENE)
rl: run_llvm
run_llvm:
	LIBGL_ALWAYS_SOFTWARE=1 __GLX_VENDOR_LIBRARY_NAME=mesa VK_ICD_FILENAMES=~/bin/mesa/share/vulkan/icd.d/lvp_icd.x86_64.json $(BLENDER)
.PHONY: all c compile r run

