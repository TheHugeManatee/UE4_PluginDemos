# OpenCV Plugin for Unreal Engine
Use OpenCV functionality from within Unreal Engine

# Platforms
Currently only Windows is supported. This is mainly limited by my (non-existent) understanding of how building and including with external libraries works on different platforms.

**Tested on Unreal Engine 4.19** <br/>
However, other versions might still work.

# Usage
To use the example project, simply create the Visual Studio Solution by right-clicking on the `.uproject` file.
Then build the solution and start the project.

# Features
 * Use `cv::VideoCapture` as an actor to get either camera or video images into a Render Target
 * `UCVUMat`: UE-Managed wrapper for `cv::UMat` to allow implementation of algorithms in Blueprints
 * Blueprint wrappers for image processing methods
 * Conversion of `UCVUMat` to Render target and vice versa