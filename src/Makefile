include ../Make_defs
############################################

MAKEFILE      = Makefile
SHELL         = /bin/sh

SUBDIRS	      = rt
LIBS	     += rt/librt.a

OBJS = ACCH.o \
       io_xysl.o \
       slice_write.o \
       slice_write_rebin.o \
       Iout.o \
       Qthin.o\
       tau_slice.o \
       xy_slice.o \
       yz_slice.o \
       xz_slice.o \
       corona_emission_dem_xyz.o \
       comm_split.o \
       driver.o \
       grid.o \
       init.o \
       run.o \
       physics.o \
       analysis_light.o \
       analysis_hmean_Corona.o \
       dfparser.o \
       Adjust_Valf_Max.o \
       Add_Sources_Integrate_SR.o \
       mhdres_SR.o \
       tvdlimit_SR.o \
       clean_divB.o \
       exchange.o \
       potential_sd_fftw3.o \
       potential_sd_fftw3_par.o \
       potential_sd_heffte_kernels.o \
       boundary_pdmp_1_fftw3.o \
       solver.o \
       eos_init.o \
       cons_to_prim.o

DEPS = $(OBJS:.o=.d)

all:
	@list='$(SUBDIRS)' ; for subdir in $$list ; do $(MAKE) all -C   $$subdir ; done
	$(MAKE) $(OBJS) $(HEADERS)
	@echo "Linking $(PROGRAM) ..."
	$(LD) -o $(PROGRAM) $(OBJS) $(LIBS) $(LDFLAGS)
	@echo "done"

clean:
	@list='$(SUBDIRS)' ; for subdir in $$list ; do $(MAKE) clean -C   $$subdir ; done
	rm -f $(OBJS) $(DEPS) core

distclean:
	@list='$(SUBDIRS)' ; for subdir in $$list ; do $(MAKE) distclean -C   $$subdir ; done
	rm -f $(OBJS) $(DEPS) core $(PROGRAM)

install:
	cp -v $(PROGRAM) /usr/local/bin/

# Header dependencies are generated automatically by $(DEPFLAGS) at compile
# time (see Make_defs); no separate pass is needed. Kept as a no-op so that
# existing scripts calling "make dep" still succeed.
dep depend:
	@echo "Header dependencies are generated automatically during compilation."

update:
	$(FILEPATH)/$(PROGRAM)

.PHONY: all clean distclean install dep depend update

# Pull in the generated dependency files. The leading '-' suppresses errors on
# the first build, when no .d files exist yet. This must stay below the 'all'
# target so that an included .d cannot become the default goal.
-include $(DEPS)
