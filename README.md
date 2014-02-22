2DaysLeft
=========

Study project for C/C++ lecture. It will implemented a simple pong clone.


Compile guide
=============

Linux:
    * Required libraries:
        * libsfml-2.x package (go to: http://www.sfml-dev.org and download it, 
        because the linux packet manager repositories are not up to date)
        * libGLEW.so.1.7.0 ( go to http://glew.sourceforge.net/ to get the correct version
        same problem like above)
        * libxmu-dev and libxmu6 (available over packet manager)
        * libxi-dev and libxi6 (also available over packet manager)
        * libglu1-mesa and libglu1-mesa-dev ( last but not least also available 
        over packet manager)
    * After installing these libraries run make.
    * To start the application run dist/Debug/GNU-Linux-x86/pong

Windows:
    * Required libraries:
	* Download SFML and unpack it to a destination, where you want to (http://www.sfml-dev.org/download/sfml/)
	* Create a new Project in Visual Studio 2013 and open Settings
	* Configuration Properties -> C/C++ -> General (at "Additional Include Directories" choose the path to
	the unpacked SFML-File until the include-File, like: ..\SFML-2.1\include)
	* Configuration Properties -> Linker -> General (at "Additional Library Directories" choose the path to
	the unpacked SFML-File until the Lib-File, like: ..\SFML-2.1\lib)
	* Configuration Properties -> Linker -> Input (at "Additional Dependencies" write the lib-Files in the list,
	for debug: sfml-xxx-d.lib, for release: sfml-xxx.lib; xxx is for the specific library)
    * after configure your project, start debuging
    * To make a application, change the libraries and change from debug to release and start it once