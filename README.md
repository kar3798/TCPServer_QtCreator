Steps to commit code -

git init
git add .
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/kar3798/TCPServer_QtCreator.git
git push -u origin main

How to make windows.exe Steps -

Add the path, where windeployqt is installed in your PC, under system variables in the edit environment variables menu.
Open CMD
Open the directory where you .exe release is present (C:\Qt\Projects\TCPServer\build\Desktop_Qt_6_7_3_MinGW_64_bit-Release\release).
Run the command $ windeployqt <Program.exe> (windeployqt TCPServer.exe)
This creates a executable with all the libraries linked.
