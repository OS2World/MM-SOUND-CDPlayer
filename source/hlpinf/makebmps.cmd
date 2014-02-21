cd high
for %%A in ( *.bmp ) do catbmp ..\%%A %%A 0 0 ..\med\%%A 800 600 ..\low\%%A 640 480
cd ..\deu\high
for %%A in ( *.bmp ) do catbmp ..\%%A %%A 0 0 ..\med\%%A 800 600 ..\low\%%A 640 480
cd ..\..\eng\high
for %%A in ( *.bmp ) do catbmp ..\%%A %%A 0 0 ..\med\%%A 800 600 ..\low\%%A 640 480
cd ..\..
