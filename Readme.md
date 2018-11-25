# Plugin Demos for Unreal Engine
Demonstrates the basic usage of some of our plugins.

# Features
 * Shows how to use the **OpenCV plugin**
    * Grabs a texture from a VideoCapture camera stream and maps it to several Actors
    * Shows how to perform basic image processing (Blurring, Canny Edge Detection)
    * Shows how to wrap additional OpenCV functions for use in blueprints
 * Demonstrates Usage of the **SIMPLE plugin**
    * Receives an image publisher stream using the `ImageSubscriber` actor and uploads it to a texture (Compatible with the example_image_publisher from the SIMPLE examples)
    * Receives a transform message using the `TransformSubscriberComponent` and moves the attached actor accordingly
 * **Raymarching Plugin**
    * No demo yet. Note: Compiling this plugin needs a custom engine build. If you don't want to test it, just delete the plugin folder.

## Cloning/Downloading
This repository uses git-lfs [git-lfs](https://git-lfs.github.com/) to store the binaries of the *.uasset files. Furthermore, it uses submodules (which in turn use LFS to store *.dll and *.lib files).
The most reliable way to get everything set up cleanly is
```
    git lfs clone https://github.com/TheHugeManatee/UE4_PluginDemos.git --recursive
```

## Using
To use the example project, simply open the uproject. You will be prompted to build the C++ code for the plugins as well as the main module. 
You will probably also have to rebuild lighting data from the editor. 
If you want to play around with the C++ code, right-click on the `.uproject` file and choose "Generate Visual Studio Project Files", then open the generated solution.


# Platforms
Currently only Windows is supported as the plugins do not currently work with other platforms.

**Tested on Unreal Engine 4.21** <br/>
However, other versions might still work.
