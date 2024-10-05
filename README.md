# How to install `nguyenpanda_cpp`

### Installing to another project

To install `nguyenpanda_cpp` library to another project, change the absolute path of variable `TO` in the following command.

The following command creates 2 directories `include` & `share`.

```shell
make install TO="/to/your/other/prefix/project"
make clear
```

For example, change `/to/your/other/prefix/project` to absolute path `nguyenpanda/test_install_library` directory.

### Installing to your local system

Using as a dynamic linking library

```shell
mkdir build
cd build
cmake ..
make install
cd ..
rm -r build
```

Read `README.md` in `test_locolly_include` directory.
