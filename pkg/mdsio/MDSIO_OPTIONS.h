C $Header: /u/gcmpack/MITgcm/pkg/mdsio/MDSIO_OPTIONS.h,v 1.4 2004/04/06 00:25:56 dimitri Exp $
C $Name:  $

#ifndef MDSIO_OPTIONS_H
#define MDSIO_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#ifdef ALLOW_MDSIO

#include "CPP_OPTIONS.h"

C Defining SAFE_IO stops the model from overwriting its own files
#undef  SAFE_IO

#ifdef SAFE_IO
#define _NEW_STATUS 'new'
#else
#define _NEW_STATUS 'unknown'
#endif

#ifdef ALLOW_AUTODIFF_TAMC
#define ALLOW_BROKEN_MDSIO_GL
#define _OLD_STATUS 'unknown'
#else
#undef  ALLOW_BROKEN_MDSIO_GL
#define _OLD_STATUS 'old'
#endif

C o By default pkg/mdsio assumes that missing tiles are
C   present in the input and in the output files.  When
C   MISSING_TILE_IO is defined, the input and output
C   files do not include the missing tiles.  Therefore
C   the 2-D dimension of input and output files is:
C   #if defined(ALLOW_EXCH2) && !defined(MISSING_TILE_IO)
C    xy_size = exch2_domain_nxt*exch2_tnx * exch2_domain_nyt*exch2_tny
C   #else
C    xy_size = Nx * Ny = sNx*nSx*nPx * sNy*nSy*nPy
C   #endif
#undef MISSING_TILE_IO

#endif /* ALLOW_MDSIO */
#endif /* MDSIO_OPTIONS_H */
