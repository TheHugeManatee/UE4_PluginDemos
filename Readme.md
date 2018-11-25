# OpenCV Plugin for Unreal Engine
Use OpenCV functionality from within Unreal Engine

# Features
 * Use `cv::VideoCapture` as an actor to get either camera or video images into a Render Target
 * `UCVUMat`: UE-Managed wrapper for `cv::UMat` to allow implementation of algorithms in Blueprints
 * Blueprint wrappers for image processing methods
 * Conversion of `UCVUMat` to Render target and vice versa

# Usage

## Cloning/Downloading
This repository uses git-lfs [git-lfs](https://git-lfs.github.com/) to store the binaries of the *.uasset files. Furthermore, it uses submodules (which in turn use LFS to store *.dll and *.lib files).
The most reliable way to get everything set up cleanly is
```
    git lfs clone https://github.com/TheHugeManatee/UE4_PluginDemos.git --recursive
```

## Using
To use the example project, simply open the uproject. You will be prompted to build the C++ code for the two plugins as well as the main module. 
You will also have to rebuild lighting data from the editor. 
If you want to play around with the C++ code, right-click on the `.uproject` file and choose "Generate Visual Studio Project Files".


# Platforms
Currently only Windows is supported as the plugins do not currently work with other platforms.

**Tested on Unreal Engine 4.19** <br/>
However, other versions might still work.
