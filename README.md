# REDSource
*A project focusing on modifying Source 2013 to the newest engine branches (like Strata / Xengine, etc)*
(Now running on TF2 branch!!!)

## Instructions for building:
To build this massive project you need:
- Visual Studio 2022
- C++ MFC for Visual C++ v14.3 (143) tools.
- [Windows 11 SDK 10.0.22621.0](https://developer.microsoft.com/en-us/windows/downloads/windows-sdk/)
- Latest Python version for compiling VScript.

Create the project using `createallprojects.bat`. If you want to add map compile tools, create them using `createcompiletools.bat`
Open the solution file using Visual Studio
Click "Build All"

Done!!!

# Goals for this project.
Currently, I have implementated:
- [x] PBR
- [ ] Screen Spaced Ambient Occlusion (with Gaussian Blur)
- [ ] Cascade Shadow Mapping
- [ ] Deferred and volumetric lighting
- [ ] Lens Flares
- [ ] Updated anti-aliasing (from MSAA to CMAA2 or FXAA)