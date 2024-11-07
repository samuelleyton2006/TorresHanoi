AUTOMAKE_OPTIONS = foreign subdir-objects
AM_CFLAGS = -Wall -Wextra -Wpedantic
AM_CPPFLAGS = -I $(top_srcdir)/include -g

bin_PROGRAMS = bin/hanoi
default = src/main.c src/jugar.c
libdata = src/stack.c
libmodel = src/hanoi.c
libview = src/animation_vara.c src/animation_hanoi.c

if RANLIB
libraries = lib/libmodel.a lib/libdata.a lib/libview.a
noinst_LIBRARIES = $(libraries)
lib_libdata_a_SOURCES = $(libdata)
lib_libmodel_a_SOURCES = $(libmodel)
lib_libview_a_SOURCES = $(libview)

bin_hanoi_SOURCES = $(default)
bin_hanoi_LDADD = $(libraries) -lncurses
else
bin_hanoi_SOURCES = $(default) $(libdata) $(libmodel) $(libview)
endif

EXTRA_DIST = include

test:
	valgrind --leak-check=full bin/hanoi
