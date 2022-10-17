all: compile run
c: compile
compile:
	cd ..; make developer ccache ninja gonsolo; cd -
r: run
run:
	../../build_linux/bin/blender -W ~/Dokumente/blender/junkshop/gonso.blend
rz: run_zink
run_zink:
	__GLX_VENDOR_LIBRARY_NAME=mesa MESA_LOADER_DRIVER_OVERRIDE=zink GALLIUM_DRIVER=zink ../../build_linux/bin/blender -W ~/Dokumente/blender/junkshop/gonso.blend
.PHONY: all c compile r run

