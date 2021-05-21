# learn-mpi

Practice with MPI and C++

## Getting Started - mac OS

Easiest to use homebrew to install dependencies:

`brew install openmpi`

Configure and generate makefile:

`ccmake .`

Build:

`make`

Run:

```
$ mpirun -n 4 hello

Hello from 0 of 4
Hello from 2 of 4
Hello from 3 of 4
Hello from 1 of 4
```

```
$ mpirun -n 4 pi 1000000

3.14186
```
