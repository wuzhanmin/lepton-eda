/* gEDA - GPL Electronic Design Automation
 * libgeda - gEDA's Library
 * Copyright (C) 1998-2010 Ales Hvezda
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02111-1301 USA.
 */

#ifndef STRUCT_H
#define STRUCT_H

#include <glib.h>  /* Include needed to make GList work. */

/* Wrappers around a new list mechanism */
typedef struct _GedaList SELECTION;
typedef struct _GedaList GedaPageList;

/* lepton-schematic structures */
typedef struct st_conn CONN;

/* Managed text buffers */
typedef struct _TextBuffer TextBuffer;

/* Component library objects */
typedef struct _CLibSource CLibSource;
typedef struct _CLibSymbol CLibSymbol;

/* Component library search modes */
typedef enum { CLIB_EXACT=0, CLIB_GLOB } CLibSearchMode;

/* f_open behaviour flags.  See documentation for f_open_flags() in
   f_basic.c. */
typedef enum { F_OPEN_RC           = 1,
               F_OPEN_CHECK_BACKUP = 2,
               F_OPEN_RESTORE_CWD  = 4
} FOpenFlags;


/*! \brief Structure for connections between OBJECTs
 *
 * The st_conn structure contains a single connection
 * to another object.
 * The connection system in s_conn.c uses this struct
 */
struct st_conn {
  /*! \brief The "other" object connected to this one */
  OBJECT *other_object;
  /*! \brief type of connection. Always in reference to how the "other"
    object is connected to the current one */
  int type;
  /*! \brief x coord of the connection position */
  int x;
  /*! \brief y coord of the connection position */
  int y;
  /*! \brief which endpoint of the current object caused this connection */
  int whichone;
  /*! \brief which endpoint of the "other" object caused this connection */
  int other_whichone;
};

/*! \brief Type of callback function for calculating text bounds */
typedef gboolean(*RenderedBoundsFunc)(void*, const GedaObject*, gint*, gint*, gint*, gint*);

/*! \brief Type of callback function for object damage notification */
typedef int(*ChangeNotifyFunc)(void *, OBJECT *);

/*! \brief Type of callback function for querying loading of backups */
typedef gboolean(*LoadBackupQueryFunc)(void *, GString *);

/* used by the rc loading mechanisms */
typedef struct {
  int   m_val;
  const char *m_str;
} vstbl_entry;

/* Used by g_rc_parse_handler() */
typedef void (*ConfigParseErrorFunc)(GError **, void *);

#endif
