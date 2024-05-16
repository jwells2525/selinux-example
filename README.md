# SELinux Example
#### Used to help show how SELinux works and how to create a custom SELinux Context.
#### This code has been used and tested on RHEL 8.x systems.

####
### <ins>Compiling Code</ins>
#### Uncompiled C++ Application can be found in source/myapp.cpp
#### To compile run: <em>gcc myapp.cpp -o myapp</em>

####
### <ins>Installing on System</ins>
#### Create a directory named /opt/selinux
#### <em>mkdir -p /opt/selinux</em>
#### Copy the compiled myapp, myapp.conf, and myapp.log to the directory
#### <em>cp myapp myapp.conf myapp.log /opt/selinux/.</em>


