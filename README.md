# REDSource
*A project focusing on modifying Source 2013 to the newest engine branches (like Strata / Xengine, etc)*

## Instructions for building:
To build this massive project you need:
- Visual Studio 2022
- C++ MFC for Visual C++ v14.3 (143) tools.
- [Windows 8.1 SDK](https://developer.microsoft.com/en-us/windows/downloads/sdk-archive/)

Create the project using `creategameprojects.bat` or if you want to include the rest of tools use `createallprojects.bat`
Open the solution file using Visual Studio
Click "Build All"

Done!!!

# Goals for this project.
Currently, I have implementated:
- [x] PBR
- [x] Screen Spaced Ambient Occlusion (with Gaussian Blur)
- [ ] Cascade Shadow Mapping
- [ ] Deferred lighting
