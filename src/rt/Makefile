include ../../Make_defs
############################################

MAKEFILE      = Makefile

DEST	      = .
PROGRAM       = mhd3d

OBJS          = rt.o mem.o
DEPS          = $(OBJS:.o=.d)

SUBDIRS       =

LIBRARY       = librt.a

all:            
		@list='$(SUBDIRS)' ; for subdir in $$list ; do $(MAKE) all -C   $$subdir; done
		$(MAKE) $(OBJS) $(HEADERS)
		@echo "Creating $(LIBRARY) ..."
		@$(AR) cru $(LIBRARY) $(OBJS)
		@echo -n "$(AR) cru $(LIBRARY) $(OBJS) "
		@list='$(LIB_LIBS)' ; for lib in $$list ; do\
                  files=`$(AR) t $$lib | grep -v SYMDEF`;\
                  echo -n $$files" ";\
                  $(AR) x $$lib;\
                  $(AR) ru $(LIBRARY) $$files;\
                  $(RM) -f $$files;\
                done
		@echo ""
		$(RANLIB) $(LIBRARY)
		@echo "done"

clean:
		@list='$(SUBDIRS)' ; for subdir in $$list ; do $(MAKE) clean -C   $$subdir; done
		$(RM) -f $(OBJS) $(DEPS) core $(LIBRARY)

distclean:
		@list='$(SUBDIRS)' ; for subdir in $$list ; do $(MAKE) distclean -C   $$subdir; done
		$(RM) -f $(OBJS) $(DEPS) core $(LIBRARY)

# Header dependencies are generated automatically by $(DEPFLAGS) at compile
# time (see Make_defs); no separate pass is needed. Kept as a no-op so that
# existing scripts calling "make dep" still succeed.
dep depend:
		@echo "Header dependencies are generated automatically during compilation."

update:		$(DEST)/$(LIBRARY)

.PHONY: all clean distclean dep depend update

# Pull in the generated dependency files. The leading '-' suppresses errors on
# the first build, when no .d files exist yet. This must stay below the 'all'
# target so that an included .d cannot become the default goal.
-include $(DEPS)
