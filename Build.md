# Build Instructions

## Officially Supported Targets

ONScripter-en has historically supported an absolute smorgasbord of platforms. For now though out we only officially support the following:
- Windows (MSYS2)
- Linux

## Unofficially Supported Targets
Through CMake, we're slowly bringing online support for various new targets, as well as trying to expand compatability of some of our existing targets. If there's a platform you're interested in, please file an issue or submit a PR!

> NOTE: This is just a draft, these aren't all updated or correct yet.

| OS/Platform | Arch | Toolchain | Compiling | Linking | Runs Games |
| -------- | ------- | -------  |  -------  |  -------  |  -------  |
| Windows | x86 | mingw32 | ✅ | ✅ | ✅ |
| Windows | x86_64 | mingw64 | ✅ | ✅ | ✅ |
| Windows | x86 | MSVC | ❌ | ❌ | ❌ |
| Windows | x86_64 | MSVC | ❌ | ❌ | ❌ |
| Windows | ARM | MSVC | ❌ | ❌ | ❌ |
| Windows | ARM64 | MSVC | ❌ | ❌ | ❌ |
| Linux | x86_64 | gcc | ❌ | ❌ | ❌ |
| Linux | x86 | gcc | ❌ | ❌ | ❌ |
| Linux | ARM | gcc | ❌ | ❌ | ❌ |
| Linux | ARM64 | gcc | ❌ | ❌ | ❌ |
| Linux | x86_64 | clang | ❌ | ❌ | ❌ |
| Linux | x86 | clang | ❌ | ❌ | ❌ |
| Linux | ARM | clang | ❌ | ❌ | ❌ |
| MacOS | ARM64 | clang | ❌ | ❌ | ❌ |
| MacOS | x86_64 | clang | ❌ | ❌ | ❌ |
| MacOS | PowerPC | [Retro68](https://github.com/autc04/Retro68) | ❌ | ❌ | ❌ |
| PSP | MIPS | [PSPDEV](https://pspdev.github.io/installation.html) | ✅ | ✅ | ❌ |
| Nintendo Switch | ARM64 | [devkitPro](https://github.com/devkitPro/pacman/releases) | ✅ | ✅ | ❌ |
| Wii U | PowerPC | [devkitPro](https://github.com/devkitPro/pacman/releases) | ✅ | ✅ | ❌ |
| Wii | PowerPC | [devkitPro](https://github.com/devkitPro/pacman/releases) | ✅ | ✅ | ❌ |
| Original Xbox | x86 | [nxdk](https://github.com/XboxDev/nxdk) | ✅ | ✅ | ❌ |

# Getting the code

This will look the same no matter how you build. You'll need git, as we use submodules for some of our dependencies.

```
git clone --recurse-submodules -j8 https://github.com/Galladite27/ONScripter-EN.git
```

# Official Instructions

## Windows

Install [MSYS2](https://www.msys2.org/), and choose if you'd like to build for x86 (32-bit) or x86-64 (64-bit) Windows.

### mingw64 (x86-64)

Install the toolchain and all of the required packages:
```bash
pacman -S mingw-w64-x86-64-SDL mingw-w64-x86-64-SDL_ttf mingw-w64-x86-64-SDL_mixer mingw-w64-x86-64-SDL_image mingw-w64-x86-64-bzip2 mingw-w64-x86-64-libogg mingw-w64-x86-64-libvorbis mingw-w64-x86-64-freetype mingw-w64-x86-64-smpeg mingw-w64-x86-64-iconv mingw-w64-x86-64-zlib mingw-w64-x86-64-toolchain mingw-w64-x86-64-autotools autotools make
```

And then while inside of the ONScripter-EN directory you cloned earlier:

```bash
make -f ./msys2/Makefile.Windows.MSYS2.x86-64.insani VERBOSE=true all
```

The ONScripter-EN executable will be within the top level repo directory, the tools will be within the tools subdirectory.

### mingw32 (x86)
Install the toolchain and all of the required packages:
```bash
pacman -S mingw-w64-i686-SDL mingw-w64-i686-SDL_ttf mingw-w64-i686-SDL_mixer mingw-w64-i686-SDL_image mingw-w64-i686-bzip2 mingw-w64-i686-libogg mingw-w64-i686-libvorbis mingw-w64-i686-freetype mingw-w64-i686-smpeg mingw-w64-i686-iconv mingw-w64-i686-zlib mingw-w64-i686-toolchain mingw-w64-i686-autotools autotools make
```

And then while inside of the ONScripter-EN directory you cloned earlier:
```bash
make -f ./msys2/Makefile.Windows.MSYS2.i686.insani VERBOSE=true all
```

The ONScripter-EN executable will be within the top level repo directory, the tools will be within the tools subdirectory.

## Linux
> NOTE: These instructions are for Ubuntu, so you may need to adjust the packages you install

You must have the following packages available when building ONScripter-EN:

```bash
sudo apt-get install libasound2-dev libpulse-dev libwebp-dev libxrandr-dev
```

Next you must configure libogg:

```bash
cd extlib/src/libogg-1.3.5
autoreconf -fi
autoupdate
```

Finally you can build ONScripter-EN and it's tools:

```bash
make all
```

The ONScripter-EN executable will be within the top level repo directory, the tools will be within the tools subdirectory.

# CMake Instructions

The instructions should all be relatively similar between platforms, but they're all a bit different.

## Windows

### MSYS2

#### mingw64 (x86-64)

Install the toolchain and all of the required packages:
```bash
pacman -S mingw-w64-x86-64-SDL mingw-w64-x86-64-SDL_ttf mingw-w64-x86-64-SDL_mixer mingw-w64-x86-64-SDL_image mingw-w64-x86-64-bzip2 mingw-w64-x86-64-libogg mingw-w64-x86-64-libvorbis mingw-w64-x86-64-freetype mingw-w64-x86-64-smpeg mingw-w64-x86-64-iconv mingw-w64-x86-64-zlib make
```

> NOTE: There's work going into making most of these packages optional, as the CMake is moving towards using our vendored dependencies.

And then while inside of the ONScripter-EN directory you cloned earlier:

```bash
make -f ./msys2/Makefile.Windows.MSYS2.x86-64.insani VERBOSE=true all
```

#### mingw32 (x86)
Install the toolchain and all of the required packages:
```bash
pacman -S mingw-w64-i686-SDL mingw-w64-i686-SDL_ttf mingw-w64-i686-SDL_mixer mingw-w64-i686-SDL_image mingw-w64-i686-bzip2 mingw-w64-i686-libogg mingw-w64-i686-libvorbis mingw-w64-i686-freetype mingw-w64-i686-smpeg mingw-w64-i686-iconv mingw-w64-i686-zlib mingw-w64-i686-toolchain make
```

> NOTE: There's work going into making most of these packages optional, as the CMake is moving towards using our vendored dependencies.

And then while inside of the ONScripter-EN directory you cloned earlier:
```bash
make -f ./msys2/Makefile.Windows.MSYS2.i686.insani VERBOSE=true all
```

### Windows (MSVC)

You'll need to have the various toolchains installed via Visual Studio. We test on Visual Studio 2022, where the ARM64 and ARM toolchains are a separate download.

### x86-64
### x86
### ARM64
### ARM

## Linux

## PSP

You'll need a toolchain, we test against the [instructions here](https://pspdev.github.io/installation.html), specifically for Ubuntu. 

The PSP toolchain has it's own configured CMake, so we invoke that specifically.

```bash
psp-cmake ..
make
```

This will provide the EBOOT.PBP which is the game executable. 

## Nintendo Switch

You'll need a toolchain, we test against the [instructions here](https://switchbrew.org/w/index.php?title=Setting_up_Development_Environment#Unix-like_platforms), specifically for Ubuntu. 

Once you have the devKitPro's pacman installed, if you haven't already you can install the Switch-dev toolchain:

```
sudo dkp-pacman -S Switch-dev
```

The Nintendo Switch devKitPro toolchain has it's own toolchain file for CMake, so we'll need to use that when invoking CMake.

```bash
cmake -DCMAKE_TOOLCHAIN_FILE=$DEVKITPRO/cmake/Switch.cmake ..
make
```

This will provide the EBOOT.PBP which is the game executable. 

## Wii U

You'll need a toolchain, we test against the [instructions here](https://switchbrew.org/w/index.php?title=Setting_up_Development_Environment#Unix-like_platforms), specifically for Ubuntu. 

Once you have the devKitPro's pacman installed, if you haven't already you can install the wiiu-dev toolchain:

```
sudo dkp-pacman -S wiiu-dev
```

The Wii U devKitPro toolchain has it's own toolchain file for CMake, so we'll need to use that when invoking CMake.

```bash
cmake -DCMAKE_TOOLCHAIN_FILE=$DEVKITPRO/cmake/WiiU.cmake ..
make
```

## Wii

You'll need a toolchain, we test against the [instructions here](https://switchbrew.org/w/index.php?title=Setting_up_Development_Environment#Unix-like_platforms), specifically for Ubuntu. 

Once you have the devKitPro's pacman installed, if you haven't already you can install the wii-dev toolchain:

```
sudo dkp-pacman -S wii-dev
```

The Wii devKitPro toolchain has it's own toolchain file for CMake, so we'll need to use that when invoking CMake.

```bash
cmake -DCMAKE_TOOLCHAIN_FILE=$DEVKITPRO/cmake/Wii.cmake ..
make
```

## Gamecube

You'll need a toolchain, we test against the [instructions here](https://switchbrew.org/w/index.php?title=Setting_up_Development_Environment#Unix-like_platforms), specifically for Ubuntu. 

Once you have the devKitPro's pacman installed, if you haven't already you can install the wii-dev toolchain:

```
sudo dkp-pacman -S gamecube-dev
```

The GameCube devKitPro toolchain has it's own toolchain file for CMake, so we'll need to use that when invoking CMake.

```bash
cmake -DCMAKE_TOOLCHAIN_FILE=$DEVKITPRO/cmake/GameCube.cmake ..
make
```

