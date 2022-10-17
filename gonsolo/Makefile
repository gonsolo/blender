BLENDER = ../../build_linux/bin/blender
#BLENDER = blender
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
rz: run_zink
run_zink:
	__GLX_VENDOR_LIBRARY_NAME=mesa MESA_LOADER_DRIVER_OVERRIDE=zink GALLIUM_DRIVER=zink $(BLENDER) $(THREADS) -W $(SCENE)
rzu: run_zink_ubuntu
run_zink_ubuntu:
	$(LD)  __GLX_VENDOR_LIBRARY_NAME=mesa MESA_LOADER_DRIVER_OVERRIDE=zink GALLIUM_DRIVER=zink $(BLENDER) $(THREADS) -W $(SCENE)
rl: run_llvm
run_llvm:
	LIBGL_ALWAYS_SOFTWARE=1 __GLX_VENDOR_LIBRARY_NAME=mesa VK_ICD_FILENAMES=~/bin/mesa/share/vulkan/icd.d/lvp_icd.x86_64.json $(BLENDER)
.PHONY: all c compile r run

