![ffe](http://i.imgur.com/4e3PC3U.png) ![pre-alpha](http://img.shields.io/badge/status-pre--alpha-lightgrey.svg)
> fitness file encoding

`ffe` (pronounced *'effy'*) is a parsing library for various fitness file
encoding formats written in C99. `ffe` enables reading and converting between
several fitness file formats, as well as providing several utilities for
cleaning up potential errors in the data.

## Installation

    $ git clone https://github.com/scheibo/ffe
    $ cd ffe && make
    $ make test # optional
    $ [sudo] make install

### Dependencies

`ffe` depends on `Mini-XML` and the `git` date code. Both of these are
included in the `lib/` directory of the project and are statically linked by
default into the resulting binary. These projects are incredibly small -
bundling them with `ffe` does not add any appreciable overhead - and
unlikely to be preinstalled on your system. Developers are free to tweak the
`Makefile` to alter how dependencies are used.

## Features

 - small binary which is easy to build and incorporate into other projects
 - read and write files in .FIT, .TCX, .GPX and .CSV formats
 - currently supports both running and bicycling files
 - corrects missing or invalid data and cleans up dropouts and spikes
 - merging and splitting files
 - calculating summary data for files

## Examples

    ffe 20140218-1.gpx -o output.csv

    ffe --merge 20140218-1.gpx 20140218-2.tcx -o merged.fit

    ffe --summary merged.fit

    ffe --laps 20149218-1.gpx

TODO: add terminal gif.

## Usage

Include `ffe.h` in your project for details in order to read in fitness
files and manipulate the data. `ffe.h` should contain the most up to data
information about what calls are available.

## Options

TODO

## Future

 - support additional file types
 - support swimming / multisport

## Bugs

TODO

## Contributing

TODO

## License

`ffe` is licensed under the GPLv2 as described in the LICENSE file.
Much of the code for `ffe` was influenced by GoldenCheetah, and certain
files reflect this in their headers. `ffe` also relies on several libraries
bundled in the `lib/` directory, which have their own licenses. For reference:

 - [GoldenCheetah](https://github.com/GoldenCheetah/GoldenCheetah) - GPLv2
 - [Mini-XML](https://github.com/scheibo/mxml) - LGPLv2 w/ static linking
 - [date](https://github.com/scheibo/date) - GPLv2
