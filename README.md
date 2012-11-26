sparser
=======

Utility for parsing in-memory data structures in c++.
This library may be useful i.e. if you have a tree that must be walked.
I use it to interpret json-config file.

Implementation is based on templates and boost::fusion (I use 1.51; sparser has not been tested on other versions).
For parsing json JsonCpp is used.

It must be compiled with -std=c++0x (g++ >4.6.3).

For how-to see main.cpp.
