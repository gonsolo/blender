BLENDER = ../../build_linux/bin/blender
SCENE = ~/Dokumente/blender/junkshop/gonso.blend
THREADS = #-t 1
LD = LD_LIBRARY_PATH=/home/gonsolo/bin/mesa/lib/x86_64-linux-gnu
OPTIX_ROOT = ~/bin/NVIDIA-OptiX-SDK-7.5.0-linux64-x86_64
MOLD = mold --run

#all: compile run
all: compile_and_notify
c: compile_and_notify
compile_and_notify: compile notify
compile:
	CYCLES_RUNTIME_OPTIX_ROOT_DIR=$(OPTIX_ROOT) OPTIX_ROOT_DIR=$(OPTIX_ROOT) cd ..; $(MOLD) make developer ccache ninja gonsolo; cd -
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
update:
	cd ..; make update; cd -

# run install_deps.sh --with all, and the flags will be in BUILD_NOTES.txt
configure:
	cd ../../build_linux; CC=/usr/lib/ccache/cc CXX=/usr/lib/ccache/c++  cmake -G Ninja -D WITH_CODEC_SNDFILE=ON -D PYTHON_VERSION=3.10 -D BOOST_ROOT=/opt/lib/boost -D Boost_NO_SYSTEM_PATHS=ON -D Boost_NO_BOOST_CMAKE=ON -D TBB_ROOT_DIR=/opt/lib/tbb -D WITH_OPENCOLORIO=ON -D WITH_IMAGE_WEBP=ON -D WITH_OPENIMAGEIO=ON -D OPENIMAGEIO_ROOT_DIR=/opt/lib/oiio -D WITH_CYCLES_OSL=ON -D WITH_LLVM=ON -D LLVM_VERSION=12.0.0 -D OSL_ROOT_DIR=/opt/lib/osl -D LLVM_ROOT_DIR=/opt/lib/llvm -D LLVM_STATIC=ON -D WITH_OPENSUBDIV=ON -D OPENSUBDIV_ROOT_DIR=/opt/lib/osd -D WITH_OPENVDB=ON -D WITH_OPENVDB_BLOSC=ON -D OPENVDB_ROOT_DIR=/opt/lib/openvdb -D BLOSC_ROOT_DIR=/opt/lib/blosc -D WITH_OPENCOLLADA=ON -D OPENCOLLADA_ROOT_DIR=/opt/lib/opencollada -D WITH_CYCLES_EMBREE=ON -D EMBREE_ROOT_DIR=/opt/lib/embree -D WITH_OPENIMAGEDENOISE=ON -D OPENIMAGEDENOISE_ROOT_DIR=/opt/lib/oidn -D WITH_JACK=ON -D WITH_JACK_DYNLOAD=ON -D WITH_PULSEAUDIO=ON -D WITH_PULSEAUDIO_DYNLOAD=ON -D WITH_ALEMBIC=ON -D ALEMBIC_ROOT_DIR=/opt/lib/alembic -D WITH_MATERIALX=ON -D MaterialX_DIR=/opt/lib/materialx/lib/cmake/MaterialX -D WITH_USD=ON -D USD_ROOT_DIR=/opt/lib/usd -D WITH_CODEC_FFMPEG=ON -D WITH_XR_OPENXR=ON -D XR_OPENXR_SDK_ROOT_DIR=/opt/lib/xr-openxr-sdk -D openpgl_DIR=/opt/lib/openpgl/lib/cmake/openpgl-0.4.1 -D WITH_CYCLES_PATH_GUIDING=ON ../blender ; cd -

.PHONY: all c compile_and_notify compile configure notify r run

