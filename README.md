# sdpa-binary128

# how to build
I verified build on Ubuntu 20.04
```
rm -rf sdpa-dd
git clone https://github.com/nakatamaho/sdpa-binary128.git
cd sdpa-dd
aclocal ; autoconf ; automake --add-missing
autoreconf --force --install
./configure --enable-openmp=yes --enable-shared=yes
make -j4
```
