#!/bin/bash

sed -i "s/autoindex off;/autoindex on;/g" /etc/nginx/sites-available/nginx.conf

service nginx restart
