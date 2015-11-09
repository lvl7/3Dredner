# 3Dredner

Projekt realizowany na Metody Numeryczne.

### Installing VTK graphic library ( Linux )
1) Download it from ( version: 6.3.0 ):
- http://www.vtk.org/download/
2) Unzip it, for instance in /usr/local/lib
3) Go to VTK directory:
>		cd /usr/local/lib/VTK-6.3.0
4) cmake lib:
>		cmake .
5) make lib:
>		make
6) Add system variable:
- open file: ~/.profile and add line (Make sure that the path is the same that unzip VTK): 
> export VTK_DIR="/usr/local/lib/VTK-6.3.0"
