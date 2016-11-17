/*   ____  ____  ____
 *  (  __)(  __)(  __)
 *   ) _)  ) _)  ) _)
 *  (__)  (__)  (____)
 *
 *  Copyright (c) 2016 Kirk Scheibelhut <kjs@scheibo.com>
 *
 *  This file is free software: you may copy, redistribute and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 2 of the License, or (at your
 *  option) any later version.
 *
 *  This file is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * This file incorporates work covered by the following copyright and
 * permission notice:
 *
 *     Copyright (c) 2010 Greg Lonnon (greg.lonnon@gmail.com)
 *     Copyright (c) 2008 Sean C. Rhea (srhea@srhea.net),
 *     Copyright (c) 2008 J.T Conklin (jtc@acorntoolworks.com)
 *
 *     This program is free software; you can redistribute it and/or modify it
 *     under the terms of the GNU General Public License as published by the
 *     Free Software Foundation; either version 2 of the License, or (at your
 *     option) any later version.
 *
 *     This program is distributed in the hope that it will be useful, but
 *     WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *     General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License along
 *     with this program; if not, write to the Free Software Foundation, Inc.,
 *     51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _FFEGPX_H_
#define _FFEGPX_H_

#include "activity.h"

#define FFE_DEFAULT_GPX_OPTIONS \
  { true, false }

/**
 * FFEGPXOptions
 *
 * Description:
 *  Structure used to specify options for how the GPX should be written.
 *
 * Fields:
 *  add_laps - whether or not to add laps as 'wpt' fields.
 *  lap_trksegs - whether to write a trkseg for each lap.
 */
// TODO topografix lap extensions?
typedef struct {
  bool add_laps;
  bool lap_trksegs;
} FFEGPXOptions;

/**
 * ffe_gpx_read
 *
 * Description:
 *  Read in the GPX file pointed to by `f` and return an `FFEActivity`.
 *
 * Parameters:
 *  f - The file descriptor for the GPX file to read.
 *
 * Return value:
 *  NULL - unable to read in GPX or invalid GPX file.
 *  valid pointer - a valid pointer to a newly allocated FFEActivity instance.
 *                  The caller is responsible for freeing the activity.
 */
FFEActivity *ffe_gpx_read(FILE *f);

/**
 * ffe_gpx_write_options
 *
 * Description:
 *  Write the `FFEActivity` to `f` in GPX format with optional lap data.
 *
 * Parameters:
 *  f - the file descriptor for the GPX file to write to.
 *  a - the `FFEActivity` to write.
 *  o - the options to use when writing the `FFEActivity`.
 *
 * Return value:
 *  0 - successfully wrote GPX file.
 *  1 - unable to write GPX.
 */
int ffe_gpx_write_options(FILE *f, FFEActivity *a, FFEGPXOptions *o);

/**
 * ffe_gpx_write
 *
 * Description:
 *  Write the `FFEActivity` to `f` in GPX format.
 *
 * Parameters:
 *  f - the file descriptor for the GPX file to write to.
 *  a - the `FFEActivity` to write.
 *
 * Return value:
 *  0 - successfully wrote the GPX file.
 *  1 - unable to write the GPX.
 */
static inline int ffe_gpx_write(FILE *f, Activity *a) {
  FFEGPXOptions o = FFE_DEFAULT_GPX_OPTIONS;
  return ffe_gpx_write_options(f, a, &o);
}

#endif /* _FFEGPX_H_ */

