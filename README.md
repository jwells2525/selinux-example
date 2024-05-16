# SELinux Example
#### Used to help show how SELinux works and how to create a custom SELinux Context.
#### This code has been used and tested on RHEL 8.x systems.

## <ins>Compiling Code</ins>
#### Uncompiled C++ Application can be found in source/myapp.cpp
#### To compile run: <em>gcc myapp.cpp -o myapp</em>

## <ins>Installing Files on System</ins>
#### Create a directory named /opt/selinux
#### &nbsp;&nbsp;&nbsp;&nbsp; <em>mkdir -p /opt/selinux</em>
#### Copy the compiled myapp, myapp.conf, and myapp.log to the directory
#### &nbsp;&nbsp;&nbsp;&nbsp; <em>cp myapp myapp.conf myapp.log /opt/selinux/.</em>

## <ins>Compiling and Enabling Custom SELinux Context</ins>
#### Compile the Custome SELinux Policy
#### &nbsp;&nbsp;&nbsp;&nbsp; <em>make -f /usr/share/selinux/strict/include/Makefile myapp.te</em>
#### Install the Newly Created Policy
#### &nbsp;&nbsp;&nbsp;&nbsp; <em>semodule -i myapp.pp</em>
#### Label the Files with the New Contexts
#### &nbsp;&nbsp;&nbsp;&nbsp; <em>semanage fcontext -a -t myapp_exec_t /opt/selinux/myapp</em>
#### &nbsp;&nbsp;&nbsp;&nbsp; <em>semanage fcontext -a -t myapp_conf_t /opt/selinux/myapp.conf</em>
#### &nbsp;&nbsp;&nbsp;&nbsp; <em>semanage fcontext -a -t myapp_log_t /ope/selinux/myapp.log</em>

## <ins>Show Errors for Wrong Context and then Fix</ins>
#### Change the context of the conf and log files to be incorrect.
#### &nbsp;&nbsp;&nbsp;&nbsp; <em>bash messup.sh</em>
#### Execute myapp
#### &nbsp;&nbsp;&nbsp;&nbsp; <em>./myapp</em>
#### Troubleshoot SELinux Errors
#### &nbsp;&nbsp;&nbsp;&nbsp; <em>sealert -l "*"</em>
#### Correct File Contexts
#### &nbsp;&nbsp;&nbsp;&nbsp; <em>chcon -t myapp_conf_t /opt/selinux/myapp.conf</em>
#### &nbsp;&nbsp;&nbsp;&nbsp; <em>chcon -t myapp_log_t /opt/selinux/myapp.log</em>
#### Check for Errors Again
#### &nbsp;&nbsp;&nbsp;&nbsp; <em>sealert -l "*"</em>
