# img2raw

A simple C program that takes an image in output (as supported by stb_image library) and saves a raw version of its pixel buffer.

## build

execute build script:

```
$ ./build.sh
```

## usage

running

```
$ img2raw imagefile.ext 
```

will produce a new file named *imagefile.ext.w_h_c.raw* where *w* is the width in pixels, *h* the height, *c* the channel count.
The pixel buffer starts at the top left of the screen. Pixels are layed out one after the other in a simple RGB, or RGBA order (depending on the channel count); color channels are encoded in on byte each.  