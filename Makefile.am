bin_PROGRAMS = sdpa_binary128

if SYSTEM_MPACK
sdpa_binary128_SOURCES = sdpa_chordal.cpp sdpa_dataset.cpp sdpa_io.cpp \
sdpa_jordan.cpp sdpa_linear.cpp sdpa_main.cpp sdpa_newton.cpp sdpa_parts.cpp \
sdpa_struct.cpp sdpa_tool.cpp sdpa_chordal.h sdpa_dataset.h \
sdpa_include.h sdpa_io.h sdpa_jordan.h sdpa_linear.h sdpa_newton.h \
sdpa_parts.h sdpa_right.h sdpa_struct.h sdpa_tool.h
else
sdpa_binary128_SOURCES = sdpa_chordal.cpp sdpa_dataset.cpp sdpa_io.cpp \
sdpa_jordan.cpp sdpa_linear.cpp sdpa_main.cpp sdpa_newton.cpp sdpa_parts.cpp \
sdpa_struct.cpp sdpa_tool.cpp sdpa_chordal.h sdpa_dataset.h \
sdpa_include.h sdpa_io.h sdpa_jordan.h sdpa_linear.h sdpa_newton.h \
sdpa_parts.h sdpa_right.h sdpa_struct.h sdpa_tool.h \
mpack/Rtrsm.cpp mpack/Rsyrk.cpp\
mpack/Rtrmm.cpp mpack/Rtrsv.cpp mpack/iMlaenv.cpp\
mpack/Rlamch.cpp mpack/Rlascl.cpp mpack/Rsytrd.cpp mpack/Rsterf.cpp\
mpack/Rorgtr.cpp mpack/Rlatrd.cpp mpack/Rsyr2k.cpp mpack/Rsytd2.cpp \
mpack/Rlanst.cpp mpack/Rlae2.cpp mpack/Rlapy2.cpp mpack/Rlasrt.cpp\
mpack/Rorgql.cpp mpack/Rorgqr.cpp mpack/Rsymv.cpp mpack/Rlarfg.cpp\
mpack/Rsyr2.cpp mpack/Rlassq.cpp mpack/Rorg2l.cpp mpack/Rlarft.cpp\
mpack/Rlarfb.cpp mpack/Rorg2r.cpp mpack/Rnrm2.cpp mpack/Rlarf.cpp \
mpack/Rger.cpp mpack/Rpotrf.cpp mpack/Mxerbla.cpp mpack/Rpotf2.cpp \
mpack/Mlsame.cpp mpack/Rscal.cpp mpack/Rgemv.cpp \
mpack/Rtrmv.cpp mpack/Rsteqr.cpp mpack/Rlaset.cpp mpack/Rlaev2.cpp \
mpack/Rlasr.cpp mpack/Rlartg.cpp mpack/Rswap.cpp mpack/Rsyev.cpp\
mpack/Rlansy.cpp mpack/Mutils.cpp\
mpack/Rgemm_omp.cpp\
mpack/Raxpy_omp.cpp\
mpack/Rcopy_omp.cpp\
mpack/Rdot_omp.cpp\
mpack/Rgemm_NN_omp.cpp\
mpack/Rgemm_NT_omp.cpp\
mpack/Rgemm_TN_omp.cpp\
mpack/Rgemm_TT_omp.cpp
endif

if ENABLE_SHARED
else
sdpa_binary128_LDFLAGS = -static
endif

if SYSTEM_MPACK
sdpa_binary128_LDADD = $(pthread_lib) -L$(SPOOLES_LIBDIR) -lspooles -lquadmath $(OPENMPLIB) -L$(MPACK_LIBDIR) -lmlapack_binary128 -lmblas_binary128
sdpa_binary128_CXXFLAGS= $(pthread_cflags) -I$(SPOOLES_INCLUDEDIR) -DUseMETIS=0 $(OPENMPFLAGS) -I$(MPACK_INCLUDEDIR)
else
sdpa_binary128_LDADD = $(pthread_lib) -L$(SPOOLES_LIBDIR) -lspooles -lquadmath $(OPENMPLIB)
sdpa_binary128_CXXFLAGS= $(pthread_cflags) -I$(SPOOLES_INCLUDEDIR) -DUseMETIS=0 -I$(MPACK_INCLUDEDIR) $(OPENMPFLAGS) -I./mpack
endif

if BUILD_SPOOLES
SUBDIRS = spooles
endif
