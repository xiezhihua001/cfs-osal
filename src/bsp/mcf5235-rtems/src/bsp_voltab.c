/*
** File   : bsp_voltab.c
** Author : Nicholas Yanchik / GSFC Code 582
**
**      This is governed by the NASA Open Source Agreement and may be used, 
**      distributed and modified only pursuant to the terms of that agreement. 
**
**      Copyright (c) 2004-2006, United States government as represented by the 
**      administrator of the National Aeronautics Space Administration.  
**      All rights reserved. 
**
**
** BSP Volume table for file systems
*/

/****************************************************************************************
                                    INCLUDE FILES
****************************************************************************************/
#include "common_types.h"
#include "osapi.h"


/* 
**  OSAL Disk volume table.  
**  Note for RTEMS, there is only one RAM_DISK device supported right now. 
**   This is due to the static configuration of the driver structures ( see bsp_start.c )
*/
OS_VolumeInfo_t OS_VolumeTable [NUM_TABLE_ENTRIES] = 
{
/* Dev Name  Phys Dev  Vol Type        Volatile?  Free?     IsMounted? Volname  MountPt BlockSz */

/*  RAM Disk */
{"/ramdev0", "/dev/rda",   RAM_DISK,        TRUE,      TRUE,     FALSE,     " ",      " ",     0        },


/* non-volatile Disk -- Auto-Mapped to an existing CF disk */
{"/eedev0",  "/",       FS_BASED,        FALSE,     FALSE,     TRUE,     "CF",      "/",     512        },

/* 
** Spare RAM disks to be used for SSR and other RAM disks 
*/
{"/ramdev1", "/ram1",      FS_BASED,        TRUE,      TRUE,     FALSE,     " ",      " ",     0        },
{"/ramdev2", "/ram2",      FS_BASED,        TRUE,      TRUE,     FALSE,     " ",      " ",     0        },
{"/ramdev3", "/ram3",      FS_BASED,        TRUE,      TRUE,     FALSE,     " ",      " ",     0        },
{"/ramdev4", "/ram4",      FS_BASED,        TRUE,      TRUE,     FALSE,     " ",      " ",     0        },
{"/ramdev5", "/ram5",      FS_BASED,        TRUE,      TRUE,     FALSE,     " ",      " ",     0        },

/* 
** Hard disk mappings 
*/
{"/ssrdev0",  "/hd:0/SSR1", FS_BASED,        TRUE,      TRUE,     FALSE,     " ",      " ",     0        },
{"/ssrdev1",  "/hd:0/SSR2", FS_BASED,        TRUE,      TRUE,     FALSE,     " ",      " ",     0        },
{"/ssrdev2",  "/hd:0/SSR3", FS_BASED,        TRUE,      TRUE,     FALSE,     " ",      " ",     0        },

{"unused",   "unused",    FS_BASED,        TRUE,      TRUE,     FALSE,     " ",      " ",     0        },
{"unused",   "unused",    FS_BASED,        TRUE,      TRUE,     FALSE,     " ",      " ",     0        },
{"unused",   "unused",    FS_BASED,        TRUE,      TRUE,     FALSE,     " ",      " ",     0        },
{"unused",   "unused",    FS_BASED,        TRUE,      TRUE,     FALSE,     " ",      " ",     0        }

};



