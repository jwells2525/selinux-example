#!/bin/bash

chcon -t zebra_log_t /opt/selinux/myapp.log

chcon -t zebra_conf_t /opt/selinux/myapp.conf


