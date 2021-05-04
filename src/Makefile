#
#--------------------------------------------------------
# Compilazione
#
# Versione: 1.0.0
# Autore:   URMET TLC
#
# -------------------------------------------------------- 

LIBMQTT_PATH ?= /home/steve/cgdm/kamikaze_8.09/build_dir/arm/mosquitto-/mosquitto-1.4.9/lib


LIBJSON_PATH ?= /home/steve/cgdm/kamikaze_8.09/build_dir/arm/json-c-0.9/.libs

LIBJANSSON_PATH ?= /home/steve/cgdm/kamikaze_8.09/build_dir/arm/jansson-2.7/ipkg-install/usr/lib
INCJANSSON_PATH ?= /home/steve/cgdm/kamikaze_8.09/build_dir/arm/jansson-2.7/src

############################################################################
# General
############################################################################
APPLNAME = CGDM

CFLAGS  = -Wall
LDFLAGS = 


LGW_INC_PATH = -I/home/fabio/SDK/openwrt-sdk-19.07.7-at91-sama5_gcc-7.5.0_musl_eabi.Linux-x86_64/staging_dir/target-arm_cortex-a5+vfpv4_musl_eabi/usr/include/libloragw/
LGW_LIB_PATH ?= /home/fabio/SDK/openwrt-sdk-19.07.7-at91-sama5_gcc-7.5.0_musl_eabi.Linux-x86_64/staging_dir/target-arm_cortex-a5+vfpv4_musl_eabi/usr/lib/

FABIO_INC_PATH = ../inc/
NANO_LIBS = 

############################################################################
# Source files
############################################################################
C_BASE_FILES += \
    wait.c \
    	
C_NANO_FILE += \
    nano.c \
    wait1.c \
    $(C_BASE_FILES)

############################################################################
# list of object files 
############################################################################
O_NANO_FILE := $(C_NANO_FILE:.c=.o)

############################################################################
# default 
############################################################################
default: $(APPLNAME)-tNano

############################################################################
# Rules for building files/dependencies
############################################################################

# Rule for compiling (always first)
%.o: %.c
	$(CC) -I$(FABIO_INC_PATH) $(CFLAGS) $< -c -o $@

# Rule for building dependencies from source (always second)
%.d: %.c
	$(CC) -I$(FABIO_INC_PATH) -M $(CFLAGS) $< > $@ 


############################################################################
# Automatic source file dependencies
############################################################################

# include the dependencies (always third)
D_NANO_FILE := $(O_NANO_FILE:.o=.d)
include $(D_NANO_FILE)

############################################################################
# targets 
############################################################################
$(APPLNAME)-tNano: $(O_NANO_FILE)
	$(CC) $(O_NANO_FILE) -o $(APPLNAME)-tNano $(LDFLAGS) $(NANO_LIBS)

############################################################################
# clean 
############################################################################
clean: 
	rm -f $(APPLNAME)-tNano
	    
	rm -f *.o *.d ../*.o ../*.d

